/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehelee <jehelee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 20:46:07 by jehelee           #+#    #+#             */
/*   Updated: 2023/02/04 18:07:04 by jehelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./lib/include/push_swap.h"

void	del_cmd(t_list *del)
{
	//do free
	del->prev->next = del->next->next;
	del->next->next->prev = del->prev;
}

void	trim_cmd(t_ab *stacks)
{
	t_list	*tmp;

	tmp = stacks->commands->head;
	while (tmp->next)
	{
		if (!ft_strncmp(tmp->string, "ra\n", 4) && \
		!ft_strncmp(tmp->next->string, "rra\n", 4))
		{
			del_cmd(tmp);
			tmp = tmp->prev;
			continue ;
		}
		if (!ft_strncmp(tmp->string, "rb\n", 4) && \
		!ft_strncmp(tmp->next->string, "rrb\n", 4))
		{
			del_cmd(tmp);
			tmp = tmp->prev;
			continue ;
		}
		tmp = tmp->next;
	}
}

void	print_cmd(t_ab *stacks)
{
	t_list *tmp = stacks->commands->head;
	while (tmp)
	{
		ft_printf("%s", tmp->string);
		tmp = tmp->next;
	}
}

int main(int argc, char *argv[])
{
	t_ab		stacks;
	int			i;

	stacks.commands = malloc(sizeof(t_cmd_lst));
	if (!stacks.commands)
		return (0);
	stacks.commands->head = NULL;
	stacks.commands->tail = NULL;
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
		return (ft_printf("ERROR:sorted"));
	make_index(stacks.a, stacks.a->size);
	stacks.b = malloc(sizeof(t_stack));
	if (!stacks.b)
		return (0);
	init_stack(stacks.b, 'b');
	a_to_b(&stacks, stacks.a->size);
	b_to_a(&stacks, stacks.b->size);

	trim_cmd(&stacks);
	print_cmd(&stacks);
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
