# Компилятор и флаги
CC = gcc
CFLAGS = -Wall -Wextra -pedantic -std=c11 -Iinclude -g

# Исходники и объектники
SRC = src/relation.c
OBJ = $(SRC:.c=.o)

# Имя библиотеки
LIBDIR = lib
LIB = $(LIBDIR)/librelation.a

# Основное правило
all: $(LIB)

# Правило для библиотеки
$(LIB): $(OBJ) | $(LIBDIR)
	ar rcs $@ $^

# Создание папки для библиотеки (кроссплатформенно)
$(LIBDIR):
	mkdir -p $(LIBDIR)

# Правило компиляции .c -> .o
src/%.o: src/%.c
	$(CC) $(CFLAGS) -c -o $@ $<

# Очистка
clean:
	rm -f $(OBJ) $(LIB)

.PHONY: all clean
