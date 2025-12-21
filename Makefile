CC = g++
CFLAGS := -Wall -Werror -Wextra -std=c++11 
# CFLAGS := -std=c++11 

SRC_DIR := src
BUILD_DIR := build

# Ищет все файлы в директории по указанному шаблону и вставляет их через пробел
SRCS := $(wildcard $(SRC_DIR)/*.cpp)

# patsubst что_искать, на_что_поменять, где_искать
OBJS := $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SRCS))

BUILDS := $(BUILD_DIR)/%.o

TARGET := program

all: $(TARGET)

clean:
	@echo "Удаление $(TARGET) $(OBJS)"
	rm -rf $(TARGET) $(OBJS)


$(TARGET): $(OBJS)
	@echo "Создание исполняемого файла $@"
	$(CC) $(CFLAGS) $(OBJS) -o $@
	./$(TARGET)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@echo "Компиляция $< → $@"
	@$(CC) $(CFLAGS) -c $< -o $@

rebuild: clean all

valgrind:
	valgrind --tool=memcheck --leak-check=yes  ./$(TARGET)

.PHONY: clean
# # $@ - имя цели
# first:
# 	echo $@

# # $< - первая зависимость
# second: src/*.cpp 
# 	echo $<

# # $^ - все зависимости списком
# third: src/*.cpp 
# 	echo $^

# # $+ - Если зависимости повторяются то сохраняет последовательность и не удаляет
# four: src/*.cpp src/dataTime.cpp
# 	@echo $^
# 	@echo $+

# # 	$| — только порядковые зависимости
# five:
# 	@echo 




