DIRSDL=/usr/local
#DIRSDL=/users/prog1a/C/librairie/SDL2_Phelma

SRC= lifo.c list.c fifo.c element.c distribution.c
OBJ1=$(SRC:.c=.o)

#Pour paser en mode graphiqe, lancer make bataille MODE=GRAPHIQUE
#Lorque l'on change de mode, penser a faire un make clean avant.

ifeq ($(MODE),GRAPHIQUE)
OBJ=$(OBJ1) graph_print.o
CFLAGS= -DMODEGRAPHIQUE -c -g  -I$(DIRSDL)/include  -Wall
LDFLAGS= -L$(DIRSDL)/lib -lSDL2 -lSDL2_gfx -lSDL2_ttf -lSDL2_image -lSDL2_phelma -lm -lSDL_sound
else
OBJ=$(OBJ1)
CFLAGS= -c -g -Wall
LDFLAGS=-lm
endif


exemple_graphique:
	rm -f *.o
	make exemple MODE=GRAPHIQUE

exemple: exemple.o  $(OBJ)
	gcc -o $@ $^ $(LDFLAGS)

bataille : bataille.o $(OBJ)
	gcc -o $@ $^ $(LDFLAGS)

%.o:%.c
	gcc -g -c $(CFLAGS)  $^

clean :
	rm -f *.o bataille exemple
