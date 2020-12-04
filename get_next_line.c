/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssar <ssar@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 12:17:56 by ssar              #+#    #+#             */
/*   Updated: 2020/12/03 17:21:52 by ssar             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_free_new(char *new_line)
{
	free(new_line);
	return (-1);
}

int	ft_end_of_line(int fd, char **line, char *new_line)
{
	int			size;
	static char	temp[BUF_SIZE + 1] = "\0";

	if (ft_compare(temp, '\n') != 0)
	{
		ft_move(temp, &size);
		if (!(new_line = ft_concate(new_line, temp)))
			return (ft_free_new(new_line));
	}
	while (ft_compare(temp, '\n') == 0)
	{
		if ((size = read(fd, temp, BUFFER_SIZE)) == -1)
			return (ft_free_new(new_line));
		temp[size] = '\0';
		if (!(new_line = ft_concate(new_line, temp)))
			return (ft_free_new(new_line));
		if (size == 0)
			break ;
	}
	if (!(*line = ft_dup(line, new_line)))
		return (ft_free_new(new_line));
	free(new_line);
	if (size == 0)
		return (0);
	return (1);
}

int	get_next_line(int fd, char **line)
{
	char	*new_line;
	int		result;

	if (fd < 0 || line == 0 || BUFFER_SIZE <= 0)
		return (-1);
	if (!(new_line = malloc(sizeof(char))))
		return (-1);
	new_line[0] = '\0';
	result = ft_end_of_line(fd, line, new_line);
	if (result == -1)
		return (-1);
	else if (result == 0)
		return (0);
	else
		return (1);
}
