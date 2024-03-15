/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdi-pint <pdi-pint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 10:48:55 by pdi-pint          #+#    #+#             */
/*   Updated: 2024/02/26 11:59:30 by pdi-pint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

char    *ft_freejoin(char *str1, char *str2);
char	*get_next_line(int fd);
char	*ft_gnlstrchr(const char *s, int c);
size_t	ft_gnlstrlen(const char *str);
char	*ft_gnlstrjoin(char const *s1, char const *s2);
void	*ft_gnlcalloc(size_t n, size_t size);
char	*ft_gnlsubstr(char const *s, unsigned int start, size_t len);

#endif