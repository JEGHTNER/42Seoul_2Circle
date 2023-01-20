/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehelee <jehelee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 16:31:20 by jehelee           #+#    #+#             */
/*   Updated: 2023/01/20 17:51:52 by jehelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/include/so_long.h"

int	main(void)
{
	t_map		*map;

	map = malloc(sizeof(t_map));
	if(!map)
		return (0);
	map_init(map);
	int fd = open("./so_long/map.ber",O_RDONLY);
	parse_map(map, fd);
	if (map->map_error != 0)
		return (write(1,"Map Error\n", 10));

	t_list *tmp = map->head;
	while(tmp)
	{
		printf("%s\n",tmp->content);
		tmp = tmp->next;
	}
	map->mlx = mlx_init();
	map->win = mlx_new_window(map->mlx, map->map_width * 64, map->map_height * 64, "So_long");
	mlx_key_hook(map->win, key_press, map);
	init_image(map);
	set_image(map);
	mlx_loop(map->mlx);
	return (0);
}
