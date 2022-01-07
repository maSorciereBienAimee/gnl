#include "get_next_line.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(void)
{
	int fd;
	int res;
	char *str;
	
	fd = open("test.txt", O_RDONLY);
	res = 1;
	while (res == 1)
	{
		res = get_next_line(0, &str);
		write(1, str, ft_length(str));
		write(1, "\n", 1);
		free(str);
	}
}
