GCC=gcc 
CFALGS=-Wall -Werror -Wextra -std=c11
SOURCES=*.c

all: clean s21_decimal.a

personal: clean
	$(GCC) $(CFLAGS) $(SOURCES) -o a

s21_decimal.a:
	$(GCC) $(CFLAGS) $(SOURCES) -c
	ar rcs s21_decimal.a $(OBJECTS)


clean:
	rm -rf a
