CFLAGS= -c -Wall -g
all : histo_text sequentiel testhashtable

histo_text: histo_text.o tadhash.o list.o divers.o element.o
	gcc  -o $@ $^

testhashtable: testhashtable.o tadhash.o list.o divers.o element.o
			gcc  -o $@ $^

sequentiel: sequentiel.o list.o divers.o element.o
		gcc  -o $@ $^

%.o: %.c
	gcc $(CFLAGS) $<

clean:
	rm -f *.o histo_text sequentiel testhashtable
