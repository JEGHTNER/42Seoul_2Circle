/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehelee <jehelee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 16:11:24 by jehelee           #+#    #+#             */
/*   Updated: 2023/02/02 20:49:43 by jehelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/include/push_swap.h"

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

void	init_index(t_stack *stack, int size)
{
	t_list	*current;
	int		i;

	i = -1;
	current = stack->top;
	while (++i < size)
	{
		current->index = 0;
		current = current->next;
	}
}

void	make_index(t_stack *stack, int size)
{
	t_list	*tmp;
	t_list	*current;
	int		i;
	int		j;

	init_index(stack, size);
	i = -1;
	current = stack->top;
	while (++i < size)
	{
		j = -1;
		tmp = stack->top;
		while (++j < size)
		{
			if (current->content > tmp->content)
				current->index++;
			tmp = tmp->next;
		}
		current = current->next;
	}
}
