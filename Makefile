GCC=gcc -g
CFALGS=-Wall -Werror -Wextra -std=c11
SOURCES=*.c

all: clean s21_decimal.a

personal: *.c
	gcc *.c -o a
	./a

s21_decimal.a:
	$(GCC)  $(SOURCES) -c
	ar rcs s21_decimal.a $(OBJECTS)


clean:
	rm -rf a
