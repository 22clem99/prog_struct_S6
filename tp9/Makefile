CFLAGS=-c -g
LDFLAGS=

all: test_list3 test_list2 test_list1 test_list0

test_list3: test_list3.o list.o element.o
	clang  -o $@ $^ $(LDFLAGS)

test_list2: test_list2.o list.o element.o
	clang  -o $@ $^ $(LDFLAGS)

test_list1: test_list1.o list.o element.o
	clang  -o $@ $^ $(LDFLAGS)

test_list0: test_list0.o list.o element.o
	clang  -o $@ $^ $(LDFLAGS)

%.o: %.c
	clang $(CFLAGS) $<

clean :
	rm *.o test_list2 test_list1 test_list0 test_list3
