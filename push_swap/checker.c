/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehelee <jehelee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 15:20:52 by jehelee           #+#    #+#             */
/*   Updated: 2023/02/11 19:35:44 by jehelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/include/push_swap_bonus.h"

void	check_leaks(void)
{
	system("leaks mychecker");
}

int	main(int argc, char *argv[])
{
	t_ab	stacks;
	char	*line;

	stacks.a = malloc(sizeof(t_stack));
	if (!stacks.a)
		return (0);
	init_stack(stacks.a, 'a');
	stacks.b = malloc(sizeof(t_stack));
	if (!stacks.b)
		return (0);
	init_stack(stacks.b, 'b');
	parse_argv(argc, argv, &stacks);
	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		do_cmd(line, &stacks);
		free(line);
	}
	if (is_sorted(stacks.a, stacks.a->size) && stacks.b->size == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_stacks(&stacks);
}

void	do_cmd(char *line, t_ab *stacks)
{
	if (!line)
		return ;
	if (!(ft_strncmp(line, "sa\n", 3)))
		swap_bn(stacks->a);
	else if (!(ft_strncmp(line, "sb\n", 3)))
		swap_bn(stacks->b);
	else if (!(ft_strncmp(line, "ra\n", 3)))
		rotate_bn(stacks->a);
	else if (!(ft_strncmp(line, "rb\n", 3)))
		rotate_bn(stacks->b);
	else if (!(ft_strncmp(line, "rra\n", 4)))
		reverse_rotate_bn(stacks->a);
	else if (!(ft_strncmp(line, "rrb\n", 4)))
		reverse_rotate_bn(stacks->b);
	else if (!(ft_strncmp(line, "pa\n", 3)))
		push_bn(stacks->a, stacks->b);
	else if (!(ft_strncmp(line, "pb\n", 3)))
		push_bn(stacks->b, stacks->a);
}
