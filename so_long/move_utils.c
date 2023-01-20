/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehelee <jehelee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:35:59 by jehelee           #+#    #+#             */
/*   Updated: 2023/01/21 00:11:34 by jehelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/include/so_long.h"

void    check_end(t_map *map, int x, int y)
{
    if (map->c_count == 0)
    {
        ft_printf("You Escaped in %d moves!\n",map->move);
        exit(0);
    }
	else
	{
		mlx_put_image_to_window(map->mlx, map->win, map->img_exit, x * 64, y * 64);
		mlx_put_image_to_window(map->mlx, map->win, map->img_player, x * 64, y * 64);	
	}
}

void	check_current_place(t_map *map)
{
	int	x;
	int	y;

	x = map->p_place[1];
	y = map->p_place[0];
	if (map->p_list->content[x] != 'E')
	{
        map->p_list->content[x] = '0';
	    mlx_put_image_to_window(map->mlx, map->win, map->img_ground, x * 64, y * 64);
    }
	else
		mlx_put_image_to_window(map->mlx, map->win, map->img_exit, x * 64, y * 64);
}

void	move_w(t_map *map)
{
	int		x;
	int		y;

	y = map->p_place[0];
	x = map->p_place[1];
	if (y - 1 < 0 || map->p_list->prev->content[x] == '1')
		return ;
    ft_printf("%d moves\n",++(map->move));
    check_current_place(map);
	map->p_place[0] = y - 1;
	map->p_list = map->p_list->prev;
	if (map->p_list->content[x] == '0')
		mlx_put_image_to_window(map->mlx, map->win, map->img_player, x * 64, (y - 1) * 64);
	else if (map->p_list->content[x] == 'C')
	{
		mlx_put_image_to_window(map->mlx, map->win, map->img_ground, x * 64, (y - 1) * 64);
		mlx_put_image_to_window(map->mlx, map->win, map->img_player, x * 64, (y - 1) * 64);
        map->c_count--;
	}
    else if (map->p_list->content[x] == 'E')
        check_end(map, map->p_place[1], map->p_place[0]);
}

void	move_s(t_map *map)
{
	int		x;
	int		y;

	y = map->p_place[0];
	x = map->p_place[1];

	if (y + 1 < 0 || map->p_list->next->content[x] == '1')
		return ;
    ft_printf("%d moves\n",++(map->move));
	check_current_place(map);
	map->p_place[0] = y + 1;
	map->p_list = map->p_list->next;
	if (map->p_list->content[x] == '0')
		mlx_put_image_to_window(map->mlx, map->win, map->img_player, x * 64, (y + 1) * 64);
	else if (map->p_list->content[x] == 'C')
	{
		mlx_put_image_to_window(map->mlx, map->win, map->img_ground, x * 64, (y + 1) * 64);
		mlx_put_image_to_window(map->mlx, map->win, map->img_player, x * 64, (y + 1) * 64);
        map->c_count--;
	}
    else if (map->p_list->content[map->p_place[x]] == 'E')
  		check_end(map, map->p_place[1], map->p_place[0]);
}

void	move_a(t_map *map)
{
	int		x;
	int		y;

	y = map->p_place[0];
	x = map->p_place[1];

	if (x - 1 < 0 || map->p_list->content[x - 1] == '1')
		return ;
    ft_printf("%d moves\n",++(map->move));
	check_current_place(map);
	map->p_place[1] = x - 1;
	if (map->p_list->content[x - 1] == '0')
		mlx_put_image_to_window(map->mlx, map->win, map->img_player, (x - 1) * 64, y * 64);
	else if (map->p_list->content[x - 1] == 'C')
	{
		mlx_put_image_to_window(map->mlx, map->win, map->img_ground, (x - 1) * 64, y * 64);
		mlx_put_image_to_window(map->mlx, map->win, map->img_player, (x - 1) * 64, y * 64);
        map->c_count--;
	}
    else if (map->p_list->content[x - 1] == 'E')
        check_end(map, map->p_place[1], map->p_place[0]);
}

void	move_d(t_map *map)
{
	int		x;
	int		y;

	y = map->p_place[0];
	x = map->p_place[1];

	if (x + 1 < 0 || map->p_list->content[x + 1] == '1')
		return ;
    ft_printf("%d moves\n",++(map->move));
	check_current_place(map);
	map->p_place[1] = x + 1;
	if (map->p_list->content[x + 1] == '0')
		mlx_put_image_to_window(map->mlx, map->win, map->img_player, (x + 1) * 64, y * 64);
	else if (map->p_list->content[x + 1] == 'C')
	{
		mlx_put_image_to_window(map->mlx, map->win, map->img_ground, (x + 1) * 64, y * 64);
		mlx_put_image_to_window(map->mlx, map->win, map->img_player, (x + 1) * 64, y * 64);
        map->c_count--;	
    }
    else if (map->p_list->content[x + 1] == 'E')
        check_end(map, map->p_place[1], map->p_place[0]);
}
