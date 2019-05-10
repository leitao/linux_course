CC=gcc
CFLAGS=-I.
OBJ = lwp.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

lwp: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
