/**
 * @file main.c
 * @author Hanjae Lee (mail@hanjaelee.com)
 * @date 2026-01-26 20:27
 */

#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main() {

    // AF_INET : IPv4
    int socketFD = socket(AF_INET, SOCK_STREAM, 0);

    char *ip = "127.0.0.1";
    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_port = 2000;
    inet_pton(AF_INET, ip, &address.sin_addr.s_addr);

    int result = connect(socketFD, (struct sockaddr *)&address, sizeof(address));

}

