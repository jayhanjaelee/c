export MACOSX_DEPLOYMENT_TARGET=10.9

TARGET = app

CC = clang
CFLAGS = -Wall -Iinclude
LDFLAGS = -Llib -lraylib       \
					-framework CoreVideo \
					-framework IOKit     \
					-framework Cocoa     \
					-framework GLUT      \
					-framework OpenGL

BUILD_DIR = build
OBJS_DIR = $(BUILD_DIR)/objs
SRC_DIR = src

SRCS = $(shell find $(SRC_DIR) -type f -name "*.c")
OBJS = $(patsubst $(SRC_DIR)/%.c,$(OBJS_DIR)/%.o,$(SRCS))

all: setup compdb run

compdb:
	bear -- make $(TARGET)

run:
	$(BUILD_DIR)/$(TARGET)

setup:
	@mkdir -p $(BUILD_DIR)
	@mkdir -p $(OBJS_DIR)

$(OBJS_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(TARGET): $(OBJS)
	$(CC) $(LDFLAGS) -o $(BUILD_DIR)/$(TARGET) $^

.PHONY: clean

clean:
	@rm -f $(OBJS)
	@rm -f $(BUILD_DIR)/$(TARGET)

print:
	@echo $(OBJS)
