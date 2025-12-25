CC = g++
CFLAGS := -Wall -Werror -Wextra -std=c++11 
# CFLAGS := -std=c++11 

SRC_DIR := src
BUILD_DIR := build
MY_VECTOR_DIR := MyVector
LIB_DIR := lib

VECTOR_SRS := $(wildcard $(SRC_DIR)/$(MY_VECTOR_DIR)/*.cpp)
VECTOR_OBJ := $(patsubst $(SRC_DIR)/$(MY_VECTOR_DIR)/%.cpp, $(BUILD_DIR)/$(MY_VECTOR_DIR)/%.o, $(VECTOR_SRS))

MAIN_SRC := $(wildcard $(SRC_DIR)/*.cpp)
MAIN_OBJ := $(patsubst $(SRC_DIR)/%.cpp, $(SRC_DIR)/%.о, $(SRC))

# Ищет все файлы в директории по указанному шаблону и вставляет их через пробел
# SRCS := $(wildcard $(SRC_DIR)/*.cpp)
# patsubst что_искать, на_что_поменять, где_искать
# OBJS := $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SRCS))

BUILDS := $(BUILD_DIR)/%.o

LIB_VECTOR_NAME = MyVector
STATIC_LIB := $(LIB_DIR)/lib$(LIB_VECTOR_NAME).a
SHARED_LIB := $(LIB_DIR)/lib$(LIB_VECTOR_NAME).so


TARGET := program

all: $(TARGET)

lib: $(STATIC_LIB)

$(STATIC_LIB): $(VECTOR_OBJ)
	@echo "Создание статической библиотеки вектор"
	@mkdir -p $(LIB_DIR)
	ar rcs $@ $(VECTOR_OBJ)


$(TARGET): $(OBJS)
	@echo "Создание исполняемого файла $@"
	$(CC) $(CFLAGS) $(OBJS) -o $@
	./$(TARGET)

$(BUILD_DIR)/$(MY_VECTOR_DIR)/%.o: $(SRC_DIR)/$(MY_VECTOR_DIR)/%.cpp
	@echo "Компиляция Myvector $< → $@"
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -Iinclude -c $< -o $@ 

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@echo "Компиляция $< → $@"
	@$(CC) $(CFLAGS) -c $< -o $@

rebuild: clean all

valgrind:
	valgrind --tool=memcheck --leak-check=yes  ./$(TARGET)

clean:
	@echo "Удаление $(TARGET) $(OBJS)"
	rm -rf $(TARGET) $(OBJS)

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




