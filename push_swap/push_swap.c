/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehelee <jehelee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 20:11:07 by jehelee           #+#    #+#             */
/*   Updated: 2023/02/02 20:55:11 by jehelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/include/push_swap.h"

int	get_pivot(t_stack *stack, int size)
{
	t_list	*tmp;
	int		sum;
	int		find;
	int		i;

	sum = 0;
	tmp = stack->top;
	make_index(stack, size);
	i = -1;
	while (++i < size)
	{
		sum += tmp->index;
		tmp = tmp->next;
	}
	tmp = stack->top;
	find = sum / size;
	while (--i >= 0)
	{
		if (tmp->index == find)
			return (tmp->content);
		tmp = tmp->next;
	}
	return (stack->top->content);
}

void	b_to_a(t_ab *stacks, int count)
{
	int	pivot;
	int	i;
	int	push_count;
	int	rb_count;

	if (count <= 1)
	{
		push(stacks->a, stacks->b);
		return ;
	}
    if (count == 2)
        rev_sort_2(stacks, stacks->b);
    else if (count == 3)
        rev_sort_3(stacks, stacks->b);
    else if (count == 5)
    	rev_sort_5_ba(stacks);
    else
    {
		rb_count = 0;
		push_count = 0;
		i = -1;
        pivot = get_pivot(stacks->b, count);
		ft_printf("b_pivot = %d\n",pivot);
		while (++i < count)
		{
			if (stacks->b->top->content > pivot)
			{
				push(stacks->a, stacks->b);
				push_count++;
				continue ;
			}
			else
			{
				rotate(stacks->b);
				rb_count++;
			}
		}
		i = -1;
		while (++i < rb_count)
			reverse_rotate(stacks->b);
		a_to_b(stacks, push_count);
		b_to_a(stacks, count - push_count);
    }
}

void    a_to_b(t_ab *stacks, int count)
{
	int	pivot;
	int	i;
	int	ra_count;
	int	push_count;

	if (count <= 1)
		return ;
    if (count == 2)
        sort_2(stacks->a);
    else if (count == 3)
        sort_3(stacks->a);
    else if (count == 5)
        sort_5_ab(stacks);
    else
    {
		push_count = 0;
		ra_count = 0;
		i = -1;
		pivot = get_pivot(stacks->a, count);
		ft_printf("a_pivot = %d\n", pivot);
		while (++i < count)
		{
			if (stacks->a->top->content < pivot)
			{
				push(stacks->b, stacks->a);
				push_count++;
			}
			else
			{
				rotate(stacks->a);
				ra_count++;
			}
		}
		i = -1;
		while (++i < ra_count)
			reverse_rotate(stacks->a);
		a_to_b(stacks, count - push_count);
		b_to_a(stacks, push_count);
    }
}
