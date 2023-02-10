/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehelee <jehelee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 18:44:55 by jehelee           #+#    #+#             */
/*   Updated: 2023/02/10 18:45:43 by jehelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/include/push_swap.h"

void	move_rev(t_ab *stacks, int count_arr[3], int count, int *pivots)
{
	int	i;

	count_arr[0] = 0;
	count_arr[1] = 0;
	count_arr[2] = 0;
	i = -1;
	while (++i < count)
	{
		if (stacks->b->top->content < pivots[1])
		{
			rotate(stacks->b, stacks->commands);
			(count_arr[1])++;
		}
		else
		{
			push(stacks->a, stacks->b, stacks->commands);
			(count_arr[2])++;
			if (stacks->a->top->content < pivots[0])
			{
				(count_arr[0])++;
				rotate(stacks->a, stacks->commands);
			}
		}
	}
}

void	quick_sort_rev(t_ab *stacks, int count, int *pivots)
{
	int	i;
	int	count_arr[3];
	int	ra_count;
	int	rb_count;
	int	push_count;

	i = -1;
	move_rev(stacks, count_arr, count, pivots);
	ra_count = count_arr[0];
	rb_count = count_arr[1];
	push_count = count_arr[2];
	a_to_b(stacks, push_count - ra_count);
	i = -1;
	while (++i < ra_count)
		reverse_rotate(stacks->a, stacks->commands);
	i = -1;
	while (++i < rb_count)
		reverse_rotate(stacks->b, stacks->commands);
	a_to_b(stacks, ra_count);
	b_to_a(stacks, rb_count);
}

void	move(t_ab *stacks, int count_arr[3], int count, int *pivots)
{
	int	i;

	count_arr[0] = 0;
	count_arr[1] = 0;
	count_arr[2] = 0;
	i = -1;
	while (++i < count)
	{
		if (stacks->a->top->content >= pivots[0])
		{
			rotate(stacks->a, stacks->commands);
			(count_arr[0])++;
		}
		else
		{
			push(stacks->b, stacks->a, stacks->commands);
			(count_arr[2])++;
			if (stacks->b->top->content >= pivots[1])
			{
				rotate(stacks->b, stacks->commands);
				(count_arr[1])++;
			}
		}
	}
}

void	quick_sort(t_ab *stacks, int count, int *pivots)
{
	int	i;
	int	count_arr[3];
	int	ra_count;
	int	rb_count;
	int	push_count;

	i = -1;
	move(stacks, count_arr, count, pivots);
	ra_count = count_arr[0];
	rb_count = count_arr[1];
	push_count = count_arr[2];
	i = -1;
	while (++i < ra_count)
		reverse_rotate(stacks->a, stacks->commands);
	i = -1;
	while (++i < rb_count)
		reverse_rotate(stacks->b, stacks->commands);
	a_to_b(stacks, ra_count);
	b_to_a(stacks, rb_count);
	b_to_a(stacks, push_count - rb_count);
}
