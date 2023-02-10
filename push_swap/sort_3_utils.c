/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehelee <jehelee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 18:52:54 by jehelee           #+#    #+#             */
/*   Updated: 2023/02/10 18:53:24 by jehelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/include/push_swap.h"

void	check_case_3(t_ab *stacks, t_stack *stack, int max, int min)
{
	if (stack->top->content == min && stack->top->next->content == max)
	{
		swap(stack, stacks->commands);
		rotate(stack, stacks->commands);
	}
	else if (stack->top->content != max && stack->top->content != min)
	{
		if (stack->top->next->content == max)
			reverse_rotate(stack, stacks->commands);
		else
			swap(stack, stacks->commands);
	}
	else if (stack->top->content == max)
	{
		if (stack->top->next->content == min)
			rotate(stack, stacks->commands);
		else
		{
			swap(stack, stacks->commands);
			reverse_rotate(stack, stacks->commands);
		}
	}
}

void	sort_3(t_ab *stacks, t_stack *stack)
{
	int		max;
	int		min;
	int		i;
	t_list	*tmp;

	max = stack->top->content;
	min = stack->top->content;
	tmp = stack->top;
	i = -1;
	while (++i < 3)
	{
		if (max < tmp->content)
			max = tmp->content;
		else if (min > tmp->content)
			min = tmp->content;
		tmp = tmp->next;
	}
	if (tmp)
		check_case_3_above(stacks, stack, max, min);
	else
		check_case_3(stacks, stack, max, min);
}
