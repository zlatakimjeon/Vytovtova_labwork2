# Компилятор и флаги
CC = gcc
CFLAGS = -Wall -Wextra -pedantic -std=c11 -Iinclude -g

# Определяем расширение для Windows
EXE =
ifeq ($(OS),Windows_NT)
    EXE = .exe
endif

# Исходники и объектники для библиотеки
SRC = src/relation.c
OBJ = $(SRC:.c=.o)

# Папка и имя библиотеки
LIBDIR = lib
LIB = $(LIBDIR)/librelation.a

# Тестовый бинарник
TEST = test/run$(EXE)
TESTSRC = test/test.c test/test_relation.c

# Цель по умолчанию
all: $(LIB) $(TEST)

# Создание статической библиотеки
$(LIB): $(OBJ) | $(LIBDIR)
	ar rcs $@ $^

# Создание директории для библиотеки
$(LIBDIR):
	mkdir -p $(LIBDIR)

# Компиляция .c -> .o
src/%.o: src/%.c
	$(CC) $(CFLAGS) -c -o $@ $<

# Сборка тестов
$(TEST): $(TESTSRC) $(LIB)
	$(CC) $(CFLAGS) -o $@ $(TESTSRC) $(LIB)

# Запуск тестов
test: $(TEST)
	./$(TEST)

# Очистка
clean:
	rm -f $(OBJ) $(LIB) $(TEST)

.PHONY: all clean test
