/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehelee <jehelee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 20:25:10 by jehelee           #+#    #+#             */
/*   Updated: 2023/02/01 13:58:13 by jehelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./lib/include/push_swap.h"

void swap(t_stack *stack)
{
    t_list  *tmp;

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
	if (stack->name == 'a')
		ft_printf("sa\n");
	else if (stack->name == 'b')
		ft_printf("sb\n");
}

void    push(t_stack *stack_to, t_stack *stack_from)
{
    int push_num;

    if (stack_from->size == 0)
        return ;
    push_num = stack_from->top->content;
    ft_stack_pop(stack_from);
    ft_stack_push(stack_to, ft_lstnew(push_num));
	if (stack_to->name == 'a')
		ft_printf("pa\n");
	else if (stack_to->name == 'b')
		ft_printf("pb\n");
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
	tmp->prev = stack->bottom;
	stack->bottom = tmp;
	if (stack->both_flag == 1)
		return ;
	if (stack->name == 'a')
		ft_printf("ra\n");
	else if (stack->name == 'b')
		ft_printf("rb\n");
}

void reverse_rotate(t_stack *stack)
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
	if (stack->both_flag == 1)
		return ;
	if (stack->name == 'a')
		ft_printf("rra\n");
	else if (stack->name == 'b')
		ft_printf("rrb\n");
}