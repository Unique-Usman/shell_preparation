#include <stdio.h>
#include <sys/stat.h>

//program that check if a file is present using the stat function
int main(int ac, char **argv)
{
	struct stat file;
	const char *filepath = argv[1];

	if (stat(filepath, &file) == -1)
	{
		perror("stat");
		return -1;
	}

	printf("File is present");
}
