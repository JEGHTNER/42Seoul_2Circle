/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehelee <jehelee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 20:11:07 by jehelee           #+#    #+#             */
/*   Updated: 2023/02/10 16:05:52 by jehelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/include/push_swap.h"

void	get_pivot(t_stack *stack, int size, int *big_pivot, int *small_pivot)
{
	t_list	*tmp;
	int		find[2];
	int		i;

	tmp = stack->top;
	make_index(stack, size);
	find[0] = size / 3 * 2;
	find[1] = size / 3;
	tmp = stack->top;
	i = -1;
	while (++i < size)
	{
		if (tmp->index == find[0])
			*big_pivot = tmp->content;
		else if (tmp->index == find[1])
			*small_pivot = tmp->content;
		tmp = tmp->next;
	}
}

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


void	b_to_a(t_ab *stacks, int count)
{
	int	pivots[2];

	if (count <= 5)
		check_count_ba(stacks, count);
	else
	{
		get_pivot(stacks->b, count, &pivots[0], &pivots[1]);
		quick_sort_rev(stacks, count, pivots);
	}
}

void	check_count_ba(t_ab *stacks, int count)
{
	if (count <= 1)
	{
		push(stacks->a, stacks->b, stacks->commands);
		return ;
	}
	if (is_rev_sorted(stacks->b, count))
	{
		while (--count >= 0)
			push(stacks->a, stacks->b, stacks->commands);
		return ;
	}
	if (count == 2)
		rev_sort_2(stacks, stacks->b);
	else if (count == 3)
		rev_sort_3(stacks, stacks->b);
	else if (count == 4)
		rev_sort_4_ba(stacks);
	else if (count == 5)
		rev_sort_5_ba(stacks);
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

void	a_to_b(t_ab *stacks, int count)
{
	int	pivots[2];

	if (count <= 5)
		check_count_ab(stacks, count);
	else
	{
		get_pivot(stacks->a, count, &pivots[0], &pivots[1]);
		quick_sort(stacks, count, pivots);
	}
}
