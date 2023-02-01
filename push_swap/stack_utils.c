/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehelee <jehelee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 16:11:24 by jehelee           #+#    #+#             */
/*   Updated: 2023/02/01 16:11:45 by jehelee          ###   ########.fr       */
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