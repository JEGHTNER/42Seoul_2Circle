/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehelee <jehelee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 16:31:20 by jehelee           #+#    #+#             */
/*   Updated: 2023/01/07 20:48:58 by jehelee          ###   ########.fr       */
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

typedef struct s_map
{
	t_list	*head;
	t_list	*tail;
	int		empty_sp;
	int		wall;
	int		collectible;
	int		exit;
	int		player;
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

void	parse_map(t_map *map, int fd)
{
	char	*tmp;

	while (1)
	{
		tmp = get_next_line(fd);
		if (!tmp)
			break ;
		ft_lstadd_back(&map->head, ft_lstnew(tmp));
	}
}

void	map_init(t_map *map)
{
	map->collectible = 0;
	map->empty_sp = 0;
	map->exit = 0;
	map->wall = 0;
	map->player = 0;
	map->head = NULL;
	map->tail = NULL;
}

int	main(void)
{
	t_vars		vars;
	t_status	status;
	t_map		*map;

	map = malloc(sizeof(t_map));
	map_init(map);
	int fd = open("map.ber",O_RDONLY);
	parse_map(map, fd);
	t_list *tmp = map->head;
	while(tmp)
	{
		printf("%s\n",tmp->content);
		tmp = tmp->next;
	}
	// status_init(&status);
	// vars.mlx = mlx_init();
	// vars.win = mlx_new_window(vars.mlx, 1024, 1024, "Hello World");
	// mlx_key_hook(vars.win, key_press, &status);
	// mlx_loop(vars.mlx);

	return (0);
}
