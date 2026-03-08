CC = clang
CFLAGS = -Wall -g
BUILD_DIR = build

all:

setup:
	@mkdir $(BUILD_DIR)

01_lesson: src/01_lesson/01_lesson.c
	$(CC) $(CFLAGS) -o $(BUILD_DIR)/$@ $^

02_transformer: src/02_transformer/02_transformer.c
	$(CC) $(CFLAGS) -o $(BUILD_DIR)/$@ $^

03_file-opener: src/03-files/file-opener.c
	$(CC) $(CFLAGS) -o $(BUILD_DIR)/$@ $^

03_exercise: src/03-files/exercise.c
	$(CC) $(CFLAGS) -o $(BUILD_DIR)/$@ $^
