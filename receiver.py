import socket

receiver_ip = '0.0.0.0'
receiver_port = 12345

sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

sock.bind((receiver_ip, receiver_port))

sock.listen(1)

print("Waiting for connections...")

while True:
    connection, client_address = sock.accept()

    try:
        print("IP Grabbed > ", client_address)

    finally:
        connection.close()
