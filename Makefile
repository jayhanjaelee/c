CC = gcc

# C++ 컴파일러 옵션
CXXFLAGS = -Wall -O2 -Wunused-private-field

# 링커 옵션
LDFLAGS =

# 헤더파일 경로
INCLUDE = -Iinclude/ -Isrc/

# 디렉토리 설정
SRC_DIR = ./src
OBJ_DIR = ./obj
BIN_DIR = ./bin
TARGET = main

# 모든 .c 파일을 재귀적으로 검색
SRCS = $(shell find $(SRC_DIR) -name '*.c')

# 오브젝트 파일 및 디펜던시 설정
OBJS = $(SRCS:$(SRC_DIR)/%.c=%.o)
	OBJECTS = $(addprefix $(OBJ_DIR)/, $(OBJS))
	DEPS = $(OBJECTS:.o=.d)

# 기본 타겟
all: dirs $(TARGET)

dirs:
	@mkdir -p $(BIN_DIR) $(OBJ_DIR)

# 오브젝트 파일 생성
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CXXFLAGS) $(INCLUDE) -c $< -o $@ -MD $(LDFLAGS)

# 링크하여 실행 파일 생성
$(TARGET): $(OBJECTS)
	$(CC) $(CXXFLAGS) $(OBJECTS) -o $(BIN_DIR)/$(TARGET) $(LDFLAGS)

# 정리
.PHONY: clean all
clean:
	rm -f $(OBJECTS) $(DEPS) $(BIN_DIR)/$(TARGET)

# 의존성 포함
-include $(DEPS)
