/***************************************************
 * Programname:    SimpleShell         	 	    
 * Author:		    Nathalie Herzog
 * ID:			    09
 * Class:		    3AHIF
 * Date:		    7th of Nov
 * -------------------------------------------------
 * Description:
 * Implement a simple shell that behaves similarly
 * to the UNIX shell.
 * *************************************************
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_LENGTH 1000

char **convert_input(char *);

int main() {
    int status;
    char input[MAX_LENGTH];
    char* tmp;
    char **command;
    char* delimiter = "&";
       
    printf("Enter command: ");

    scanf("%s", input);

    //parts the string
    tmp = strtok(input, delimiter);

    while(tmp != 0) {
        command = convert_input(tmp);

        if (fork() != 0) 
        {
            //waits for the process to change (-1 = waits for any child process)
            waitpid(-1, &status, 0);
        } else 
        {
            //executes the given command
            execvp(command[0], command);
        }    

        tmp = strtok(0, delimiter);
        free(command);
    }

    free(command);
    
    return 0;
}

char **convert_input(char *input) {
    int i = 0;
    char **command = malloc(10 * sizeof(char *));
    char *parsed;
    char* delimiter = " ";

    parsed = strtok(input, delimiter);

    while (parsed != 0) {
        command[i] = parsed;
        parsed = strtok(0, delimiter);
        i++;
    }

    command[i] = 0;
    return command;
}