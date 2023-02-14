/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehelee <jehelee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 20:46:07 by jehelee           #+#    #+#             */
/*   Updated: 2023/02/14 13:21:17 by jehelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./lib/include/push_swap.h"

int	main(int argc, char *argv[])
{
	t_ab		stacks;

	init_commands(&stacks);
	stacks.a = malloc(sizeof(t_stack));
	if (!stacks.a)
		exit_with_error("Error\nmalloc error\n");
	init_stack(stacks.a, 'a');
	stacks.b = malloc(sizeof(t_stack));
	if (!stacks.b)
		exit_with_error("Error\nmalloc error\n");
	init_stack(stacks.b, 'b');
	parse_argv(argc, argv, &stacks);
	if (is_sorted(stacks.a, stacks.a->size))
		exit(EXIT_SUCCESS);
	make_index(stacks.a, stacks.a->size);
	a_to_b(&stacks, stacks.a->size);
	trim_cmd(&stacks);
	print_cmd(&stacks);
	free_stacks(&stacks);
	free_commands(&stacks);
	return (0);
}
