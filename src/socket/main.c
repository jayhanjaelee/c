/**
 * @file main.c
 * @author Hanjae Lee (mail@hanjaelee.com)
 * @date 2026-01-26 20:27
 */

#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <inttypes.h>
#include <unistd.h>
#include <string.h>

#define PORT 8200
#define BUF_SIZE 1024

int main() {
    int fd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(PORT);
    addr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);

    if (fd != -1) {
        int is_binded = bind(fd, (struct sockaddr*)&addr, sizeof(addr));
        if (is_binded == -1) {
            fprintf(stderr, "It might address already in use.\n");
        }

        if (listen(fd, 5) == -1) {
            fprintf(stderr, "Failed to Listen.\n");
        }

        struct sockaddr *peer_address = { 0 };
        socklen_t *addr_len = NULL;
        int client_fd = 0;
        char req_buf[BUF_SIZE] = { 0 };
        ssize_t bytes_read = 0;

        char resp_buf[1024];
        snprintf(resp_buf, BUF_SIZE, "HTTP/1.1 200 OK\r\n\
                    Content-Type: text/plain; charset=UTF-8\r\n\
                    Content-Encoding: UTF-8\r\n\
                    Accept-Ranges: bytes\r\n\
                    Connection: keep-alive\r\n\r\n\
                    world");
        while ((client_fd = accept(fd, peer_address, addr_len))) {
            printf("client_fd : %d\n", client_fd);
            bytes_read = read(client_fd, req_buf, BUF_SIZE);
            printf("bytes read: %ld\n", bytes_read);
            printf("%s\n", req_buf);

            int bytes_sent = send(client_fd, resp_buf, strlen(resp_buf), 0);
            printf("number of bytes %d was sent.", bytes_sent);
            if (write(client_fd, resp_buf, BUF_SIZE) == -1) {
                printf("Can't respond to a client.");
            }

            close(client_fd);
        }
    }

    close(fd);

    return 0;
}

