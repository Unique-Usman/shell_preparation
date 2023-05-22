#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

extern char **envron;

//A program that prints the address of env (the third parameter of the main function) and environ (the global variable). 
int main(int ac, char **arg, char **enpv)
{
	char **env = environ;
	while (*env != NULL)
	{
		printf("%ss\n", *env);
		env++;
	}

	printf("From the main function\n");
	while (*enpv != NULL)
	{
		printf("%s\n", *enpv);
		enpv++;
	}
}
