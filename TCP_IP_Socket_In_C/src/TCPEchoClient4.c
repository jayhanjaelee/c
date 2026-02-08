/**
 * @file TCPEchoClient4.c
 * @author Hanjae Lee (mail@hanjaelee.com)
 * @date 2026-02-08 14:20
 *
 * TCP 에코 클라이언트: 서버에 문자열을 전송하고 에코된 응답을 수신하는 프로그램
 */

/* 표준 C 라이브러리 헤더 */
#include <stdio.h>        /* 표준 입출력 함수 (printf, fputs, fputc) - /usr/include/stdio.h */
#include <stdlib.h>       /* 표준 라이브러리 (atoi 문자열->정수 변환, exit 프로그램 종료) - /usr/include/stdlib.h */
#include <string.h>       /* 문자열 조작 함수 (strlen 문자열 길이, memset 메모리 초기화) - /usr/include/string.h */
#include <unistd.h>       /* POSIX API (close 소켓 종료) - /usr/include/unistd.h */

/* 소켓 통신 관련 헤더 */
#include <sys/types.h>    /* 시스템 데이터 타입 정의 (ssize_t, in_port_t) - /usr/include/sys/types.h */
#include <sys/socket.h>   /* 소켓 API (socket, send, recv, connect) - /usr/include/sys/socket.h */
#include <netinet/in.h>   /* 인터넷 프로토콜 정의 (AF_INET, IPPROTO_TCP, sockaddr_in) - /usr/include/netinet/in.h */
#include <arpa/inet.h>    /* 인터넷 주소 변환 함수 (inet_pton, htons) - /usr/include/arpa/inet.h */

/* 프로젝트 헤더 파일 */
#include "Practical.h"    /* 프로젝트 유틸리티 (DieWithUserMessage, DieWithSystemMessage 에러 처리) */

int main(int argc, char *argv[]) {
    /* 명령줄 인자 개수 검증: 최소 3개(프로그램명 + 서버IP + 에코문자열), 최대 4개(+ 포트번호) */
    if (argc < 3 || argc > 4)
        DieWithUserMessage("Parameter(s)", "<Server Address> <Echo Word> [<Server Port>]");

    /* argv[1]: 접속할 서버의 IP 주소 문자열 */
    char *servIP = argv[1];
    /* argv[2]: 서버에 전송할 에코 문자열 */
    char *echoString = argv[2];

    /* 디버그 출력: 서버 IP와 에코 문자열 확인 */
    printf("%s %s\n", servIP, echoString);

    /* 포트번호 설정: argv[3]이 있으면 정수로 변환(atoi), 없으면 기본 포트 7(에코 서비스) 사용 */
    in_port_t servPort = (argc == 4) ? atoi(argv[3]) : 7;

    /* TCP 소켓 생성: AF_INET(IPv4), SOCK_STREAM(TCP), IPPROTO_TCP(TCP 프로토콜) */
    /* sys/socket.h의 socket() 시스템 콜 */
    int sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sock < 0)
        DieWithSystemMessage("socket() failed");

    /* 서버 주소 구조체 선언 및 초기화 */
    /* sockaddr_in 구조체: sin_family(프로토콜 종류), sin_port(포트), sin_addr(IP주소) - netinet/in.h에서 정의 */
    struct sockaddr_in servAddr;
    memset(&servAddr, 0, sizeof(servAddr));  /* 메모리를 0으로 초기화 - string.h의 memset() */

    /* sin_family: 사용할 네트워크 프로토콜 종류를 지정 */
    /* AF_INET = Address Family for Internet Protocol version 4 (IPv4 인터넷 프로토콜 계열) */
    /* netinet/in.h에서 정의되는 상수로 socket API에서 IPv4를 사용할 것을 명시 */
    servAddr.sin_family = AF_INET;            /* IPv4 프로토콜 사용 지정 */

    /* 문자열 형식의 IP 주소를 바이너리 형식으로 변환 - arpa/inet.h의 inet_pton() */
    /* 반환값: 1(성공), 0(유효하지 않은 주소), -1(시스템 에러) */
    int rtnVal = inet_pton(AF_INET, servIP, &servAddr.sin_addr.s_addr);
    if (rtnVal == 0)
        DieWithUserMessage("inet_pton() failed", "invalid address string");  /* 사용자 입력 오류 */
    else if (rtnVal < 0)
        DieWithSystemMessage("inet_pton() failed");  /* 시스템 오류 */

    /* 호스트 바이트 순서의 포트를 네트워크 바이트 순서로 변환 - arpa/inet.h의 htons() */
    servAddr.sin_port = htons(servPort);

    /* TCP 연결 수립: 지정된 서버 주소로 연결 시도 - sys/socket.h의 connect() 시스템 콜 */
    /* 반환값: 0(성공), -1(실패) */
    if (connect(sock, (struct sockaddr *)&servAddr, sizeof(servAddr)) < 0)
        DieWithSystemMessage("connect() failed");

    /* 에코 문자열의 길이 계산 - string.h의 strlen() */
    /* size_t: 부호 없는 정수로 크기 값을 나타냄 (sys/types.h) */
    size_t echoStringLen = strlen(echoString);

    /* 서버에 데이터 전송 - sys/socket.h의 send() 시스템 콜 */
    /* 반환값: 전송된 바이트 수, -1(에러) */
    ssize_t numBytes = send(sock, echoString, echoStringLen, 0);
    if (numBytes < 0)
        DieWithSystemMessage("send() failed");  /* 시스템 에러 */
    else if (numBytes != echoStringLen)
        DieWithUserMessage("send", "sent unexpected number of bytes");  /* 부분 전송 감지 */

    /* 수신한 총 바이트 수 추적 */
    unsigned int totalBytesRcvd = 0;
    /* "Received: " 출력 - stdio.h의 fputs() */
    fputs("Received: ", stdout);

    /* 에코 문자열 크기만큼 모두 수신할 때까지 반복 */
    while (totalBytesRcvd < echoStringLen) {
        char buffer[BUFSIZ];  /* BUFSIZ: 표준 버퍼 크기 (보통 1024) */

        /* 서버로부터 데이터 수신 - sys/socket.h의 recv() 시스템 콜 */
        /* 반환값: 수신한 바이트 수, 0(연결 종료), -1(에러) */
        numBytes = recv(sock, buffer, BUFSIZ - 1, 0);

        if (numBytes < 0)
            DieWithSystemMessage("recv() failed");  /* 시스템 에러 */
        else if (numBytes == 0)
            DieWithUserMessage("recv()", "connection closed prematurely");  /* 예상치 못한 연결 종료 */

        /* 누적 수신 바이트 수 증가 */
        totalBytesRcvd += numBytes;
        /* 버퍼를 문자열로 만들기 위해 null 종료자 추가 */
        buffer[numBytes] = '\0';
        /* 수신한 데이터 출력 - stdio.h의 fputs() */
        fputs(buffer, stdout);
    }

    /* 마지막에 개행 문자 출력 - stdio.h의 fputc() */
    fputc('\n', stdout);

    /* 소켓 파일 디스크립터 종료 - unistd.h의 close() */
    close(sock);
    /* 프로그램 정상 종료 - stdlib.h의 exit() */
    exit(0);
}

