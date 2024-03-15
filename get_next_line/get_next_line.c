/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdi-pint <pdi-pint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 10:48:11 by pdi-pint          #+#    #+#             */
/*   Updated: 2024/02/26 12:01:20 by pdi-pint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_freejoin(char *str1, char *str2)
{
	char	*temp;

	temp = ft_gnlstrjoin(str1, str2);
	free(str1);
	return (temp);
}

char	*ft_sep_str(char **testo)
{
	char	*buffer;
	char	*temp;
	char	*ret;
	int		i;
	int		j;

	i = 0;
	j = 0;
	temp = *testo;
	ret = NULL;
	while (temp[i] && temp[i] != '\n')
	{
		i++;
	}
	if (!temp[i])
		j = -1;
	i++;
	while (j != -1 && temp[i + j])
		j++;
	buffer = ft_gnlsubstr(*testo, 0, i);
	if (j != -1)
		ret = ft_gnlsubstr(*testo, i, j);
	free(temp);
	*testo = ret;
	return (buffer);
}

char	*ft_get_line(int fd, char *testo)
{
	int		bytes_read;
	char	*buffer;

	bytes_read = 1;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1 || (bytes_read == 0 && ft_gnlstrlen(testo) == 0))
		{
			free(testo);
			free(buffer);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		testo = ft_freejoin(testo, buffer);
		if (ft_gnlstrchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (testo);
}

char	*get_next_line(int fd)
{
	static char	*testo;
	char		*buffer;

	buffer = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(testo);
		return (NULL);
	}
	if (!testo)
		testo = ft_gnlcalloc(1, 1);
	if (!testo)
		return (NULL);
	testo = ft_get_line(fd, testo);
	if (!testo)
		return (NULL);
	buffer = ft_sep_str(&testo);
	return (buffer);
}

// int main()
// {
//     int fd = open("prova1.txt", O_RDONLY);

//     char *str;

// 	for (int i = 0; i < 10; i++)
// 	{
// 		str = get_next_line(fd);
//     	printf("Linea letta : (riga %i) :%s",i,  str);
// 		free(str);
// 	}
// }
