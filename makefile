CC = gcc

CFLAGS = -Iheaders

TARGET = res
OBJS = src/main.o src/task.o src/array.o src/utils.o src/task_parser.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $@ $^

main.o: src/main.c headers/main.h
	$(CC) $(CFLAGS) -c src/main.c

task.o: src/task.c headers/task.h
	$(CC) $(CFLAGS) -c src/task.c

array.o: src/array.c headers/array.h
	$(CC) $(CFLAGS) -c src/array.c

utils.o: src/utils.c headers/utils.h
	$(CC) $(CFLAGS) -c src/utils.c

task_parser.o: src/task_parser.c headers/task_parser.h
	$(CC) $(CFLAGS) -c src/task_parser.c

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean
