/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_gen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdi-pint <pdi-pint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 18:40:21 by pdi-pint          #+#    #+#             */
/*   Updated: 2024/03/11 15:18:45 by pdi-pint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	rows_alloc(t_data *window, char *file_name)
{
	int		j;
	int		fd;
	int		row_count;
	char	char_check;
	void	*char_ptr;

	row_count = 1;
	char_ptr = &char_check;
	j = open(file_name, O_RDONLY | __O_DIRECTORY);
	if (j > 0)
	{
		ft_printf("type the file name");
		return (close(j), 0);
	}
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return (ft_printf("invalid file"), 0);
	while (read(fd, char_ptr, 1) > 0)
		if (char_check == '\n')
			row_count++;
	close(fd);
	window->map = ft_calloc(row_count + 1, sizeof(char *));
	if (!window->map || row_count < 0)
		return (0);
	return (row_count);
}

static int	ft_mini_map_gen(t_data *window, int row_count, int fd)
{
	int		i;
	char	*tmp;

	i = -1;
	while (++i < row_count)
	{
		window->map[i] = NULL;
		tmp = get_next_line(fd);
		if (ft_strlen(tmp) > 1)
			window->map[i] = ft_strtrim(tmp, "\n");
		else
			window->map[i] = ft_calloc(2, sizeof(char));
		if (!window->map[i])
			break ;
		free(tmp);
		tmp = NULL;
	}
	if (tmp)
		return (free(tmp), 0);
	return (1);
}

int	ft_map_gen(t_data *window, char *file_name)
{
	int		fd;
	int		row_count;
	size_t	file_len;

	row_count = rows_alloc(window, file_name);
	if (!window->map)
		return (0);
	file_len = ft_strlen(file_name);
	fd = open(file_name, O_RDONLY);
	if (!ft_mini_map_gen(window, row_count, fd))
		return (0);
	if (strncmp(file_name + file_len - 4, ".ber", 4))
		return (ft_printf("invalid type of file"), 0);
	close(fd);
	return (1);
}
