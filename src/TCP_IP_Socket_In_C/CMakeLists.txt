cmake_minimum_required(VERSION 3.8)
project(TCP_IP_Socket)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# 공용 소스 파일
set(COMMON_SOURCES
  "${CMAKE_SOURCE_DIR}/src/DieWithMessage.c"
  "${CMAKE_SOURCE_DIR}/src/TCPServerUtility.c"
)

# TCP Echo Server 빌드
add_executable(server
  "${CMAKE_SOURCE_DIR}/src/TCPEchoServer4.c"
  ${COMMON_SOURCES}
)
target_include_directories(server PUBLIC "${CMAKE_SOURCE_DIR}/include")

# TCP Echo Client 빌드
add_executable(client
  "${CMAKE_SOURCE_DIR}/src/TCPEchoClient4.c"
  ${COMMON_SOURCES}
)
target_include_directories(client PUBLIC "${CMAKE_SOURCE_DIR}/include")
