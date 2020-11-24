#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "history.h"
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char **argv)
{

	int i=0;
	char exitstr[] = "exit";
	int MAXLINE = 4096;
	int cmp=0;
	int comp = 0;
	int his=0;
	//char *target = "/tmp";
	char directory[1024];
	int ret;
	history* list;
	int value = 1;
	char hist[]= "history";


	list = init_history(); 

	fprintf( stderr, "$" );


	char buff[MAXLINE];
	char* cmdLine[MAXLINE];
	while (fgets(buff, MAXLINE, stdin) != NULL) {
		if (strcmp(buff, "") && strlen(buff) == 1){
			fprintf( stderr, "$" );
			continue;
		}else {

			buff[strlen(buff) - 1] = '\0'; /* replace newline with null */
			cmdLine[0]= buff;
			add_history(list,cmdLine);
			cmp = strcmp(buff,exitstr);
			his = strcmp(buff,hist);
			char cd[]="cd";

			char* token = strtok(buff," ");

			comp = strcmp (token,cd);

			//if ( strcmp (token,cd) != 0 && cmp != 0 && his != 0){

				if (cmp !=0 && comp != 0 && his != 0){

				//char *argv[2048];

				while (token != NULL) {
					printf("[%d] %s\n",i++,token);
					token = strtok (NULL, " ");
					cmdLine[value++]=token;


				}
				//char *par[]= {cmdLine[0],cmdLine[1],NULL};

				int pid = fork();

				if (pid == 0)
				{   
					if (execvp(cmdLine[0], cmdLine) == -1) {
					//if (execvp(par[0], par) == -1) {
						perror("Fork failed");
					}
					exit(EXIT_FAILURE);
				} else if (pid>0)  {
					int exitStatus;                    
					wait(&exitStatus);                 

				} else {
					perror("Fork failed");             
				}
				/*
				   int j = 0;
				   for (j=0; j<2048; j++){
				   argv[j]= NULL;
				   }*/
				i =0;
				fprintf( stderr, "$" );
			} else if (cmp == 0) {
				clear_history(list);
				return(0);
			}
			else if (his == 0){
				print_history(list );

			}else{


				char *array[10];
				int k=0;
				array[k]= buff;
				if (k>2){

					printf("cd: Too many arguments\n");
				}else{
					while(array[k] != NULL){
						array[++k] = strtok(NULL," ");
					}

					ret = chdir(array[1]);
					if (ret != 0){  

						printf("error: %s does not exist\n", array[1]);
						fprintf( stderr, "$" );

					}else{

						if(chdir(cmdLine[1]) == 0) {
							getcwd(directory, sizeof(directory));
							printf("%s\n", array[1]);
							fprintf( stderr, "$" );


						}

					}
                                        printf("%s\n", array[1]);
					fprintf( stderr, "$");
				}
			}

			}
		}  

		clear_history(list);

		return (0);
	}









