/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_input_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehelee <jehelee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:35:59 by jehelee           #+#    #+#             */
/*   Updated: 2023/01/19 16:37:30 by jehelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/include/so_long.h"

void	move_w(t_map *map)
{
	int		x;
	int		y;

	y = map->p_place[0];
	x = map->p_place[1];

	if (y - 1 < 0 || map->p_list->prev->content[x] == '1')
		return ;
	map->p_list->content[x] = '0';
	mlx_put_image_to_window(map->mlx, map->win, map->img_ground, x * 64, y * 64);
	map->p_place[0] = y - 1;
	map->p_list = map->p_list->prev;
	if (map->p_list->content[x] == '0')
		mlx_put_image_to_window(map->mlx, map->win, map->img_player, x * 64, (y - 1) * 64);
	else if (map->p_list->content[x] == 'C')
	{
		mlx_put_image_to_window(map->mlx, map->win, map->img_ground, x * 64, (y - 1) * 64);
		mlx_put_image_to_window(map->mlx, map->win, map->img_player, x * 64, (y - 1) * 64);
	}
}

void	move_s(t_map *map)
{
	int		x;
	int		y;

	y = map->p_place[0];
	x = map->p_place[1];

	if (y + 1 < 0 || map->p_list->next->content[x] == '1')
		return ;
	map->p_list->content[x] = '0';
	mlx_put_image_to_window(map->mlx, map->win, map->img_ground, x * 64, y * 64);
	map->p_place[0] = y + 1;
	map->p_list = map->p_list->next;
	if (map->p_list->content[x] == '0')
		mlx_put_image_to_window(map->mlx, map->win, map->img_player, x * 64, (y + 1) * 64);
	else if (map->p_list->content[x] == 'C')
	{
		mlx_put_image_to_window(map->mlx, map->win, map->img_ground, x * 64, (y + 1) * 64);
		mlx_put_image_to_window(map->mlx, map->win, map->img_player, x * 64, (y + 1) * 64);
	}
}

void	move_a(t_map *map)
{
	int		x;
	int		y;

	y = map->p_place[0];
	x = map->p_place[1];

	if (x - 1 < 0 || map->p_list->content[x - 1] == '1')
		return ;
	map->p_list->content[x] = '0';
	mlx_put_image_to_window(map->mlx, map->win, map->img_ground, x * 64, y * 64);
	map->p_place[1] = x - 1;
	if (map->p_list->content[x - 1] == '0')
		mlx_put_image_to_window(map->mlx, map->win, map->img_player, (x - 1) * 64, y * 64);
	else if (map->p_list->content[x - 1] == 'C')
	{
		mlx_put_image_to_window(map->mlx, map->win, map->img_ground, (x - 1) * 64, y * 64);
		mlx_put_image_to_window(map->mlx, map->win, map->img_player, (x - 1) * 64, y * 64);
	}
}

void	move_d(t_map *map)
{
	int		x;
	int		y;

	y = map->p_place[0];
	x = map->p_place[1];

	if (x + 1 < 0 || map->p_list->content[x + 1] == '1')
		return ;
	map->p_list->content[x] = '0';
	mlx_put_image_to_window(map->mlx, map->win, map->img_ground, x * 64, y * 64);
	map->p_place[1] = x + 1;
	if (map->p_list->content[x + 1] == '0')
		mlx_put_image_to_window(map->mlx, map->win, map->img_player, (x + 1) * 64, y * 64);
	else if (map->p_list->content[x + 1] == 'C')
	{
		mlx_put_image_to_window(map->mlx, map->win, map->img_ground, (x + 1) * 64, y * 64);
		mlx_put_image_to_window(map->mlx, map->win, map->img_player, (x + 1) * 64, y * 64);
	}
}

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
		exit(0);
	return (0);
}
