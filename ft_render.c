/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdi-pint <pdi-pint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 16:19:25 by pdi-pint          #+#    #+#             */
/*   Updated: 2024/01/14 18:40:57 by pdi-pint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*xpm_to_img(t_data	*window, char *c, int x, int y)
{
	return (mlx_xpm_file_to_image(window->mlx, c, &x, &y));
}

void	put_img(t_data *window, void *img, int x, int y)
{
	mlx_put_image_to_window(window->mlx, window->win, img,
		x * IMG_WIDTH, y * IMG_HEIGHT);
}

void	ft_select_image(t_data *window, char c, int x, int y)
{
	if (c == '0')
		put_img(window, window->img.floor, x, y);
	else if (c == '1')
		put_img(window, window->img.wall, x, y);
	else if (c == 'C')
	{
		put_img(window, window->img.coll, x, y);
		(window->collectable)++;
	}
	else if (c == 'E')
		put_img(window, window->img.exit[0], x, y);
	else if (c == 'P')
	{
		put_img(window, window->img.player[2], x, y);
		window->player_pos.x = x;
		window->player_pos.y = y;
	}
	else if (c == 'G')
		put_img(window, window->img.enemy, x, y);
}

static void	ft_put_image(t_data *window)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (window->map[j])
	{
		while (window->map[j][i])
		{
			ft_select_image(window, window->map[j][i], i, j);
			i++;
			if (window->map[j][i] == 'G')
				window->enemies++;
		}
		i = 0;
		j++;
	}
	put_img(window, window->img.banner, 0, 0);
}

void	ft_render(t_data *window)
{
	int	i;
	int	j;

	i = IMG_WIDTH;
	j = IMG_HEIGHT;
	window->img.exit[0] = xpm_to_img(window, "img/exit.xpm", i, j);
	window->img.exit[1] = xpm_to_img(window, "img/exit_2.xpm", i, j);
	window->img.wall = xpm_to_img(window, "img/wall.xpm", i, j);
	window->img.coll = xpm_to_img(window, "img/collectable.xpm", i, j);
	window->img.floor = xpm_to_img(window, "img/floor.xpm", i, j);
	window->img.player[0] = xpm_to_img(window, "img/player_r.xpm", i, j);
	window->img.player[1] = xpm_to_img(window, "img/player_l.xpm", i, j);
	window->img.player[2] = xpm_to_img(window, "img/player_f.xpm", i, j);
	window->img.player[3] = xpm_to_img(window, "img/player_b.xpm", i, j);
	window->img.enemy = xpm_to_img(window, "img/enemy.xpm", i, j);
	window->img.banner = xpm_to_img(window, "img/banner.xpm", i, j);
	ft_put_image(window);
}
