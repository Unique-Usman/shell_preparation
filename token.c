#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//implementation of str token
char *_strtok(char *str, char *delimeter)
{
	static char *ptr;
	if( str != NULL)
		ptr = str;
	int pos = 0;
	//finding the position of the delimeter;
	if (*ptr != '\0'){
		char *s = strstr(ptr, delimeter);
		if (!s)
		{
			s = malloc(sizeof(char) * (strlen(ptr) + 1));
			strcpy(s, ptr);
			ptr =  "";
			return s;
		}
		pos = s - ptr;
		s = malloc(sizeof(char) * (pos + 1));
		strncpy(s, ptr, pos);
		s[pos + 1] = '\0';
		ptr = strstr(ptr, delimeter) + strlen(delimeter);
		return s;
	}else{
		return NULL;
	}
}

//a function that uses strtok
int main()
{
	char *str;
	size_t len;
	printf("Input the string that you want to split\n");
	getline(&str, &len, stdin);
	char *s;
	s = _strtok(str, "_");
	while (s != NULL)
	{
		printf("%s", s);
		s = _strtok(NULL, "_");
		printf("\n");
	}
}
