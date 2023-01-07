/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehelee <jehelee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 16:31:20 by jehelee           #+#    #+#             */
/*   Updated: 2023/01/07 18:35:38 by jehelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include <stdio.h>

# define KEY_ESC		53
# define KEY_W			13
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2

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

int	main(void)
{
	t_vars		vars;
	t_status	status;

	status_init(&status);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1024, 1024, "Hello World");
	mlx_key_hook(vars.win, key_press, &status);
	mlx_loop(vars.mlx);
	return (0);
}
