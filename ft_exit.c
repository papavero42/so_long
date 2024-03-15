/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdi-pint <pdi-pint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 18:40:15 by pdi-pint          #+#    #+#             */
/*   Updated: 2024/02/29 16:40:02 by pdi-pint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

static void	ft_clean_sprites(t_data *window)
{
	int	i;

	i = -1;
	while (++i < 2)
		if (window->img.exit[i] != NULL)
			mlx_destroy_image(window->mlx, window->img.exit[i]);
	if (window->img.wall != NULL)
		mlx_destroy_image(window->mlx, window->img.wall);
	if (window->img.coll != NULL)
		mlx_destroy_image(window->mlx, window->img.coll);
	if (window->img.floor != NULL)
		mlx_destroy_image(window->mlx, window->img.floor);
	if (window->img.enemy != NULL)
		mlx_destroy_image(window->mlx, window->img.enemy);
	i = -1;
	while (++i < 4)
		if (window->img.player[i] != NULL)
			mlx_destroy_image(window->mlx, window->img.player[i]);
}

int	ft_clean_exit(t_data *window)
{
	ft_clean_sprites(window);
	if (window->img.banner != NULL)
		mlx_destroy_image(window->mlx, window->img.banner);
	if (window->win)
		mlx_destroy_window(window->mlx, window->win);
	if (window->mlx)
		mlx_destroy_display(window->mlx);
	if (window->map)
		ft_free_map(window->map);
	free(window->enemy_pos);
	free(window->mlx);
	exit (0);
}
