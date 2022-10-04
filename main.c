#include "get_next_line.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char **argv)
{
	int fd;
	int res;
	char *str;
	
	if (argc == 1)
		fd = 0;
	else	
		fd = open(argv[1], O_RDONLY);
	res = 1;
	while (res == 1)
	{
		res = get_next_line(fd, &str);
		write(1, str, ft_length(str));
		write(1, "\n", 1);
		free(str);
	}
}
