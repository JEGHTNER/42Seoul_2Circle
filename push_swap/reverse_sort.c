/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehelee <jehelee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 17:07:08 by jehelee           #+#    #+#             */
/*   Updated: 2023/02/10 19:24:03 by jehelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./lib/include/push_swap.h"

void	rev_sort_2(t_ab *stacks, t_stack *stack)
{
	if (stack->top->content < stack->top->next->content)
		swap(stack, stacks->commands);
	push(stacks->a, stacks->b, stacks->commands);
	push(stacks->a, stacks->b, stacks->commands);
}

void	rev_sort_4_ba(t_ab *stacks)
{
	int	max;
	int	i;
	int	rb_count;

	rb_count = 0;
	max = get_max(stacks->b, 4);
	i = -1;
	while (++i < 4)
	{
		if (stacks->b->top->content == max)
			push(stacks->a, stacks->b, stacks->commands);
		else if (stacks->b->size > 3)
		{
			rotate(stacks->b, stacks->commands);
			rb_count++;
		}
	}
	while (--rb_count >= 0)
		reverse_rotate(stacks->b, stacks->commands);
	rev_sort_3(stacks, stacks->b);
}

void	rev_sort_5_ba(t_ab *stacks)
{
	int	max;
	int	min;
	int	i;
	int	rb_count;

	rb_count = 0;
	max = get_max(stacks->b, 5);
	min = get_min(stacks->b, 5);
	i = -1;
	while (++i < 5)
	{
		if (stacks->b->top->content == max || stacks->b->top->content == min)
			push(stacks->a, stacks->b, stacks->commands);
		else if (stacks->b->size > 3)
		{
			rotate(stacks->b, stacks->commands);
			rb_count++;
		}
	}
	while (--rb_count >= 0)
		reverse_rotate(stacks->b, stacks->commands);
	if (stacks->a->top->content > stacks->a->top->next->content)
		swap(stacks->a, stacks->commands);
	rotate(stacks->a, stacks->commands);
	rev_sort_3(stacks, stacks->b);
	reverse_rotate(stacks->a, stacks->commands);
}
