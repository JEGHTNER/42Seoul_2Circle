/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehelee <jehelee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:36:04 by jehelee           #+#    #+#             */
/*   Updated: 2023/01/20 23:10:21 by jehelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/include/so_long.h"

void	check_map(t_map *map)
{
	int		i;
	char	*line;

	line = map->head->content;
	i = -1;
	while (++i < map->map_width)
	{
		if (line[i] != '1')
		{	
			map->map_error = LINE_ERROR;
			break ;
		}
	}
	if (map->collectible < 1)
		map->map_error = NO_COLLECTIBLE;
	if (map->exit < 1)
		map->map_error = NO_EXIT;
	if (map->player < 1)
		map->map_error = NO_PLAYER;
    map->c_count = map->collectible;
	check_valid_path(map);
}

void	parse_map(t_map *map, int fd)
{
	char	*line;
	int		i;

	line = get_next_line(fd);
	if (!line)
		return ;
	map->map_width = ft_strlen(line) - 1;
	map->map_height++;
	check_line(map, line);
	map->tail = ft_lstadd_back(&map->head, ft_lstnew(line));
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		check_line(map, line);
		map->tail = ft_lstadd_back(&map->head, ft_lstnew(line));
		map->map_height++;
	}
	check_map(map);
	map->p_list = map->head;
	i = -1;
	while(++i < map->p_place[0])
		map->p_list = map->p_list->next;
}

void	map_init(t_map *map)
{
	map->map_height = 0;
	map->map_width = 0;
	map->map_error = 0;
	map->collectible = 0;
	map->exit = 0;
	map->player = 0;
	map->p_place[0] = 0;
	map->p_place[1] = 0;
	map->head = NULL;
	map->tail = NULL;
	map->p_list = NULL;
}