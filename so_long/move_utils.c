/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehelee <jehelee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:35:59 by jehelee           #+#    #+#             */
/*   Updated: 2023/01/25 17:34:02 by jehelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./lib/include/so_long.h"

void	check_end(t_map *map)
{
	if (map->c_count == 0)
	{
		ft_printf("You Escaped in %d moves!\n", map->move);
		exit(0);
	}
}

void	move_w(t_map *map)
{
	int	x;
	int	y;

	y = map->p_place[0];
	x = map->p_place[1];
	if (y - 1 < 0 || map->p_list->prev->content[x] == '1' || \
	(map->c_count != 0 && map->p_list->prev->content[x] == 'E'))
		return ;
	ft_printf("%d moves\n", ++(map->move));
	map->p_list->content[x] = '0';
	get_image(map, y, x, '0');
	map->p_place[0] = y - 1;
	map->p_list = map->p_list->prev;
	if (map->p_list->content[x] == '0')
		get_image(map, y - 1, x, 'P');
	else if (map->p_list->content[x] == 'C')
	{
		get_image(map, y - 1, x, '0');
		get_image(map, y - 1, x, 'P');
		map->c_count--;
	}
	else if (map->p_list->content[x] == 'E')
		check_end(map);
}

void	move_s(t_map *map)
{
	int	x;
	int	y;

	y = map->p_place[0];
	x = map->p_place[1];
	if (y + 1 < 0 || map->p_list->next->content[x] == '1' || \
	(map->c_count != 0 && map->p_list->next->content[x] == 'E'))
		return ;
	ft_printf("%d moves\n", ++(map->move));
	map->p_list->content[x] = '0';
	get_image(map, y, x, '0');
	map->p_place[0] = y + 1;
	map->p_list = map->p_list->next;
	if (map->p_list->content[x] == '0')
		get_image(map, y + 1, x, 'P');
	else if (map->p_list->content[x] == 'C')
	{
		get_image(map, y + 1, x, '0');
		get_image(map, y + 1, x, 'P');
		map->c_count--;
	}
	else if (map->p_list->content[map->p_place[x]] == 'E')
		check_end(map);
}

void	move_a(t_map *map)
{
	int	x;
	int	y;

	y = map->p_place[0];
	x = map->p_place[1];
	if (x - 1 < 0 || map->p_list->content[x - 1] == '1' || \
	(map->c_count != 0 && map->p_list->content[x - 1] == 'E'))
		return ;
	ft_printf("%d moves\n", ++(map->move));
	map->p_list->content[x] = '0';
	get_image(map, y, x, '0');
	map->p_place[1] = x - 1;
	if (map->p_list->content[x - 1] == '0')
		get_image(map, y, x - 1, 'P');
	else if (map->p_list->content[x - 1] == 'C')
	{
		get_image(map, y, x - 1, '0');
		get_image(map, y, x - 1, 'P');
		map->c_count--;
	}
	else if (map->p_list->content[x - 1] == 'E')
		check_end(map);
}

void	move_d(t_map *map)
{
	int	x;
	int	y;

	y = map->p_place[0];
	x = map->p_place[1];
	if (x + 1 < 0 || map->p_list->content[x + 1] == '1' || \
	(map->c_count != 0 && map->p_list->content[x + 1] == 'E'))
		return ;
	ft_printf("%d moves\n", ++(map->move));
	map->p_list->content[x] = '0';
	get_image(map, y, x, '0');
	map->p_place[1] = x + 1;
	if (map->p_list->content[x + 1] == '0')
		get_image(map, y, x + 1, 'P');
	else if (map->p_list->content[x + 1] == 'C')
	{
		get_image(map, y, x + 1, '0');
		get_image(map, y, x + 1, 'P');
		map->c_count--;
	}
	else if (map->p_list->content[x + 1] == 'E')
		check_end(map);
}
