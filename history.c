#include <stdio.h>
#include <stdlib.h>
#include "history.h"


#define HISTORY_COUNT 5000

int size = 1000;

 int d = 0;
history* init_history(){
         history *hiArr  = malloc(size * sizeof(history));
            hiArr[0]= NULL;
             int i;
               for (i = 0; i < size; ++i) {
                   hiArr[i] = NULL;
                     }
    return hiArr;
                     }

 int add_history(history* history, char* commandline[]) {
         
    struct cmd *cur = (struct cmd *)malloc(sizeof(struct cmd));
    history[d] = cur;
    char commend[4096];
    int t=0;
    while (commandline[t] != NULL){
      strcat(commend, commandline[t]);
      strcat(commend, " ");
      t++;
    }
    cur->cmde = malloc(strlen(commend)+1);
    strcpy(cur->cmde, commend);
    commend[0]= '\0';
    d++;
    return 1;
	  
     }
 void print_history(history* History) {
      int i;
       for (i = 0; i < d; ++i) {
        printf("%d %s\n",i,History[i]->cmde);
	
            }
        fprintf( stderr, "$" );  
      }
  void clear_history(history* History) {
       int i;
     for (i = 0; i < d; ++i) {
        free(History[i]->cmde);
	free(History[i]);
         }
       free(History);
   }


