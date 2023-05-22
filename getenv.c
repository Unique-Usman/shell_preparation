#include <stdio.h>
#include <unistd.h>
#include <string.h>

//my own implementation of getenv function, it typically get the environment varible specified by the user
extern char **environ;
char *_getenv(const char *name)
{
	char **env = environ;

	while (*env != NULL)
	{
		if (strstr(*env, name) != NULL)
		{
			char *res = strstr(*env, name);
			return res + strlen(name) + 1;
		}
		env++;
	}
	return NULL;
}
int main(int ac, char *arg[])
{
	char *res = _getenv(arg[1]);
	printf("%s\n", res);
	return 0;
}
