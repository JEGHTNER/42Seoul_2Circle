/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehelee <jehelee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 19:46:40 by jehelee           #+#    #+#             */
/*   Updated: 2023/02/03 16:20:32 by jehelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./lib/include/push_swap.h"

void	sort_2(t_stack *stack)
{
	if (stack->top->content > stack->top->next->content)
		swap(stack);
}

void	check_case_3(t_stack *stack, int max, int min)
{
	if (stack->top->content == min && stack->top->next->content == max)
	{
		swap(stack);
		rotate(stack);
	}
	else if (stack->top->content != max && stack->top->content != min)
	{
		if (stack->top->next->content == max)
			reverse_rotate(stack);
		else
			swap(stack);
	}
	else if (stack->top->content == max)
	{
		if (stack->top->next->content == min)
			rotate(stack);
		else
		{
			swap(stack);
			rotate(stack);
			swap(stack);
			reverse_rotate(stack);
			swap(stack);
		}
	}
}

void	sort_3(t_stack *stack)
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
	check_case_3(stack, max, min);
}

void	sort_4_ab(t_ab *stacks)
{
	int	min;
	int	i;
	int ra_count;

	min = get_min(stacks->a, 4);
	ra_count = 0;
	i = -1;
	while (++i < 4)
	{
		if (stacks->a->top->content == min)
			push(stacks->b, stacks->a);
		else if (stacks->a->size > 3)
		{
			rotate(stacks->a);
			ra_count++;
		}
	}
	sort_3(stacks->a);
	while(--ra_count >= 0)
		reverse_rotate(stacks->a);
	push(stacks->a, stacks->b);
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
			push(stacks->b, stacks->a);
		else
		{
			rotate(stacks->a);
			ra_count++;
		}
	}
	if (stacks->b->top->content < stacks->b->top->next->content)
		swap(stacks->b);
	push(stacks->a, stacks->b);
	while (--ra_count >= 0)
		reverse_rotate(stacks->a);
	sort_3(stacks->a);
	push(stacks->a, stacks->b);
}
