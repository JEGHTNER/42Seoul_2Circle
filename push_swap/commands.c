/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehelee <jehelee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 20:25:10 by jehelee           #+#    #+#             */
/*   Updated: 2023/01/22 21:32:35 by jehelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./lib/include/push_swap.h"

void swap(t_stack *stack)
{
    t_list  *tmp;

    if (stack->size <= 1)
        return ;
    tmp = stack->top->next;
    stack->top->next = tmp->next;
    stack->top->prev = tmp;
    tmp->prev = NULL;
    tmp->next = stack->top;
    stack->top = tmp;
}

void    push(t_stack *stack_to, t_stack *stack_from)
{
    int push_num;
    if (stack_from->size == 0)
        return ;
    push_num = stack_from->top->content;
    ft_stack_pop(stack_from);
    ft_stack_push(stack_to, ft_lstnew(push_num));
}

void rotate(t_stack *stack)
{
	t_list	*tmp;
	
	if (stack->size <= 1)
		return ;
    tmp = stack->top;
	stack->top->next->prev = NULL;
	stack->top = stack->top->next;
	stack->bottom->next = tmp;
	tmp->next = NULL;
	stack->bottom = tmp;
}