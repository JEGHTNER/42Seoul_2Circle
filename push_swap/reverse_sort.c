/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehelee <jehelee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 17:07:08 by jehelee           #+#    #+#             */
/*   Updated: 2023/02/02 23:18:57 by jehelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./lib/include/push_swap.h"

void	rev_sort_2(t_ab *stacks, t_stack *stack)
{
	// if (stack->size != 2)
	// 	return ;
	if (stack->top->content < stack->top->next->content)
		swap(stack);
	push(stacks->a, stacks->b);
	push(stacks->a, stacks->b);
}

void	rev_check_case_3(t_ab *stacks, t_stack *stack, int max, int min)
{
	if (stack->top->content == max)
	{
		if (stack->top->next->content == min)
		{
			rotate(stack);
			swap(stack);
			reverse_rotate(stack);
			push(stacks->a, stacks->b);
			push(stacks->a, stacks->b);
			push(stacks->a, stacks->b);
		}
		else
		{
			push(stacks->a, stacks->b);
			push(stacks->a, stacks->b);
			push(stacks->a, stacks->b);			
		}
			
	}
	else if (stack->top->content != max && stack->top->content != min)
	{
		if (stack->top->next->content == max)
			swap(stack);
		else
		{
			push(stacks->a, stacks->b);
			swap(stack);
			push(stacks->b, stacks->a);
			swap(stack);
		}
	}
	else if (stack->top->content == min)
	{
		if (stack->top->next->content == max)
		{
			push(stacks->a, stacks->b);
			push(stacks->a, stacks->b);
			swap(stacks->a);
			push(stacks->a, stacks->b);
			swap(stacks->a);
		}
		else
		{
			swap(stack);
			push(stacks->a, stacks->b);
			swap(stack);
			push(stacks->a, stacks->b);
			swap(stacks->a);
			push(stacks->a, stacks->b);
		}
	}
}

void	rev_sort_3(t_ab *stacks, t_stack *stack)
{
	int		max;
	int		min;
	int		i;
	t_list	*tmp;

	// if (stack->size != 3)
	// 	return ;
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
			push(stacks->a, stacks->b);
		else if (stacks->b->size > 3)
		{
			rotate(stacks->b);
			rb_count++;
		}
	}
	while (--rb_count >= 0)
		reverse_rotate(stacks->b);
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
	i = 0;
	while (i < 5)
	{
		if (stacks->b->top->content == max || stacks->b->top->content == min)
			push(stacks->a, stacks->b);
		else if (stacks->b->size > 3)
		{
			rotate(stacks->b);
			rb_count++;
		}
		i++;
	}
	while (--rb_count >= 0)
		reverse_rotate(stacks->b);
	if (stacks->a->top->content > stacks->a->top->next->content)
		swap(stacks->a);
	rotate(stacks->a);
	rev_sort_3(stacks, stacks->b);
	reverse_rotate(stacks->a);
}
