/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehelee <jehelee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 23:03:20 by jehelee           #+#    #+#             */
/*   Updated: 2023/01/25 13:20:09 by jehelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./lib/include/so_long.h"

int	key_press(int keycode, t_map *map)
{
	if (keycode == KEY_W)
		move_w(map);
	else if (keycode == KEY_S)
		move_s(map);
	else if (keycode == KEY_A)
		move_a(map);
	else if (keycode == KEY_D)
		move_d(map);
	else if (keycode == KEY_ESC)
		exit_game(map);
	return (0);
}

int	exit_game(t_map *map)
{
	mlx_destroy_window(map->mlx, map->win);
	ft_printf("You gave up!\n");
	exit(0);
}
