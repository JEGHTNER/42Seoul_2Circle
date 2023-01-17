/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehelee <jehelee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 16:31:20 by jehelee           #+#    #+#             */
/*   Updated: 2023/01/17 20:23:22 by jehelee          ###   ########.fr       */
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

typedef struct s_game
{
	void	*mlx;
	void	*win;
	void	*img_wall;
	void	*img_ground;
	void	*img_player;
	void	*img_collectible;
	void	*img_exit;

}				t_game;

typedef struct s_status
{
	int	x;
	int	y;
}				t_status;

void	move_w(t_map *map)
{
	int	x;
	int	y;

	y = map->p_place[0];
	x = map->p_place[1];

	//while ()
}

int	key_press(int keycode, t_map *map)
{
	// if (keycode == KEY_W)
	// 	move_w(map);
	// else if (keycode == KEY_S)
	// 	move_s(map);
	// else if (keycode == KEY_A)
	// 	move_a(map);
	// else if (keycode == KEY_D)
	// 	move_d(map);
	// else if (keycode == KEY_ESC)
	// 	exit(0);
	return (0);
}
#include<stdio.h>

void	check_line(t_map *map, char *line)
{
	int line_len;
	//rectangle check, first last 1 check
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
		ft_strlcpy(table[i], tmp->content, map->map_width);
		tmp = tmp->next;
	}
	return (table);
}

int dfs(char **table, int i, int j, int *found,t_map *map)
{
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
	dfs(table, i + 1, j, &found, map);
	dfs(table, i, j + 1, &found, map);
	dfs(table, i - 1, j, &found, map);
	dfs(table, i, j - 1, &found, map);
	if (found == 0)
		map->map_error = NO_PATH;
	if (map->collectible != 0)
		map->map_error = NO_PATH;
}

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

void init_image(t_game *game)
{
	int	img_width;
	int	img_height;

	game->img_player =mlx_xpm_file_to_image(game->mlx,"./so_long/images/front1.xpm",&img_width, &img_height);
	game->img_collectible = mlx_xpm_file_to_image(game->mlx,"./so_long/images/collectible.xpm",&img_width, &img_height);
	game->img_ground = mlx_xpm_file_to_image(game->mlx,"./so_long/images/ground.xpm",&img_width, &img_height);
	game->img_wall = mlx_xpm_file_to_image(game->mlx,"./so_long/images/wall.xpm",&img_width, &img_height);
	game->img_exit = mlx_xpm_file_to_image(game->mlx,"./so_long/images/exit.xpm",&img_width, &img_height);
}

void	set_image(t_map *map, t_game game)
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
				mlx_put_image_to_window(game.mlx, game.win, game.img_wall, width * 64, height * 64);
			else if (tmp->content[width] == '0')
				mlx_put_image_to_window(game.mlx, game.win, game.img_ground, width * 64, height * 64);
			else if (tmp->content[width] == 'P')
			{	
				mlx_put_image_to_window(game.mlx, game.win, game.img_ground, width * 64, height * 64);
				mlx_put_image_to_window(game.mlx, game.win, game.img_player, width * 64, height * 64);
			}
			else if (tmp->content[width] == 'C')
			{
				mlx_put_image_to_window(game.mlx, game.win, game.img_ground, width * 64, height * 64);
				mlx_put_image_to_window(game.mlx, game.win, game.img_collectible, width * 64, height * 64);
			}
			else if (tmp->content[width] == 'E')
				mlx_put_image_to_window(game.mlx, game.win, game.img_exit, width * 64, height * 64);
			width++;
		}
		tmp = tmp->next;
		height++;
	}
}

int	main(void)
{
	t_game		game;
	t_status	status;
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
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, map->map_width * 64, map->map_height * 64, "So_long");
	mlx_key_hook(game.win, key_press, map);
	init_image(&game);
	set_image(map, game);
	mlx_loop(game.mlx);
	return (0);
}
