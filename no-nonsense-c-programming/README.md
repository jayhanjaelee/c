# no-nonsense-c-programming

## How to compile automatically

Requirements

- entr (watch file whenever it changed.)

```sh
brew install entr
```

다음 shell 명령어는 src 하위 디렉토리 변경점이 생기면 c 프로그램 빌드 후 실행한다.

```sh
find . src/** | entr -s 'make && build/a.out'
```
