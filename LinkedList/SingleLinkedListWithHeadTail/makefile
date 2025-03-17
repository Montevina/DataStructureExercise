# 定义编译器
CC = gcc

# 定义编译选项
CFLAGS = -Wall -g

# 定义目标文件
TARGET = singleLinkedListHT

# 定义源文件
SRCS = main.c singleLinkedListHT.c

# 定义目标文件
OBJS = $(SRCS:.c=.o)

# 默认目标
all: $(TARGET)

# 链接目标文件生成可执行文件
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# 编译源文件生成目标文件
%.o: %.c singleLinkedListHT.h
	$(CC) $(CFLAGS) -c $< -o $@

# 清理生成的文件
clean:
	rm -f $(OBJS) $(TARGET)
