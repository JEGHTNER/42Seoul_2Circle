/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehelee <jehelee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 16:31:20 by jehelee           #+#    #+#             */
/*   Updated: 2023/01/25 14:17:01 by jehelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/include/so_long.h"

int	main(int argc, char *argv[])
{
	t_map		*map;
	int			fd;

	if (argc != 2)
		return (ft_printf("Error\nInput Map Missing.\n"));
	map = malloc(sizeof(t_map));
	if (!map)
		return (0);
	map_init(map);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (ft_printf("Error\nFile Open Failed.\n"));
	if (!parse_map(map, fd))
		return (ft_printf("Error\nMap Parse Error.\n"));
	if (map->map_error != 0)
		return (print_err(map));
	map->mlx = mlx_init();
	map->win = mlx_new_window(map->mlx, map->map_width * 64, \
	map->map_height * 64, "So_long");
	mlx_key_hook(map->win, key_press, map);
	mlx_hook(map->win, KEY_EXIT, 0, &exit_game, map);
	init_image(map);
	set_image(map);
	mlx_loop(map->mlx);
	return (0);
}
