/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehelee <jehelee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 20:46:07 by jehelee           #+#    #+#             */
/*   Updated: 2023/02/11 18:47:24 by jehelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./lib/include/push_swap.h"

void	check_leaks(void)
{
	system("leaks push_swap");
}

int	main(int argc, char *argv[])
{
	t_ab		stacks;

	init_commands(&stacks);
	stacks.a = malloc(sizeof(t_stack));
	if (!stacks.a)
		return (0);
	init_stack(stacks.a, 'a');
	stacks.b = malloc(sizeof(t_stack));
	if (!stacks.b)
		return (0);
	init_stack(stacks.b, 'b');
	parse_argv(argc, argv, &stacks);
	make_index(stacks.a, stacks.a->size);
	a_to_b(&stacks, stacks.a->size);
	trim_cmd(&stacks);
	print_cmd(&stacks);
	free_stacks(&stacks);
	free_commands(&stacks);
	return (0);
}
