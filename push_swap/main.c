/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehelee <jehelee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 20:46:07 by jehelee           #+#    #+#             */
/*   Updated: 2023/02/01 15:55:47 by jehelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./lib/include/push_swap.h"

void	init_stack(t_stack *stack, char name)
{
	stack->bottom = NULL;
	stack->top = NULL;
	stack->size = 0;
	stack->name = name;
	stack->both_flag = 0;
}

void	ft_stack_push(t_stack *stack, t_list *new)
{
	if (!new || !stack)
		return ;
	if (stack->size == 0)
		stack->bottom = new;
	new->next = stack->top;
	if (stack->top)
		stack->top->prev = new;
	stack->top = new;
	stack->size++;
}

void	ft_stack_pop(t_stack *stack)
{
	t_list	*tmp;

	if (!stack)
		return ;
	tmp = stack->top;
	stack->top = stack->top->next;
	if (stack->top)
		stack->top->prev = NULL;
	free(tmp);
	stack->size--;
	if (stack->size == 0)
		stack->bottom = NULL;
}


void	exit_with_error(char *str)
{
	ft_printf("%s", str);
	exit(0);
}

int main(int argc, char *argv[])
{
	t_ab stacks;

	stacks.a = malloc(sizeof(t_stack));
	if (!stacks.a)
		return (0);
	init_stack(stacks.a, 'a');
	for (int i = argc - 1; i >= 1; i--)
	{
		if (!check_argv(argv[i], stacks.a))
			return (0);
	}
	if (!check_duplicate(stacks.a))
		return (ft_printf("ERROR:sorted"));
	stacks.b = malloc(sizeof(t_stack));
	if (!stacks.b)
		return (0);
	init_stack(stacks.b, 'b');
	a_to_b(&stacks, stacks.a->size);
	b_to_a(&stacks, stacks.b->size);
	t_list *tmp = stacks.a->top;
	t_list *tmp2 = stacks.b->top;
	ft_printf("a= ");
	for (int i = 0; i < stacks.a->size; i++)
	{
		ft_printf("%d ", tmp->content);
		tmp = tmp->next;
	}
	ft_printf("\n");
	ft_printf("b= ");
	for (int i = 0; i < stacks.b->size; i++)
	{
		ft_printf("%d ", tmp2->content);
		tmp2 = tmp2->next;
	}
}
