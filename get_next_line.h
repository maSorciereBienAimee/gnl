/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssar <ssar@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 12:18:45 by ssar              #+#    #+#             */
/*   Updated: 2021/02/03 11:45:23 by ssar             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>

int		ft_length(char *str);
char	*ft_concate(char *s1, char *s2);
int		ft_compare(char *str, char c);
void	ft_move(char *str, int *size);
char	*ft_dup(char **dest, char *src);
int		ft_free_new(char *new_line);
int ft_temp_is_n(char **new_line, char *temp, int *size);
int		ft_end_of_line(int fd, char **line, char *new_line);
int		get_next_line(int fd, char **line);

#if BUFFER_SIZE < 0
# define BUF_SIZE 0
#else
# define BUF_SIZE BUFFER_SIZE
#endif
#endif
