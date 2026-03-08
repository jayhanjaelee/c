/**
 * @file TCPEchoServer4.c
 * @author Hanjae Lee (mail@hanjaelee.com)
 * @date 2026-02-08 18:03
 */

// 표준 라이브러리 헤더파일
#include <stdio.h>      // 표준 입출력 함수 (printf, puts)
#include <stdlib.h>     // 표준 유틸리티 함수 (atoi)
#include <string.h>     // 문자열 처리 함수 (memset)

// POSIX 소켓 프로그래밍 관련 헤더파일
#include <sys/types.h>  // 기본 데이터 타입 정의
#include <sys/socket.h> // 소켓 함수 (socket, bind, listen, accept)
#include <netinet/in.h> // 인터넷 주소 구조체 및 상수 (sockaddr_in, INADDR_ANY, htons, htonl)
#include <arpa/inet.h>  // 주소 변환 함수 (inet_ntop)

// 프로젝트 커스텀 헤더파일
#include "Practical.h"          // DieWithUserMessage, DieWithSystemMessage 함수
#include "TCPServerUtility.h"   // HandleTCPClient 함수

// 대기 중인 클라이언트의 최대 개수 (listen() 함수의 backlog 값)
static const int MAXPENDING = 5;

/**
 * TCP 에코 서버의 메인 함수
 * 클라이언트의 연결을 받아들이고 핸들링하는 무한 루프 실행
 */
int main(int argc, char *argv[]) {
    // 명령행 인자 검증: 서버 포트번호가 반드시 필요
    if (argc != 2)
        DieWithUserMessage("Parameter(s)", "<Server Port>");

    // argv[1]을 정수로 변환하여 포트번호 설정 (netinet/in.h에서 정의된 in_port_t 타입)
    in_port_t servPort = atoi(argv[1]);

    // 서버 소켓 파일 디스크립터 생성
    // AF_INET: IPv4 주소 패밀리
    // SOCK_STREAM: TCP 스트림 소켓
    // IPPROTO_TCP: TCP 프로토콜 사용
    int servSock;
    if ((servSock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0)
        DieWithSystemMessage("socket() failed");

    // 서버 주소 구조체 초기화 (sockaddr_in은 netinet/in.h에서 정의)
    struct sockaddr_in servAddr;
    memset(&servAddr, 0, sizeof(servAddr));     // 구조체 메모리를 0으로 초기화
    servAddr.sin_family = AF_INET;              // IPv4 주소 패밀리 설정
    servAddr.sin_addr.s_addr = htonl(INADDR_ANY); // 모든 인터페이스에서 수신 (호스트 바이트 -> 네트워크 바이트 순서 변환)
    servAddr.sin_port = htons(servPort);        // 포트번호를 네트워크 바이트 순서로 변환

    // 소켓과 주소를 바인딩 (서버 소켓을 특정 포트에 연결)
    if (bind(servSock, (struct sockaddr*) &servAddr, sizeof(servAddr)) < 0)
        DieWithSystemMessage("bind() failed");

    // 소켓을 수신 대기 상태로 변경
    // MAXPENDING: 연결 대기 큐에 등록될 수 있는 최대 클라이언트 개수
    if (listen(servSock, MAXPENDING) < 0)
        DieWithSystemMessage("listen() failed");

    // 무한 루프: 클라이언트 연결을 계속해서 수락하고 처리
    for (;;) {
        // 클라이언트 주소 정보 저장 구조체
        struct sockaddr_in clntAddr;
        // 클라이언트 주소 구조체의 크기 (accept()에서 수정될 수 있음)
        socklen_t clntAddrLen = sizeof(clntAddr);

        // 클라이언트 연결 수락
        // 성공시 클라이언트 소켓 파일 디스크립터 반환, 실패시 음수 반환
        int clntSock = accept(servSock, (struct sockaddr *)&clntAddr, &clntAddrLen);
        if (clntSock < 0)
            DieWithSystemMessage("accept() failed");

        // 클라이언트 IP 주소를 문자열로 변환하여 저장할 버퍼
        // INET_ADDRSTRLEN: IPv4 주소 문자열의 최대 길이 (arpa/inet.h에서 정의)
        char clntName[INET_ADDRSTRLEN];

        // 클라이언트의 네트워크 바이트 순서 주소를 호스트 바이트 순서의 문자열로 변환
        // inet_ntop(): 네트워크 주소를 문자열로 변환 (arpa/inet.h에서 정의) -> numeric to printable
        if (inet_ntop(AF_INET, &clntAddr.sin_addr.s_addr, clntName, sizeof(clntName)) != NULL)
            // ntohs(): 네트워크 바이트 순서 -> 호스트 바이트 순서 포트번호 변환
            printf("Handling client %s/%d\n", clntName, ntohs(clntAddr.sin_port));
        else
            puts("Unable to get client address");

        // 클라이언트 소켓을 처리하는 함수 호출
        // TCPServerUtility.h에서 정의된 함수로, 클라이언트와의 통신을 담당
        HandleTCPClient(clntSock);
    }

    return 0;
}

