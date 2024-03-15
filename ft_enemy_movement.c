/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enemy_movement.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdi-pint <pdi-pint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 18:39:36 by pdi-pint          #+#    #+#             */
/*   Updated: 2024/01/14 18:39:40 by pdi-pint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	enemy_init(t_data *window)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	y = -1;
	window->enemy_pos = malloc(sizeof(t_coord) * (window->enemies));
	if (!window->enemy_pos)
		return (0);
	while (window->map[++y])
	{
		x = -1;
		while (window->map[y][++x])
		{
			if (window->map[y][x] == 'G')
			{
				window->enemy_pos[i].x = x;
				window->enemy_pos[i].y = y;
				i++;
			}
		}
	}
	return (1);
}

static void	move_calculator(t_data *window, int x, int y, int i)
{
	int	rx;
	int	ry;

	rx = window->player_pos.x - x;
	ry = window->player_pos.y - y;
	if (rx < 0 && ft_move_check(window, x - 1, y, 'G'))
		window->enemy_pos[i].x -= 1;
	else
		rx = 1;
	if (ry < 0 && ft_move_check(window, x, y - 1, 'G')
		&& (x == window->enemy_pos[i].x && y == window->enemy_pos[i].y))
		window->enemy_pos[i].y -= 1;
	else
		ry = 1;
	if (rx > 0 && ft_move_check(window, x + 1, y, 'G')
		&& (x == window->enemy_pos[i].x && y == window->enemy_pos[i].y)
		&& (x != window->player_pos.x))
		window->enemy_pos[i].x += 1;
	else if (ry > 0 && ft_move_check(window, x, y + 1, 'G')
		&& (x == window->enemy_pos[i].x && y == window->enemy_pos[i].y))
		window->enemy_pos[i].y += 1;
}

int	ft_enemy_movement(t_data *window)
{
	int	x;
	int	y;
	int	i;

	i = -1;
	while (++i < window->enemies)
	{
		x = window->enemy_pos[i].x;
		y = window->enemy_pos[i].y;
		window->map[y][x] = '0';
		ft_select_image(window, '0', x, y);
		move_calculator(window, x, y, i);
		window->map[window->enemy_pos[i].y][window->enemy_pos[i].x] = 'G';
		x = window->enemy_pos[i].x;
		y = window->enemy_pos[i].y;
		ft_select_image(window, 'G', x, y);
	}
	return (0);
}
