/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehelee <jehelee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:35:44 by jehelee           #+#    #+#             */
/*   Updated: 2023/01/25 14:16:02 by jehelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../../mlx/mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include "ft_printf.h"
# include "libft.h"
# include "get_next_line.h"

# define KEY_EXIT       17
# define KEY_ESC		53
# define KEY_W			13
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2
# define NO_COLLECTIBLE 1
# define LINE_ERROR 	2
# define EXIT_ERROR		3
# define PLAYER_ERROR		4
# define NO_PATH		5

typedef struct s_map
{
	t_list	*head;
	t_list	*tail;
	t_list	*p_list;
	int		map_height;
	int		map_width;
	int		map_error;
	int		collectible;
	int		c_count;
	int		move;
	int		exit;
	int		exit_found;
	int		player;
	int		p_place[2];
	void	*mlx;
	void	*win;
	void	*img_wall;
	void	*img_ground;
	void	*img_player;
	void	*img_collectible;
	void	*img_exit;
}				t_map;

void	move_w(t_map *map);
void	move_s(t_map *map);
void	move_a(t_map *map);
void	move_d(t_map *map);
int		key_press(int keycode, t_map *map);
int		exit_game(t_map *map);
int		print_err(t_map *map);
void	check_line(t_map *map, char *line);
void	free_table(char **table);
char	**init_table(t_map *map);
int		dfs(char **table, int i, int j, t_map *map);
int		check_valid_path(t_map *map);
int		check_map(t_map *map);
int		parse_map(t_map *map, int fd);
void	map_init(t_map *map);
void	init_image(t_map *map);
void	set_image(t_map *map);
void	check_end(t_map *map);
void	get_image(t_map *map, int height, int width, char c);
void	print_image(t_list *tmp, t_map *map, int height, int width);

#endif