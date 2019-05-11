CC=gcc
CFLAGS=-I.
OBJ = loop_forever.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

loop_forever: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -fr loop_forever.o loop_forever
