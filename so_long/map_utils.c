/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehelee <jehelee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:36:04 by jehelee           #+#    #+#             */
/*   Updated: 2023/01/25 14:52:59 by jehelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./lib/include/so_long.h"

int	set_errors(t_map *map)
{
	if (map->collectible < 1)
		return (NO_COLLECTIBLE);
	if (map->exit != 1)
		return (EXIT_ERROR);
	if (map->player != 1)
		return (PLAYER_ERROR);
	map->c_count = map->collectible;
	return (check_valid_path(map));
}

void	set_player_node(t_map *map)
{
	int	i;

	map->p_list = map->head;
	i = -1;
	while (++i < map->p_place[0])
		map->p_list = map->p_list->next;
}

int	check_map(t_map *map)
{
	int		i;
	char	*head_line;
	char	*tail_line;

	head_line = map->head->content;
	if (!map->tail)
		return (LINE_ERROR);
	tail_line = map->tail->content;
	i = -1;
	while (++i < map->map_width)
	{
		if (head_line[i] != '1')
			return (LINE_ERROR);
	}
	while (--i >= 0)
	{
		if (tail_line[i] != '1')
			return (LINE_ERROR);
	}
	return (set_errors(map));
}

int	parse_map(t_map *map, int fd)
{
	char	*line;

	line = get_next_line(fd);
	if (!line)
		return (0);
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
	if (map->map_error == 0)
		map->map_error = check_map(map);
	map->p_list = map->head;
	set_player_node(map);
	return (1);
}

void	map_init(t_map *map)
{
	map->map_height = 0;
	map->map_width = 0;
	map->map_error = 0;
	map->collectible = 0;
	map->exit = 0;
	map->exit_found = 0;
	map->player = 0;
	map->p_place[0] = 0;
	map->p_place[1] = 0;
	map->head = NULL;
	map->tail = NULL;
	map->p_list = NULL;
	map->move = 0;
}
