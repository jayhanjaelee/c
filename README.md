# C Programming Repository

A comprehensive C programming playground featuring various learning projects and exercises.

## Project Structure

```
.
├── src/                          # Main source directory
│   ├── main.c                    # Entry point
│   ├── linked_list.c             # Linked list implementation
│   ├── math.c / math.h           # Math utilities
│   ├── utils.c / utils.h         # Helper utilities
│   └── examples/                 # Example programs
├── io/                           # Input/Output examples
│   ├── main.c
│   ├── printf.c
│   ├── my_printf.c
│   └── restrict.c
├── socket/                       # Network socket programming
│   ├── server.c
│   ├── tcp_client.c
│   └── showip.c
├── syscall/                      # System call examples
│   ├── main.c
│   ├── error.c
│   └── file.c
├── passgen/                      # Password generator
│   └── passgen.c
├── curl/                         # cURL library examples
│   └── curl.c
├── ctest/                        # Unit testing with greatest.h
│   ├── test.c
│   └── greatest.h
├── playgournd/                   # Experimental code
│   ├── callback_fn.c
│   ├── io.c
│   └── assert.c
├── how_to_make_lib/              # Library creation tutorial
│   ├── mymath.c / mymath.h
│   └── main.c
├── TCP_IP_Socket_In_C/           # TCP/IP socket programming guide
├── Makefile                      # Build configuration
└── build/                        # Build artifacts
```

## Quick Start

### Build and Run
```bash
make && ./bin/main
```

### Build Specific Module
```bash
cd <module_directory> && make
```

## Dependencies

- **System Libraries**: Standard C library (libc), POSIX
- **Optional Libraries**: 
  - libcurl (for curl examples)
  - SDL/OpenGL (for graphics, if included)
  - pkg-config (for library detection)

## Modules Overview

| Module | Purpose |
|--------|---------|
| `io/` | Standard I/O operations and custom printf implementation |
| `socket/` | Network programming with TCP/IP sockets |
| `syscall/` | System call wrappers and file I/O |
| `passgen/` | Password generation utility |
| `curl/` | HTTP client examples using libcurl |
| `ctest/` | Unit testing framework examples |
| `how_to_make_lib/` | Library creation and linking tutorial |

## Compilation

The project uses a Makefile-based build system. Standard compilation:

```bash
make              # Build main executable
make clean        # Remove build artifacts
```

## Tools & Features

- **gen-clangd**: Automatic `.clangd` configuration generator for IDE support
- **Testing**: Unit tests using the greatest.h framework
- **Build System**: Makefile-based builds

## Development Notes

- All source code follows standard C conventions
- Each subdirectory may contain its own Makefile for modular compilation
- Binary outputs are stored in `./bin/` directory
- Build artifacts are stored in `./build/` directory

## License

This is a personal learning repository.

## Getting Started

1. Clone the repository
2. Navigate to desired module
3. Run `make` to build
4. Execute the compiled binary from `./bin/`

For detailed instructions on specific modules, check individual module directories.
