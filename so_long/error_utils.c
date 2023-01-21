/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehelee <jehelee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:35:53 by jehelee           #+#    #+#             */
/*   Updated: 2023/01/21 15:24:39 by jehelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./lib/include/so_long.h"

void	check_line(t_map *map, char *line)
{
	int line_len;
    
	line_len = -1;
	while (line[++line_len] && line[line_len] != '\n')
	{
		if (line[line_len] == 'C')
			map->collectible++;
		if (line[line_len] == 'P')
		{
			map->player++;
			map->p_place[0] = map->map_height;
			map->p_place[1] = line_len;
		}
		if (line[line_len] == 'E')
			map->exit++;
	}
	if (line[0] != '1' || line[line_len - 1] != '1')
		map->map_error = LINE_ERROR;
	if (line_len != map->map_width)
		map->map_error = LINE_ERROR;
}

void	free_table(char **table)
{
	int	i;

	i = 0;
	while (table[i])
	{
		free(table[i]);
		i++;
	}
	free(table);
}

char	**init_table(t_map *map)
{
	char	**table;
	int		i;
	t_list	*tmp;

	table = malloc(map->map_height * (sizeof(char *) + 1));
	if (!table)
		return (NULL);
	i = -1;
	tmp = map->head;
	while (++i < map->map_height)
	{
		table[i] = malloc(map->map_width);
		if (!table[i])
		{
			free_table(table);
			return (NULL);
		}
		ft_strlcpy(table[i], tmp->content, map->map_width);
		tmp = tmp->next;
	}
    table[i] = NULL;
	return (table);
}

int dfs(char **table, int i, int j, int *found,t_map *map)
{
    if (!table)
        return (0);
	if (table[i][j] == '1')
		return (0);
	if (table[i][j] == 'C')
	{
		map->collectible--;
		table[i][j] = '0';
	}
	if (table[i][j] == '0')
	{
		table[i][j] = '1';
		dfs(table, i + 1, j, found, map);
		dfs(table, i, j + 1, found, map);
		dfs(table, i - 1, j, found, map);
		dfs(table, i, j - 1, found, map);
	}
	if (table[i][j] == 'E')
	{	
		*found = 1;
		return (1);
	}
	return (0);
}

int	check_valid_path(t_map *map)
{
	char	**table;
	int		i;
	int		j;
	int		found;

	found = 0;
	table = init_table(map);
	i = map->p_place[0];
	j = map->p_place[1];
	dfs(table, i + 1, j, &found, map);
	dfs(table, i, j + 1, &found, map);
	dfs(table, i - 1, j, &found, map);
	dfs(table, i, j - 1, &found, map);
	free_table(table);
    if (found == 0)
		return (NO_PATH);
	if (map->collectible != 0)
		return (NO_PATH);
    return (0);
}
