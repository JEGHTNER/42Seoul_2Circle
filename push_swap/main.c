/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehelee <jehelee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 20:46:07 by jehelee           #+#    #+#             */
/*   Updated: 2023/02/10 18:21:58 by jehelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./lib/include/push_swap.h"

void	check_leaks(void)
{
	system("leaks push_swap");
}

int main(int argc, char *argv[])
{
	atexit(check_leaks);
	t_ab		stacks;
	int			i;

	init_commands(&stacks);
	stacks.a = malloc(sizeof(t_stack));
	if (!stacks.a)
		return (0);
	init_stack(stacks.a, 'a');
	i = argc;
	while (--i >= 1)
	{
		if (!check_argv(argv[i], stacks.a))
			return (0);
	}
	if (!check_duplicate(stacks.a))
		exit(1);
	make_index(stacks.a, stacks.a->size);
	stacks.b = malloc(sizeof(t_stack));
	if (!stacks.b)
		return (0);
	init_stack(stacks.b, 'b');
	a_to_b(&stacks, stacks.a->size);
	b_to_a(&stacks, stacks.b->size);
	ft_printf("\n");
	for(int i = 0; i < 5; i++)
	{
		trim_useless(&stacks);
		trim_rrr(&stacks);
		trim_rbr(&stacks);
		trim_rr_2(&stacks);
		trim_rr(&stacks);
	}
	print_cmd(&stacks);
	exit(0);
	
	// t_list *tmp = stacks.a->top;
	// t_list *tmp2 = stacks.b->top;
	// ft_printf("a= ");
	// for (int i = 0; i < stacks.a->size; i++)
	// {
	// 	ft_printf("%d ", tmp->content);
	// 	tmp = tmp->next;
	// }
	// ft_printf("\n");
	// ft_printf("b= ");
	// for (int i = 0; i < stacks.b->size; i++)
	// {
	// 	ft_printf("%d ", tmp2->content);
	// 	tmp2 = tmp2->next;
	// }
}
