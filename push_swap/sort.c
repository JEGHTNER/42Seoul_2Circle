/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehelee <jehelee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 19:46:40 by jehelee           #+#    #+#             */
/*   Updated: 2023/01/24 20:31:02 by jehelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./lib/include/push_swap.h"

void    sort_2(t_stack *stack)
{
    int max;
    
    if (stack->size != 2)
        return ;
    if (stack->top > stack->top->next)
        swap(stack);
}

void	check_case(t_stack	*stack, int max, int mid, int min)
{
	if (stack->top == min && stack->top->next == max)
	{
		swap(stack);
		rotate(stack);
	}
	else if (stack->top == mid)
	{
		if (stack->top->next == max)
			reverse_rotate(stack);
		else
			swap(stack);
	}
	else if (stack->top == max)
	{
		if (stack->top->next ==min)
			rotate(stack);
		else
		{
			swap(stack);
			reverse_rotate(stack);
		}
	}
}

void    sort_3(t_stack *stack)
{
    int 	max;
	int		mid;
    int 	min;
	int		*arr;
	t_list	*tmp;

	if (stack->size != 3)
		return ;
	max = stack->top->content;
	min = stack->top->content;
	tmp = stack->top;
	while(tmp)
	{
		if (max < tmp->content)
			max = tmp->content;
		if (min > tmp->content)
			min = tmp->content;
		if (tmp->content != max && tmp->content != min)
			mid = tmp->content;
		*arr++ = tmp->content;
		tmp = tmp->next;
	}
	check_case(stack, max, mid, min);
}


