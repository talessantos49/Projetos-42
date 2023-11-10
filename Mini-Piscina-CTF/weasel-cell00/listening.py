import socket

def scan_port(ip, port):
    sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    sock.settimeout(1)
    result = sock.connect_ex((ip, port))
    sock.close()
    return result

target_ip = "10.51.1.198"
common_ports = [21, 22, 23, 80, 443, 3389]  # Exemplo de algumas portas comuns, você pode adicionar outras

# for port in common_ports:
for port in range(1, 65536):
    result = scan_port(target_ip, port)
    if result == 0:
        print(f"Porta {port} está aberta")