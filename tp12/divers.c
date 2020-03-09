#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
  Calcule le nombre de ligne d'un ficheir texte
  */
int file_length(char *fic) { FILE* fp; int c=0; char flag=0;
  if ( (fp=fopen(fic,"rt"))==NULL) return 0;
  else
    while (!feof(fp))
      if (fgetc(fp)=='\n') {if (flag) c++; flag=0;}
      else flag=1;
  fclose(fp);
  return c;
}

int file_read_word(FILE* fp, char* mot) { char c;
  mot[0]='\0' ; // vide le mot precedemment saisi
  do
  { if (fscanf(fp,"%[^\n\' ,-.!?;:\"()]s",mot)==EOF) return 0;
    //puts(mot);
    fscanf(fp,"%c",&c); // teste le separateur (caractere suivant)
    	// On accepte les j', l', etc...
        // Pas de traits d'union - acceptés
    if (c=='\'') { mot[strlen(mot)+1]=0; mot[strlen(mot)]=c;}
      // On accepte les -t* comme ajouta-t-il
    else if ((c=='-' && strlen(mot)==1 && *mot=='t') || (*mot=='\r'))
            *mot=0;
         else if (*((unsigned char*)mot)==194 && ( ((unsigned char*)mot)[1]==171 || ((unsigned char*)mot)[1]==187 ))
            *mot=0;
  } while( !strlen(mot) ) ; // attente d'un veritable mot
  return 1;
}

//
// int string_is_number(char* s) {
//   char* p; int val;
//   val=strtol(s,&p,10);
//   if (*p==0) return 1;
//   else if (*p=='.') { val=strtol(p+1,&p,10);
//           if (*p==0) return 1;
//           else return 0;
//        }
//        else return 0;
// }
