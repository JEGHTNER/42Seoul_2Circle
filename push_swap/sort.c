/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehelee <jehelee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 19:46:40 by jehelee           #+#    #+#             */
/*   Updated: 2023/02/04 16:10:49 by jehelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./lib/include/push_swap.h"

void	sort_2(t_ab *stacks, t_stack *stack)
{
	if (stack->top->content > stack->top->next->content)
		swap(stack, stacks->commands);
}

void	check_case_3(t_ab *stacks, t_stack *stack, int max, int min)
{
	if (stack->top->content == min && stack->top->next->content == max)
	{
		push(stacks->b, stacks->a, stacks->commands);
		swap(stack, stacks->commands);
		push(stacks->a, stacks->b, stacks->commands);
	}
	else if (stack->top->content != max && stack->top->content != min)
	{
		if (stack->top->next->content == max)
		{
			push(stacks->b, stacks->a, stacks->commands);
			swap(stack, stacks->commands);
			push(stacks->a, stacks->b, stacks->commands);
			swap(stack, stacks->commands);
		}
		else
			swap(stack, stacks->commands);
	}
	else if (stack->top->content == max)
	{
		if (stack->top->next->content == min)
		{
			swap(stack, stacks->commands);
			rotate(stack, stacks->commands);
			swap(stack, stacks->commands);
			reverse_rotate(stack, stacks->commands);
		}
		else
		{
			swap(stack, stacks->commands);
			rotate(stack, stacks->commands);
			swap(stack, stacks->commands);
			reverse_rotate(stack, stacks->commands);
			swap(stack, stacks->commands);
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
	check_case_3(stacks, stack, max, min);
}

void	sort_4_ab(t_ab *stacks)
{
	int	min;
	int	i;
	int	ra_count;

	min = get_min(stacks->a, 4);
	ra_count = 0;
	i = -1;
	while (++i < 4)
	{
		if (stacks->a->top->content == min)
			push(stacks->b, stacks->a, stacks->commands);
		else if (stacks->a->size > 3)
		{
			rotate(stacks->a, stacks->commands);
			ra_count++;
		}
	}
	while (--ra_count >= 0)
		reverse_rotate(stacks->a, stacks->commands);
	sort_3(stacks, stacks->a);
	push(stacks->a, stacks->b, stacks->commands);
}

void	sort_5_ab(t_ab *stacks)
{
	int	max;
	int	min;
	int	i;
	int	ra_count;

	max = get_max(stacks->a, 5);
	min = get_min(stacks->a, 5);
	ra_count = 0;
	i = -1;
	while (++i < 5)
	{
		if (stacks->a->top->content == max || stacks->a->top->content == min)
			push(stacks->b, stacks->a, stacks->commands);
		else
		{
			rotate(stacks->a, stacks->commands);
			ra_count++;
		}
	}
	if (stacks->b->top->content < stacks->b->top->next->content)
		swap(stacks->b, stacks->commands);
	push(stacks->a, stacks->b, stacks->commands);
	while (--ra_count >= 0)
		reverse_rotate(stacks->a, stacks->commands);
	sort_3(stacks, stacks->a);
	push(stacks->a, stacks->b, stacks->commands);
}
