CC = clang
CFLAGS =  -O3 -g -fomit-frame-pointer -Wall
LDFLAGS = -lm

EXEC = testheapsort testheap tempstri
all: $(EXEC)
testheapsort : testheapsort.o heap.o element.o heapsort.o
		$(CC) $(LDFLAGS) -o $@ $^
testheap : testheap.o heap.o element.o
	$(CC) $(LDFLAGS) -o $@ $^
tempstri : tempstri.o heap.o element.o heapsort.o
	$(CC) $(LDFLAGS) -o $@ $^
%.o : %.c
	$(CC) $(CFLAGS)  -c $<
clean :
	rm -f *.o $(EXEC)
