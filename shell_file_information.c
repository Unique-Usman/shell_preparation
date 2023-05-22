#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

//getline function
int _getline(char **ptr, size_t *len, FILE *stream)
{
	int buffer = 16;
	int pos = 0;
	int c; //character to be gotten from the outspace;
	*ptr = malloc(sizeof(char) * buffer);
	if (*ptr == NULL)
		return (-1);
	while ((c = fgetc(stream)) != EOF && c != '\n'){
		if (pos >= buffer)
		{
			buffer = 2 * buffer;
			*ptr = realloc(*ptr, buffer);
			if (*ptr == NULL)
				return (-1);
			(*ptr)[pos++] = c;
		}else{
			(*ptr)[pos++] = c;
		}
	}
	(*ptr)[pos] = '\0';
	*len = pos;
	return (1);
}

//a minishell that the get filename from the user and execute the file
int main(int ac, char **arg)
{
	char *ptr = NULL;
	size_t len = 0;
	int status;
	while (printf("cisfun$ ") && _getline(&ptr, &len, stdin) == 1){
		char *argv[] = {ptr, NULL};
		char *env[] = {NULL};
		pid_t child;
		child = fork();
		if (child == -1){
			perror("fork");
			return -1;
		}

		if (child == 0){
			if (execve(argv[0], argv, env) == -1)
			{
				perror("execve");
				return -1;
			}
		}
		else{
			wait(&status);
		}
	}
}
