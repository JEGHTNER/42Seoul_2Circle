/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_sort_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehelee <jehelee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 19:11:09 by jehelee           #+#    #+#             */
/*   Updated: 2023/02/10 19:32:44 by jehelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/include/push_swap.h"

void	rev_case_3_6(t_ab *stacks, t_stack *stack)
{
	swap(stack, stacks->commands);
	push(stacks->a, stacks->b, stacks->commands);
	swap(stack, stacks->commands);
	push(stacks->a, stacks->b, stacks->commands);
	swap(stacks->a, stacks->commands);
	push(stacks->a, stacks->b, stacks->commands);
}

void	rev_check_case_3(t_ab *stacks, t_stack *stack, int max, int min)
{
	if (stack->top->content == max)
	{
		if (stack->top->next->content == min)
			rev_case_3_1(stacks, stack);
		else
			rev_case_3_2(stacks);
	}
	else if (stack->top->content != max && stack->top->content != min)
	{
		if (stack->top->next->content == max)
			rev_case_3_3(stacks, stack);
		else
			rev_case_3_4(stacks, stack);
	}
	else if (stack->top->content == min)
	{
		if (stack->top->next->content == max)
			rev_case_3_5(stacks);
		else
			rev_case_3_6(stacks, stack);
	}
}

void	rev_sort_3(t_ab *stacks, t_stack *stack)
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
	rev_check_case_3(stacks, stack, max, min);
}
