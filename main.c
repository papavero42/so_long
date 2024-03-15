/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdi-pint <pdi-pint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 18:41:05 by pdi-pint          #+#    #+#             */
/*   Updated: 2024/02/29 16:37:25 by pdi-pint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_data	prova;

	if (ac != 2)
		return (ft_printf("You can only type one map"), 1);
	prova = (t_data){0};
	prova.mlx = mlx_init();
	if (!prova.mlx)
		return (!ft_clean_exit(&prova));
	if (!ft_map_gen(&prova, av[1]))
		return (!ft_clean_exit(&prova));
	if (!ft_parsing(&prova))
		return (!ft_clean_exit(&prova));
	prova.win = mlx_new_window(prova.mlx,
			ft_strlen(prova.map[0]) * IMG_WIDTH,
			count_map_lines(prova.map) * IMG_HEIGHT,
			"Ghost");
	ft_render(&prova);
	if (!enemy_init(&prova))
		return (!ft_clean_exit(&prova));
	mlx_hook(prova.win, 17, 0, ft_clean_exit, &prova);
	mlx_hook(prova.win, 2, 1L << 0, ft_movement, &prova);
	mlx_loop(prova.mlx);
}
