/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehelee <jehelee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 18:33:04 by jehelee           #+#    #+#             */
/*   Updated: 2023/02/11 19:04:08 by jehelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./lib/include/push_swap.h"

void	swap_bn(t_stack *stack)
{
	t_list	*tmp;

	if (stack->size <= 1)
		return ;
	tmp = stack->top->next;
	if (tmp->next)
		tmp->next->prev = stack->top;
	stack->top->next = tmp->next;
	stack->top->prev = tmp;
	tmp->prev = NULL;
	tmp->next = stack->top;
	stack->top = tmp;
	if (stack->size == 2)
		stack->bottom = stack->top->next;
}

void	push_bn(t_stack *stack_to, t_stack *stack_from)
{
	int	push_num;

	if (stack_from->size == 0)
		return ;
	push_num = stack_from->top->content;
	ft_stack_pop(stack_from);
	ft_stack_push(stack_to, ft_lstnew(push_num));
}

void	rotate_bn(t_stack *stack)
{
	t_list	*tmp;

	if (stack->size <= 1)
		return ;
	tmp = stack->top;
	stack->top->next->prev = NULL;
	stack->top = stack->top->next;
	stack->bottom->next = tmp;
	tmp->next = NULL;
	tmp->prev = stack->bottom;
	stack->bottom = tmp;
}

void	reverse_rotate_bn(t_stack *stack)
{
	t_list	*tmp;

	if (stack->size <= 1)
		return ;
	tmp = stack->bottom->prev;
	if (tmp)
		tmp->next = NULL;
	stack->bottom->prev = NULL;
	stack->bottom->next = stack->top;
	stack->top->prev = stack->bottom;
	stack->top = stack->bottom;
	stack->bottom = tmp;
}
