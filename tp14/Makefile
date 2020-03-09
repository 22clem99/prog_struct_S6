DIRSDL=/usr/local
CFLAGS= -c -g  -I$(DIRSDL)/include  -Wall
LDFLAGS= -lSDL2 -lSDL2_gfx -lSDL2_ttf -lSDL2_image -lSDL2_phelma -lm -lSDL_sound

EXE=test_exp1 test_exp2 test_exp3 test_exp4 test_exp5
OBJ=element.o expression.o binarytree.o expressionplot.o

all : $(EXE)

test_exp5 :$(OBJ) test_exp5.o analyse.o
	gcc -o $@ $^ $(LDFLAGS)

test_exp4 : $(OBJ) test_exp4.o analyse.o
	gcc -o $@ $^ $(LDFLAGS)

test_exp4b : $(OBJ) test_exp4b.o analyse.o
		gcc -o $@ $^ $(LDFLAGS)

test_exp3 : $(OBJ) test_exp3.o
	gcc -o $@ $^ $(LDFLAGS)

test_exp2 : $(OBJ) test_exp2.o
	gcc -o $@ $^ $(LDFLAGS)

test_exp1 : $(OBJ) test_exp1.o
	gcc -o $@ $^ $(LDFLAGS)

%.o	:%.c
	gcc  $< $(CFLAGS)

clean:
		rm -f *.o $(EXE)
