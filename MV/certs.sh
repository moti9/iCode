mkdir -p certs
cd certs

# Private keys for CAs
openssl genrsa -out server-ca.key 2048
openssl genrsa -out client-ca.key 2048

# Generate CA certificates
openssl req -new -x509 -nodes -days 3650 -key server-ca.key -out server-ca.crt
openssl req -new -x509 -nodes -days 3650 -key client-ca.key -out client-ca.crt

# Generate a certificate signing request (CSR) for the server
openssl req -newkey rsa:2048 -nodes -keyout server.key -out server.req
openssl req -newkey rsa:2048 -nodes -keyout client.key -out client.req

# Have the CA sign the certificate requests and output the certificates.
openssl x509 -req -in server.req -days 365 -CA server-ca.crt -CAkey server-ca.key -set_serial 01 -out server.crt -extFile localhost.ext
openssl x509 -req -in client.req -days 365 -CA client-ca.crt -CAkey client-ca.key -set_serial 01 -out client.crt