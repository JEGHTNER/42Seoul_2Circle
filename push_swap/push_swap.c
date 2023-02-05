/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehelee <jehelee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 20:11:07 by jehelee           #+#    #+#             */
/*   Updated: 2023/02/05 20:06:56 by jehelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/include/push_swap.h"

int		is_rev_sorted(t_stack *stack, int size)
{
	t_list	*tmp;
	int		i;

	tmp = stack->top;
	i = -1;
	while (++i < size - 1)
	{
		if (tmp->content < tmp->next->content)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int		is_sorted(t_stack *stack, int size)
{
	t_list	*tmp;
	int		i;

	tmp = stack->top;
	i = -1;
	while (++i < size - 1)
	{
		if (tmp->content > tmp->next->content)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	print_stack(t_ab *stacks, int size)
{
	t_list *tmp = stacks->a->top;
	t_list *tmp2 = stacks->b->top;
	ft_printf("size = %d a= ", size);
	for (int i = 0; i < stacks->a->size; i++)
	{
		ft_printf("%d ", tmp->content);
		tmp = tmp->next;
	}
	ft_printf("\n");
	ft_printf("b= ");
	for (int i = 0; i < stacks->b->size; i++)
	{
		ft_printf("%d ", tmp2->content);
		tmp2 = tmp2->next;
	}
	ft_printf("\n");
}


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
	int	i;
	int	push_count;
	int	ra_count;
	int	rb_count;

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
	else
	{
		ra_count = 0;
		rb_count = 0;
		push_count = 0;
		i = -1;
		get_pivot(stacks->b, count, &pivots[0], &pivots[1]);
		//ft_printf("a_pivot big = %d small = %d\n", pivots[0], pivots[1]);
		while (++i < count)
		{
			if (stacks->b->top->content < pivots[1])
			{
				rotate(stacks->b, stacks->commands);
				rb_count++;
			}
			else
			{
				push(stacks->a, stacks->b, stacks->commands);
				push_count++;
				if (stacks->a->top->content < pivots[0])
				{
					ra_count++;
					rotate(stacks->a, stacks->commands);
				}
			}
		}
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
}

void	check_count(t_ab *stacks, int count)
{
	if (count <= 1)
		return ;
	if (is_sorted(stacks->a, count))
		return ;
	if (count == 2)
		sort_2(stacks, stacks->a);
	else if (count == 3)
		sort_3(stacks, stacks->a);
	else if (count == 4)
		sort_4_ab(stacks);
	else if (count == 5)
	{
		if (stacks->a->size == 5)
			sort_5_ab(stacks);
		else
			sort_5_ab_above(stacks);
	}
}

void	a_to_b(t_ab *stacks, int count)
{
	int	pivots[2];
	int	i;
	int	ra_count;
	int	rb_count;
	int	push_count;

	if (count <= 5)
		check_count(stacks, count);
	else
	{
		push_count = 0;
		ra_count = 0;
		rb_count = 0;
		i = -1;
		get_pivot(stacks->a, count, &pivots[0], &pivots[1]);
		//ft_printf("a_pivot big = %d small = %d\n", pivots[0], pivots[1]);
		while (++i < count)
		{
			if (stacks->a->top->content >= pivots[0])
			{
				rotate(stacks->a, stacks->commands);
				ra_count++;
			}
			else
			{
				push(stacks->b, stacks->a, stacks->commands);
				push_count++;
				if (stacks->b->top->content >= pivots[1])
				{
					rotate(stacks->b, stacks->commands);
					rb_count++;
				}
			}
		}
		i = -1;
		while(++i < ra_count)
			reverse_rotate(stacks->a, stacks->commands);
		i = -1;
		while(++i < rb_count)
			reverse_rotate(stacks->b, stacks->commands);
		//print_stack(stacks, count);
		a_to_b(stacks, ra_count);
		b_to_a(stacks, rb_count);
		b_to_a(stacks, push_count - rb_count);
	}
}
