/**
 * @file TCPServerUtility.c
 * @author Hanjae Lee (mail@hanjaelee.com)
 * @date 2026-02-08 18:25
 */

#include <stdio.h>
#include <sys/socket.h>
#include <unistd.h>
#include "Practical.h"
#include "TCPServerUtility.h"

void HandleTCPClient(int clntSocket) {
    char buffer[BUFSIZ]; // Buffer for echo string

    ssize_t numBytesRcvd = recv(clntSocket, buffer, BUFSIZ, 0);
    if (numBytesRcvd < 0)
        DieWithSystemMessage("recv() failed");

    while (numBytesRcvd > 0) {
        ssize_t numBytesSent = send(clntSocket, buffer, numBytesRcvd, 0);
        if (numBytesSent < 0)
            DieWithSystemMessage("send() failed");
        else if (numBytesSent != numBytesRcvd)
            DieWithUserMessage("send()", "sent unexpected number of bytes");

        numBytesRcvd = recv(clntSocket, buffer, BUFSIZ, 0);
        if (numBytesRcvd < 0)
            DieWithSystemMessage("recv() failed");
    }

    close(clntSocket);
}
