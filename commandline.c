#include <stdio.h>
#include <stdlib.h>

//my own getline function which is perform the same function as the builtin getline function
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
//this program use the _getline to simualate commandline, it keeps getting content from the input from the user and print out the input
int main(int ac, char **arg)
{
	for (int i = 0; i < ac; i++){
		printf("%s", arg[i]);
		printf("\n");
	}
	char *ptr = NULL;
	size_t len = 0;
	while (printf("$ ") && _getline(&ptr, &len, stdin)){
		printf("%s\n", ptr);
	}
}
