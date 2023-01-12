/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehelee <jehelee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 16:31:20 by jehelee           #+#    #+#             */
/*   Updated: 2023/01/12 20:16:02 by jehelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include <stdio.h>
#include "lib/include/get_next_line.h"
#include "lib/include/libft.h"

# define KEY_ESC		53
# define KEY_W			13
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2
# define NO_COLLECTIBLE 1
# define LINE_ERROR 	2
# define NO_EXIT		3
# define NO_PLAYER		4
# define NO_PATH		5

typedef struct s_map
{
	t_list	*head;
	t_list	*tail;
	int		map_height;
	int		map_width;
	int		map_error;
	int		collectible;
	int		exit;
	int		player;
	int		p_place[2];
}				t_map;

// typedef struct s_list
// {
// 	char			*content;
// 	struct s_list	next;
// }				t_list;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}				t_vars;

typedef struct s_status
{
	int	x;
	int	y;
}				t_status;

void	status_init(t_status *status)
{
	status->x = 3;
	status->y = 4;
}

int	key_press(int keycode, t_status *status)
{
	if (keycode == KEY_W)
		status->y++;
	else if (keycode == KEY_S)
		status->y--;
	else if (keycode == KEY_A)
		status->x--;
	else if (keycode == KEY_D)
		status->x++;
	else if (keycode == KEY_ESC)
		exit(0);
	printf("x: %d, y: %d\n", status->x, status->y);
	return (0);
}
#include<stdio.h>

void	check_line(t_map *map, char *line)
{
	int line_len;
	//rectangle check, first last 1 check
	line_len = -1;
	while (line[++line_len])
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
	if (line[0] != 1 || line[line_len - 1] != 1)
		map->map_error = 1;
	if (line_len != map->map_width)
		map->map_error = 1;
}

void	free_all(char **table)
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

	table = malloc(map->map_height * (sizeof(char *)));
	if (!table)
		return (NULL);
	i = -1;
	tmp = map->head;
	while (++i < map->map_height)
	{
		table[i] = malloc(map->map_width);
		if (!table[i])
		{
			free_all(table);
			return (NULL);
		}
		table[i] = tmp->content;
		tmp = tmp->next;
	}
	return (table);
}

int dfs(char **table, int i, int j, int *found)
{
	if (table[i][j] == '1')
		return (0);
	else if (table[i][j] == '0')
	{
		table[i][j] = '1';
		dfs(table, i + 1, j, found);
		dfs(table, i, j + 1, found);
		dfs(table, i - 1, j, found);
		dfs(table, i, j - 1, found);
	}
	if (table[i][j] == 'E')
	{	
		*found = 1;
		return (1);
	}
	return (0);
}

void	check_valid_path(t_map *map)
{
	char	**table;
	int		i;
	int		j;
	int		found;

	found = 0;
	table = init_table(map);
	i = map->p_place[0];
	j = map->p_place[1];
	dfs(table, i + 1, j, &found);
	dfs(table, i, j + 1, &found);
	dfs(table, i - 1, j, &found);
	dfs(table, i, j - 1, &found);
	if (found == 0)
		map->map_error = NO_PATH;
}

void	check_map(t_map *map)
{
	int		i;
	char	*line;

	line = map->head->content;
	//first line, last line 1 check
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
	check_valid_path(map);
}

void	parse_map(t_map *map, int fd)
{
	char	*line;

	line = get_next_line(fd);
	if (!line)
		return ;
	map->map_width = ft_strlen(line) - 1; // exclude \n
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
}

int	main(void)
{
	t_vars		vars;
	t_status	status;
	t_map		*map;
	void		*img;
	void		*img2;
	int			img_width;
	int			img_height;

	map = malloc(sizeof(t_map));
	map_init(map);
	int fd = open("./so_long/map.ber",O_RDONLY);
	parse_map(map, fd);
	t_list *tmp = map->head;
	while(tmp)
	{
		printf("%s\n",tmp->content);
		tmp = tmp->next;
	}
	status_init(&status);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1024, 1024, "Hello World");
	mlx_key_hook(vars.win, key_press, &status);
	img = mlx_xpm_file_to_image(vars.mlx,"./so_long/images/front1.xpm",&img_width,&img_height);
	img2 = mlx_xpm_file_to_image(vars.mlx,"./so_long/images/front2.xpm",&img_width,&img_height);
	mlx_put_image_to_window(vars.mlx, vars.win, img, 0, 0);
	mlx_put_image_to_window(vars.mlx, vars.win, img2, 0, 64);
	mlx_loop(vars.mlx);
	return (0);
}
