/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movement.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdi-pint <pdi-pint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 18:40:37 by pdi-pint          #+#    #+#             */
/*   Updated: 2024/01/14 18:40:39 by pdi-pint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_collectable_check(t_data *window)
{
	int	i;
	int	j;

	j = 0;
	window->collectable--;
	if (window->collectable == 0)
	{
		while (window->map[j])
		{
			i = 0;
			while (window->map[j][i])
			{
				if (window->map[j][i] == 'E')
				{
					put_img(window, window->img.exit[1], i, j);
					return ;
				}
				i++;
			}
			j++;
		}
	}
}

int	ft_move_check(t_data *window, int x, int y, char entity)
{
	if (entity == 'P')
	{
		if (window->map[y][x] == '1')
			return (0);
		if (window->map[y][x] == 'E' && window->collectable != 0)
			return (0);
		if ((window->map[y][x] == 'E' && window->collectable == 0)
			|| window->map[y][x] == 'G')
			ft_clean_exit(window);
		if (window->map[y][x] == 'C')
		{
			ft_collectable_check(window);
			window->map[y][x] = 0;
		}
	}
	if (entity == 'G')
	{
		if (window->map[y][x] == '1' || window->map[y][x] == 'E'
			|| window->map[y][x] == 'C' || window->map[y][x] == 'G')
			return (0);
		if (window->map[y][x] == 'P')
			ft_clean_exit(window);
	}
	return (1);
}

void	move_player_sprite(t_data *window, int key, int x, int y)
{
	char	*moves;

	moves = ft_itoa(window->moves);
	put_img(window, window->img.banner, 0, 0);
	mlx_string_put(window->mlx, window->win, 7, 15, 0xf00707, moves);
	if (key == 'w' || key == U)
		put_img(window, window->img.player[3], x, y);
	else if (key == 'a' || key == L)
		put_img(window, window->img.player[1], x, y);
	else if (key == 'd' || key == R)
		put_img(window, window->img.player[0], x, y);
	else
		put_img(window, window->img.player[2], x, y);
	free(moves);
}

int	ft_movement(int key, t_data *window)
{
	int	x;
	int	y;

	x = window->player_pos.x;
	y = window->player_pos.y;
	window->map[y][x] = '0';
	put_img(window, window->img.floor, x, y);
	window->moves++;
	if ((key == 'w' || key == U) && ft_move_check(window, x, y - 1, 'P'))
		y -= 1;
	else if ((key == 's' || key == D) && ft_move_check(window, x, y + 1, 'P'))
		y += 1;
	else if ((key == 'a' || key == L) && ft_move_check(window, x - 1, y, 'P'))
		x -= 1;
	else if ((key == 'd' || key == R) && ft_move_check(window, x + 1, y, 'P'))
		x += 1;
	move_player_sprite(window, key, x, y);
	window->map[y][x] = 'P';
	window->player_pos.x = x;
	window->player_pos.y = y;
	if (window->moves % 2 == 0 && window->moves > 0)
		ft_enemy_movement(window);
	if (key == ESC)
		ft_clean_exit(window);
	return (0);
}
