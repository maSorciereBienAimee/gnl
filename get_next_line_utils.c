/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssar <ssar@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 12:21:36 by ssar              #+#    #+#             */
/*   Updated: 2020/12/03 17:24:55 by ssar             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_length(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_concate(char *s1, char *s2)
{
	int		size;
	char	*tab;
	int		i;
	int		j;

	j = 0;
	i = 0;
	size = ft_length(s1) + ft_length(s2);
	if (!(tab = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	while (s1[j])
		tab[i++] = s1[j++];
	j = 0;
	while (s2[j] != '\n' && s2[j])
		tab[i++] = s2[j++];
	tab[i] = '\0';
	free(s1);
	return (tab);
}

int		ft_compare(char *str, char c)
{
	while (*str != '\0')
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}

void	ft_move(char *str, int *size)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	if (!str[i])
		return ;
	i++;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			*size = 1;
		str[j++] = str[i++];
	}
	while (j <= BUFFER_SIZE)
		str[j++] = '\0';
}

char	*ft_dup(char **dest, char *src)
{
	int len;
	int i;

	i = 0;
	len = ft_length(src);
	if (!(*dest = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (src[i])
	{
		(*dest)[i] = src[i];
		i++;
	}
	(*dest)[i] = '\0';
	return (*dest);
}
