package com.jwtauth.util;

import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.security.KeyFactory;
import java.security.KeyPair;
import java.security.KeyPairGenerator;
import java.security.NoSuchAlgorithmException;
import java.security.PrivateKey;
import java.security.PublicKey;
import java.security.spec.PKCS8EncodedKeySpec;
import java.security.spec.X509EncodedKeySpec;
import java.util.Base64;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

/**
 * RSA Key Pair Generator and Loader.
 * 
 * 📚 CONCEPT: RSA (Rivest-Shamir-Adleman) Algorithm
 * 
 * RSA is an asymmetric cryptographic algorithm with two keys:
 *  1. PRIVATE KEY: Used to SIGN JWTs (kept secret on server)
 *  2. PUBLIC KEY: Used to VERIFY JWTs (can be shared publicly)
 * 
 * Why RSA instead of HMAC?
 *  - With HMAC, the same secret key signs AND verifies tokens
 *  - If that key leaks, attackers can create fake tokens
 *  - With RSA, even if the public key leaks, only the server with private key can sign tokens
 * 
 * Key Size: 2048 bits (industry standard for security)
 * 
 * @author Moti Yadav
 */
public class RSAKeyUtil {
    
    private static final Logger log = LoggerFactory.getLogger(RSAKeyUtil.class);
    private static final int KEY_SIZE = 2048;  // 2048-bit keys
    
    /**
     * Generate a new RSA key pair.
     * 
     * Process:
     *  1. Create KeyPairGenerator for RSA algorithm
     *  2. Initialize with 2048-bit key size
     *  3. Generate private and public keys
     * 
     * Use Case: First-time setup or key rotation
     * 
     * @return KeyPair containing private and public keys
     * @throws NoSuchAlgorithmException if RSA algorithm is not available
     */
    public static KeyPair generateKeyPair() throws NoSuchAlgorithmException {
        log.info("Generating new RSA key pair with {} bits...", KEY_SIZE);
        
        KeyPairGenerator keyPairGenerator = KeyPairGenerator.getInstance("RSA");
        keyPairGenerator.initialize(KEY_SIZE);
        KeyPair keyPair = keyPairGenerator.generateKeyPair();
        
        log.info("✓ RSA key pair generated successfully!");
        return keyPair;
    }
    
    /**
     * Convert PublicKey to PEM format string.
     * 
     * PEM (Privacy-Enhanced Mail) format:
     *  -----BEGIN PUBLIC KEY-----
     *  Base64-encoded key data
     *  -----END PUBLIC KEY-----
     * 
     * @param publicKey The public key to convert
     * @return PEM-formatted string
     */
    public static String publicKeyToPEM(PublicKey publicKey) {
        byte[] encoded = publicKey.getEncoded();
        String base64 = Base64.getEncoder().encodeToString(encoded);
        
        // Format with line breaks every 64 characters (PEM standard)
        StringBuilder pem = new StringBuilder();
        pem.append("-----BEGIN PUBLIC KEY-----\n");
        
        for (int i = 0; i < base64.length(); i += 64) {
            int end = Math.min(i + 64, base64.length());
            pem.append(base64, i, end).append("\n");
        }
        
        pem.append("-----END PUBLIC KEY-----\n");
        return pem.toString();
    }
    
    /**
     * Convert PrivateKey to PEM format string.
     * 
     * PEM format for private key:
     *  -----BEGIN PRIVATE KEY-----
     *  Base64-encoded key data
     *  -----END PRIVATE KEY-----
     * 
     * ⚠️ SECURITY WARNING: Store private keys securely!
     * - Never commit to Git
     * - Use environment variables or secret managers (AWS Secrets Manager, HashiCorp Vault)
     * - Encrypt at rest
     * 
     * @param privateKey The private key to convert
     * @return PEM-formatted string
     */
    public static String privateKeyToPEM(PrivateKey privateKey) {
        byte[] encoded = privateKey.getEncoded();
        String base64 = Base64.getEncoder().encodeToString(encoded);
        
        StringBuilder pem = new StringBuilder();
        pem.append("-----BEGIN PRIVATE KEY-----\n");
        
        for (int i = 0; i < base64.length(); i += 64) {
            int end = Math.min(i + 64, base64.length());
            pem.append(base64, i, end).append("\n");
        }
        
        pem.append("-----END PRIVATE KEY-----\n");
        return pem.toString();
    }
    
    /**
     * Load PublicKey from PEM-formatted string.
     * 
     * @param pemKey PEM-formatted public key string
     * @return PublicKey object
     * @throws Exception if key parsing fails
     */
    public static PublicKey loadPublicKeyFromPEM(String pemKey) throws Exception {
        // Remove PEM headers and whitespace
        String publicKeyPEM = pemKey
                .replace("-----BEGIN PUBLIC KEY-----", "")
                .replace("-----END PUBLIC KEY-----", "")
                .replaceAll("\\s", "");
        
        // Decode Base64
        byte[] decoded = Base64.getDecoder().decode(publicKeyPEM);
        
        // Generate PublicKey from bytes
        X509EncodedKeySpec keySpec = new X509EncodedKeySpec(decoded);
        KeyFactory keyFactory = KeyFactory.getInstance("RSA");
        
        return keyFactory.generatePublic(keySpec);
    }
    
    /**
     * Load PrivateKey from PEM-formatted string.
     * 
     * @param pemKey PEM-formatted private key string
     * @return PrivateKey object
     * @throws Exception if key parsing fails
     */
    public static PrivateKey loadPrivateKeyFromPEM(String pemKey) throws Exception {
        // Remove PEM headers and whitespace
        String privateKeyPEM = pemKey
                .replace("-----BEGIN PRIVATE KEY-----", "")
                .replace("-----END PRIVATE KEY-----", "")
                .replaceAll("\\s", "");
        
        // Decode Base64
        byte[] decoded = Base64.getDecoder().decode(privateKeyPEM);
        
        // Generate PrivateKey from bytes
        PKCS8EncodedKeySpec keySpec = new PKCS8EncodedKeySpec(decoded);
        KeyFactory keyFactory = KeyFactory.getInstance("RSA");
        
        return keyFactory.generatePrivate(keySpec);
    }
    
    /**
     * Load PublicKey from file.
     * 
     * @param filePath Path to PEM file
     * @return PublicKey object
     * @throws Exception if file reading or key parsing fails
     */
    public static PublicKey loadPublicKeyFromFile(String filePath) throws Exception {
        String pemKey = Files.readString(Paths.get(filePath));
        return loadPublicKeyFromPEM(pemKey);
    }
    
    /**
     * Load PrivateKey from file.
     * 
     * @param filePath Path to PEM file
     * @return PrivateKey object
     * @throws Exception if file reading or key parsing fails
     */
    public static PrivateKey loadPrivateKeyFromFile(String filePath) throws Exception {
        String pemKey = Files.readString(Paths.get(filePath));
        return loadPrivateKeyFromPEM(pemKey);
    }
    
    /**
     * Save key pair to files.
     * 
     * @param keyPair The key pair to save
     * @param publicKeyPath Path for public key file
     * @param privateKeyPath Path for private key file
     * @throws Exception if file writing fails
     */
    public static void saveKeyPairToFiles(KeyPair keyPair, String publicKeyPath, String privateKeyPath) throws Exception {
        // Save public key
        String publicKeyPEM = publicKeyToPEM(keyPair.getPublic());
        Files.writeString(Path.of(publicKeyPath), publicKeyPEM);
        log.info("✓ Public key saved to: {}", publicKeyPath);
        
        // Save private key
        String privateKeyPEM = privateKeyToPEM(keyPair.getPrivate());
        Files.writeString(Path.of(privateKeyPath), privateKeyPEM);
        log.info("✓ Private key saved to: {}", privateKeyPath);
        log.warn("⚠️  Keep private key secure! Never commit to Git!");
    }
    
    /**
     * Main method for testing and generating keys.
     * 
     * Run this to generate your RSA key pair:
     * java com.jwtauth.util.RSAKeyUtil
     */
    public static void main(String[] args) {
        try {
            log.info("=== RSA Key Pair Generator ===\n");
            
            // Generate key pair
            KeyPair keyPair = generateKeyPair();
            
            // Print keys
            System.out.println("\n===== PUBLIC KEY =====");
            System.out.println(publicKeyToPEM(keyPair.getPublic()));
            
            System.out.println("\n===== PRIVATE KEY =====");
            System.out.println(privateKeyToPEM(keyPair.getPrivate()));
            System.out.println("\n⚠️  NEVER SHARE OR COMMIT THE PRIVATE KEY! ⚠️\n");
            
            // Optionally save to files
            // saveKeyPairToFiles(keyPair, "public_key.pem", "private_key.pem");
            
        } catch (NoSuchAlgorithmException e) {
            log.error("RSA algorithm not available: {}", e.getMessage(), e);
        }
    }
}
