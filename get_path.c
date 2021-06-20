#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[], char *envp[])
{
	char *path;

	while (*envp)
	{
		if (strncmp("PATH", *envp, 4) == 0)
		{
			path = *envp;
			break;
		}
		envp++;
	}
	printf("%s\n", path);
	//ft_substr
	//PATH=....
	//ft_split(*str, ':');
	//parsing complete !!!
	return (0);
}
