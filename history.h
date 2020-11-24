#ifndef	__HISTORY_H
#define	__HISTORY_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>





struct cmd {
char* cmde;
};

typedef struct cmd *history;


history* init_history();
int add_history(history* history, char* commandline[]);
void print_history(history* history);
void clear_history(history* history);

#endif
