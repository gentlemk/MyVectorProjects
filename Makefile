CC = g++
CFLAGS := -Wall -Werror -Wextra -std=c++11 
# CFLAGS := -std=c++11 

SRC_DIR := src
BUILD_DIR := build
VECTOR_DIR := vector
LIB_DIR := lib
INCLUDE_DIR := include

VECTOR_SRCS := $(wildcard $(SRC_DIR)/$(VECTOR_DIR)/*.сpp)
VECTOR_OBJS := $(patsubst $(SRC_DIR)/$(VECTOR_DIR)/%.сpp, $(BUILD_DIR)/$(VECTOR_DIR)/%.o, $(VECTOR_SRCS))

MAIN_SRCS := $(wildcard $(SRC_DIR)/*.cpp)
MAIN_OBJS := $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(MAIN_SRCS))

# Ищет все файлы в директории по указанному шаблону и вставляет их через пробел
# SRCS := $(wildcard $(SRC_DIR)/*.cpp)
# patsubst что_искать, на_что_поменять, где_искать
# OBJS := $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SRCS))

LIB_VECTOR_NAME = vector
STATIC_LIB := $(LIB_DIR)/lib$(LIB_VECTOR_NAME).a
SHARED_LIB := $(LIB_DIR)/lib$(LIB_VECTOR_NAME).so

TARGET := program


all: $(TARGET)

lib: $(STATIC_LIB)

$(STATIC_LIB): $(VECTOR_OBJS)
	@echo "Создание статической библиотеки вектор"
	@mkdir -p $(dir $@)
	ar rcs $@ $(VECTOR_OBJS)

$(TARGET): $(STATIC_LIB) $(MAIN_OBJS)
	@echo "Создание исполняемого файла $@"
	$(CC) $(CFLAGS) $(MAIN_OBJS) $(STATIC_LIB) -o $@
	./$(TARGET)

$(BUILD_DIR)/$(VECTOR_DIR)/%.o: $(SRC_DIR)/$(VECTOR_DIR)/%.tpp
	@echo "Компиляция vector $< → $@"
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c $< -o $@ 

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@echo "Компиляция $< → $@"
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

style:
	@echo "┏=========================================┓"
	@echo "┃  Formatting your code for Google Style  ┃"
	@echo "┗=========================================┛"
	@find . \( -name '*.h' -o -name '*.cpp' \) -print0 | xargs -0 clang-format -i -style=Google

rebuild: clean all

valgrind:
	valgrind --tool=memcheck --leak-check=yes  ./$(TARGET)

clean:
	@echo "Удаление $(TARGET) $(VECTOR_OBJS) $(STATIC_LIB) $(MAIN_OBJS)"
	rm -rf $(TARGET) $(VECTOR_OBJS) $(BUILD_DIR)/$(VECTOR_DIR) $(STATIC_LIB) $(MAIN_OBJS)

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




