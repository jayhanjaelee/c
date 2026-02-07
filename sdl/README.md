# SDL3 Example Application

SDL3를 사용하여 만든 간단한 윈도우 애플리케이션 예제입니다.

## 빌드 방법

### 필수 요구사항

- CMake 3.10 이상
- C11 표준을 지원하는 컴파일러 (clang 또는 gcc)
- SDL3 라이브러리

### SDL3 설치

#### macOS (Homebrew)
```bash
brew install sdl3
```

#### Ubuntu/Debian
```bash
sudo apt-get install libsdl3-dev
```

#### 또는 pkg-config 설치
```bash
pkg-config --cflags --libs sdl3
```

### 빌드 및 실행

1. **빌드 디렉토리 생성**
```bash
mkdir build && cd build
```

2. **CMake 설정**
```bash
cmake ..
```

3. **빌드**
```bash
make
```

4. **실행**
```bash
./main
```

## 프로젝트 구조

```
sdl/
├── CMakeLists.txt               # 최상위 CMake 설정
├── .clangd                      # clangd LSP 설정 파일
├── compile_commands.json        # 컴파일 명령 데이터베이스 (심링크)
├── src/
│   ├── CMakeLists.txt           # 소스 CMake 설정
│   └── main.c                   # 메인 소스 파일
├── build/                       # 빌드 결과물 (cmake 생성)
│   ├── main                     # 실행 파일
│   └── compile_commands.json    # 실제 컴파일 명령 데이터베이스
└── README.md                    # 이 파일
```

## 기능

- SDL3 윈도우 생성 (640x480, OpenGL 지원)
- 윈도우 이벤트 처리 (종료 이벤트)
- SDL 버전 정보 출력 (컴파일/링크 버전 비교)

## 컴파일러 옵션

- `-Wall`: 모든 경고 활성화
- C 표준: C11

## LSP (Language Server Protocol) 지원

이 프로젝트는 vim/neovim의 clangd를 위한 설정이 포함되어 있습니다.

### compile_commands.json

- **역할**: 컴파일러가 각 소스 파일을 어떻게 빌드하는지 정의한 데이터베이스
- **위치**: `build/compile_commands.json` (실제 파일), 루트에 심링크 생성
- **생성 방법**: CMakeLists.txt에 `set(CMAKE_EXPORT_COMPILE_COMMANDS ON)` 설정
- **용도**: clangd, ccls 등의 LSP 서버가 프로젝트 구조를 이해하는데 사용

### .clangd 파일

프로젝트 루트의 `.clangd` 파일은 clangd LSP 서버에 SDL3 헤더 경로를 알려줍니다:

```yaml
CompileFlags:
  Add:
    - -I/usr/local/include
    - -I/usr/local/include/SDL3
    - -std=c11
  Remove:
    - -stdlib=libc++
```

이 설정으로 vim/neovim에서:
- SDL3 함수 정의로 점프 가능 (`gd`, `Ctrl+]`)
- 자동완성 지원
- 함수 시그니처 표시
- 타입 정보 확인

## 문제 해결

### SDL3 라이브러리를 찾을 수 없는 경우

```bash
# pkg-config 경로 확인
pkg-config --cflags --libs sdl3

# CMake 빌드 시 경로 지정
cmake -DCMAKE_PREFIX_PATH=/usr/local/lib/cmake/SDL3 ..
```

### 빌드 초기화
```bash
rm -rf build
mkdir build && cd build && cmake .. && make
```

### vim/neovim에서 SDL3 함수를 찾을 수 없는 경우

1. **clangd 설치 확인**
   ```bash
   which clangd
   ```

2. **LSP 클라이언트 설정 확인**
   - coc-vim: `:CocInfo`로 clangd 활성화 확인
   - neovim LSP: `:LspInfo`로 clangd 연결 확인

3. **프로젝트 파일 확인**
   ```bash
   ls -la .clangd compile_commands.json
   ```

4. **clangd 재시작**
   - coc-vim: `:CocRestart`
   - neovim LSP: `:LspRestart`
