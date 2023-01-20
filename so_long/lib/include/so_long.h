/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehelee <jehelee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:35:44 by jehelee           #+#    #+#             */
/*   Updated: 2023/01/20 17:36:35 by jehelee          ###   ########.fr       */
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
// # include "lib/include/get_next_line.h"
// # include "lib/include/libft.h"

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
	t_list	*p_list;
	int		map_height;
	int		map_width;
	int		map_error;
	int		collectible;
	int		exit;
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
int     key_press(int keycode, t_map *map);
void	check_line(t_map *map, char *line);
void	free_table(char **table);
char	**init_table(t_map *map);
int     dfs(char **table, int i, int j, int *found,t_map *map);
void	check_valid_path(t_map *map);
void	check_map(t_map *map);
void	parse_map(t_map *map, int fd);
void	map_init(t_map *map);
void    init_image(t_map *map);
void	set_image(t_map *map);
#endif