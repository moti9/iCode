import re

def is_valid_ipv4(ip):
    # Function to check if the given string is a valid IPv4 address
    pattern = re.compile(r'^\d{1,3}\.\d{1,3}\.\d{1,3}\.\d{1,3}$')
    return bool(pattern.match(ip))

def is_valid_ipv6(ip):
    # Function to check if the given string is a valid IPv6 address
    pattern = re.compile(r'^[0-9a-fA-F:]+$')
    return bool(pattern.match(ip))

def extract_last_character(ip):
    # Function to extract the last character of an IP address
    return ip[-1]

def main():
    malicious_ipv4_flag = "HQ8{"
    malicious_ipv6_flag = "HQ8{"
    malicious_both_ip = "HQ8{"


    with open("HackQuest/ip.lst", "r") as file:
        for line in file:
            ip = line.strip()

            if is_valid_ipv4(ip) and ip.startswith("99.8."):
                malicious_ipv4_flag += extract_last_character(ip)
                malicious_both_ip += extract_last_character(ip)

            elif is_valid_ipv6(ip) and ip.startswith("2610:a1:"):
                malicious_ipv6_flag += extract_last_character(ip)
                malicious_both_ip += extract_last_character(ip)

    malicious_ipv4_flag += "}"
    malicious_ipv6_flag += "}"
    malicious_both_ip += "}"

    print("Malicious IPv4 Flag:", malicious_ipv4_flag)
    print("Malicious IPv6 Flag:", malicious_ipv6_flag)
    print("Malicious Both:", malicious_both_ip)

if __name__ == "__main__":
    main()
