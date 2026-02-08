#!/bin/bash

# 사용법 출력 함수
usage() {
    echo "Usage: $0 {server|client|all} [arguments]"
    echo ""
    echo "Examples:"
    echo "  $0 server                          # Build and run server"
    echo "  $0 client 127.0.0.1 'Hello'       # Build and run client with args"
    echo "  $0 all                             # Build both server and client"
    exit 1
}

# 인자 확인
if [ $# -lt 1 ]; then
    usage
fi

TARGET=$1
shift  # 첫 번째 인자 제거, 나머지는 $@에 저장

# CMake 설정 및 빌드
cmake . -B build || exit 1

case $TARGET in
    server)
        echo "========================================"
        echo "Building Server..."
        echo "========================================"
        make -C ./build server || exit 1
        echo ""
        echo "Running Server..."
        echo "========================================"
        ./build/server "$@"
        ;;
    client)
        echo "========================================"
        echo "Building Client..."
        echo "========================================"
        make -C ./build client || exit 1
        echo ""
        echo "Running Client..."
        echo "========================================"
        ./build/client "$@"
        ;;
    all)
        echo "========================================"
        echo "Building All (Server and Client)..."
        echo "========================================"
        make -C ./build || exit 1
        echo ""
        echo "Build completed successfully!"
        echo "  - Server: ./build/server"
        echo "  - Client: ./build/client"
        ;;
    *)
        echo "Error: Unknown target '$TARGET'"
        usage
        ;;
esac
