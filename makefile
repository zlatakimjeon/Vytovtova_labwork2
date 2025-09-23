# Компилятор и флаги
CC = gcc
CFLAGS = -Wall -Wextra -pedantic -std=c11 -Iinclude -g

# Пути
SRC_DIR = src
INCLUDE_DIR = include
LIB_DIR = lib
TEST_DIR = test

# Файлы
SRC = $(SRC_DIR)/relation.c
OBJ = $(SRC_DIR)/relation.o

LIB = $(LIB_DIR)/librelation.a
TEST_SRC = $(TEST_DIR)/test.c $(TEST_DIR)/test_relation.c
TEST_BIN = $(TEST_DIR)/run

# Определение платформы (Windows или нет)
ifeq ($(OS),Windows_NT)
    MKDIR = if not exist $1 mkdir $1
    RM = del /Q /F
else
    MKDIR = mkdir -p $1
    RM = rm -f
endif

.PHONY: all clean

all: $(LIB) $(TEST_BIN)

# Компиляция объектного файла
$(OBJ): $(SRC)
	$(CC) $(CFLAGS) -c -o $@ $<

# Создание директории lib и архива
$(LIB): $(OBJ)
	$(call MKDIR,$(LIB_DIR))
	ar rcs $@ $^

# Создание директории test и компиляция тестов с линковкой библиотеки
$(TEST_BIN): $(TEST_SRC) $(LIB)
	$(call MKDIR,$(TEST_DIR))
	$(CC) $(CFLAGS) -o $@ $(TEST_SRC) -L$(LIB_DIR) -lrelation

clean:
ifeq ($(OS),Windows_NT)
	cmd /C "del /Q /F src\\relation.o lib\\librelation.a test\\run.exe"
else
	rm -f src/relation.o lib/librelation.a test/run
endif
