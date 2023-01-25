/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehelee <jehelee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:35:56 by jehelee           #+#    #+#             */
/*   Updated: 2023/01/25 13:37:26 by jehelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./lib/include/so_long.h"

void	init_image(t_map *map)
{
	int	img_width;
	int	img_height;

	map->img_player = mlx_xpm_file_to_image(map->mlx, \
	"./images/front1.xpm", &img_width, &img_height);
	map->img_collectible = mlx_xpm_file_to_image(map->mlx, \
	"./images/collectible.xpm", &img_width, &img_height);
	map->img_ground = mlx_xpm_file_to_image(map->mlx, \
	"./images/ground.xpm", &img_width, &img_height);
	map->img_wall = mlx_xpm_file_to_image(map->mlx, \
	"./images/wall.xpm", &img_width, &img_height);
	map->img_exit = mlx_xpm_file_to_image(map->mlx, \
	"./images/exit.xpm", &img_width, &img_height);
}

void	get_image(t_map *map, int height, int width, char c)
{
	if (c == '1')
		mlx_put_image_to_window(map->mlx, map->win, \
		map->img_wall, width * 64, height * 64);
	else if (c == '0')
		mlx_put_image_to_window(map->mlx, map->win, \
		map->img_ground, width * 64, height * 64);
	else if (c == 'P')
	{	
		mlx_put_image_to_window(map->mlx, map->win, \
		map->img_ground, width * 64, height * 64);
		mlx_put_image_to_window(map->mlx, map->win, \
		map->img_player, width * 64, height * 64);
	}
	else if (c == 'C')
	{
		mlx_put_image_to_window(map->mlx, map->win, \
		map->img_ground, width * 64, height * 64);
		mlx_put_image_to_window(map->mlx, map->win, \
		map->img_collectible, width * 64, height * 64);
	}
	else if (c == 'E')
		mlx_put_image_to_window(map->mlx, map->win, \
		map->img_exit, width * 64, height * 64);
}

void	print_image(t_list *tmp, t_map *map, int height, int width)
{
	while (tmp)
	{
		width = 0;
		while (tmp->content[width])
		{
			if (tmp ->content[width] == '1')
				get_image(map, height, width, '1');
			else if (tmp->content[width] == '0')
				get_image(map, height, width, '0');
			else if (tmp->content[width] == 'P')
				get_image(map, height, width, 'P');
			else if (tmp->content[width] == 'C')
				get_image(map, height, width, 'C');
			else if (tmp->content[width] == 'E')
				get_image(map, height, width, 'E');
			width++;
		}
		tmp = tmp->next;
		height++;
	}
}

void	set_image(t_map *map)
{
	t_list	*tmp;
	int		height;
	int		width;

	tmp = map->head;
	width = 0;
	height = 0;
	print_image(tmp, map, height, width);
}
