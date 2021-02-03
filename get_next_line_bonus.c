/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssar <ssar@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 12:17:56 by ssar              #+#    #+#             */
/*   Updated: 2021/02/03 10:01:21 by ssar             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_free_new(char *new_line)
{
	free(new_line);
	return (-1);
}

void	ft_temp_is_n(char *new_line, char *temp, int *size)
{
	ft_move(temp, size);
	new_line = ft_concate(new_line, temp);
	if (!new_line)
		return (ft_free_new(new_line));
}

int	ft_end_of_line(int fd, char **line, char *temp, char *new_line)
{
	int	size;

	if (ft_compare(temp, '\n') != 0)
		ft_temp_is_n(new_line, temp, &size);
	while (ft_compare(temp, '\n') == 0)
	{
		size = read(fd, temp, BUFFER_SIZE);
		if (size == -1)
			return (ft_free_new(new_line));
		temp[size] = '\0';
		new_line = ft_concate(new_line, temp);
		if (!new_line)
			return (ft_free_new(new_line));
		if (size == 0)
			break ;
	}
	*line = ft_dup(line, new_line);
	if (!(*line))
		return (ft_free_new(new_line));
	free(new_line);
	if (size == 0)
		return (0);
	return (1);
}

int	get_next_line(int fd, char **line)
{
	char		*new_line;
	int			result;
	static char	stock[1024][BUF_SIZE + 1] = {{0}};

	if (fd < 0 || fd >= 1024 || !line || BUFFER_SIZE <= 0)
		return (-1);
	new_line = malloc(sizeof(char));
	if (!new_line)
		return (-1);
	new_line[0] = '\0';
	result = ft_end_of_line(fd, line, stock[fd], new_line);
	if (result == -1)
		return (-1);
	else if (result == 0)
		return (0);
	else
		return (1);
}
