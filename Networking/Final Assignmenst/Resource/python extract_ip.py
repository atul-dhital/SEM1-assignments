import xml.etree.ElementTree as ET

def extract_ip_addresses(packet_tracer_file):
    tree = ET.parse(packet_tracer_file)
    root = tree.getroot()

    ip_addresses = set()

    # Assuming IP addresses are stored in the 'IPAddress' elements
    for ip_element in root.iter('IPAddress'):
        ip_address = ip_element.text
        ip_addresses.add(ip_address)

    return list(ip_addresses)

# Example usage
file_path = 'E:\\Assignments\\SEM1-assignments\\Networking\\Final Assignmenst\\Resource\\res.pkt'

ip_addresses = extract_ip_addresses(file_path = 'E:\\Assignments\\SEM1-assignments\\Networking\\Final Assignmenst\\Resource\\res.pkt'
)

print("Extracted IP Addresses:")
for ip in ip_addresses:
    print(ip)
