/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehelee <jehelee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 20:11:07 by jehelee           #+#    #+#             */
/*   Updated: 2023/02/10 19:45:52 by jehelee          ###   ########.fr       */
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
		rev_sort_5_ba(stacks, -1);
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
