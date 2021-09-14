CC=gcc
CFLAGS= -Wall -Werror
DEPS = test_llfifo.h llfifo.h test_cbfifo.h cbfifo.h
OBJ = main.o test_llfifo.o test_cbfifo.o llfifo.o cbfifo.o 

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

hellomake: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
