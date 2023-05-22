#include <stdio.h>
#include <sys/stat.h>

//a program for getting information about /bin/ls file
int main()
{
	const char * filepath = "/bin/ls";
	struct stat file;

	if (stat(filepath, &file) == -1)
	{
		perror("stat");
		return -1;
	}

	printf("Last acces time: %ld\n", file.st_atime);
}
