/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehelee <jehelee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:35:56 by jehelee           #+#    #+#             */
/*   Updated: 2023/01/20 23:54:50 by jehelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./lib/include/so_long.h"

void init_image(t_map *map)
{
	int	img_width;
	int	img_height;

	map->img_player =mlx_xpm_file_to_image(map->mlx,"./images/front1.xpm",&img_width, &img_height);
	map->img_collectible = mlx_xpm_file_to_image(map->mlx,"./images/collectible.xpm",&img_width, &img_height);
	map->img_ground = mlx_xpm_file_to_image(map->mlx,"./images/ground.xpm",&img_width, &img_height);
	map->img_wall = mlx_xpm_file_to_image(map->mlx,"./images/wall.xpm",&img_width, &img_height);
	map->img_exit = mlx_xpm_file_to_image(map->mlx,"./images/exit.xpm",&img_width, &img_height);
}

void	set_image(t_map *map)
{
	t_list	*tmp;
	int		height;
	int		width;

	tmp = map->head;
	width = 0;
	height = 0;
	while (tmp)
	{
		width = 0;
		while (tmp->content[width])
		{
			if (tmp ->content[width] == '1')
				mlx_put_image_to_window(map->mlx, map->win, map->img_wall, width * 64, height * 64);
			else if (tmp->content[width] == '0')
				mlx_put_image_to_window(map->mlx, map->win, map->img_ground, width * 64, height * 64);
			else if (tmp->content[width] == 'P')
			{	
				mlx_put_image_to_window(map->mlx, map->win, map->img_ground, width * 64, height * 64);
				mlx_put_image_to_window(map->mlx, map->win, map->img_player, width * 64, height * 64);
			}
			else if (tmp->content[width] == 'C')
			{
				mlx_put_image_to_window(map->mlx, map->win, map->img_ground, width * 64, height * 64);
				mlx_put_image_to_window(map->mlx, map->win, map->img_collectible, width * 64, height * 64);
			}
			else if (tmp->content[width] == 'E')
				mlx_put_image_to_window(map->mlx, map->win, map->img_exit, width * 64, height * 64);
			width++;
		}
		tmp = tmp->next;
		height++;
	}
}