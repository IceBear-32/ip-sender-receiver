#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winsock2.h>

int main(int argc, char *argv[]) {
    char receiver[13];
    strcpy(receiver, "[YOUR IP]");
    int receiver_port = 12345;

    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        perror("WSAStartup");
        return 1;
    }

    SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == INVALID_SOCKET) {
        perror("socket");
        return 1;
    }

    struct sockaddr_in receiver_addr;
    receiver_addr.sin_family = AF_INET;
    receiver_addr.sin_port = htons(receiver_port);
    if (inet_pton(AF_INET, receiver, &receiver_addr.sin_addr) <= 0) {
        perror("inet_pton");
        return 1;
    }

    if (connect(sock, (struct sockaddr *)&receiver_addr, sizeof(receiver_addr)) == SOCKET_ERROR) {
        perror("connect");
        return 1;
    }
    else {
        printf("Connection successful!\n");
        system("pause");
    }
    closesocket(sock);
    WSACleanup();

    return 0;
}
