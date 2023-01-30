/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehelee <jehelee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 20:11:07 by jehelee           #+#    #+#             */
/*   Updated: 2023/01/30 21:57:26 by jehelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/include/push_swap.h"

int	get_pivot(t_stack *stack)
{
	t_list	*tmp;
	//int		i;
	
	tmp = stack->top;
	// i = -1;
	// while (++i < 1)
	// 	tmp = tmp->next;
	return (tmp->content);
}

void	b_to_a(t_ab *stacks, int count)
{
	int	pivot;
	int	i;
	int	push_count;
	int	rb_count;
	
	if (stacks->b->size == 1)
	{
		push(stacks->a, stacks->b);
		return ;
	}
	if (count <= 0)
		return ;
    // if (stacks->b->size == 2)
    //     sort_2(stacks->b);
    // else if (stacks->b->size == 3)
    //     sort_3(stacks->b);
    // else if (stacks->b->size == 5)
    // 	sort_5_ba(stacks);
    else
    {
		rb_count = 0;
		push_count = 0;
		i = -1;
        pivot = get_max(stacks->b, count);
		while (++i < count)
		{
			if (stacks->b->top->content == pivot)
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
		b_to_a(stacks, count - 1);
    }
}

void    a_to_b(t_ab *stacks, int count)
{
	int	pivot;
	int	i;
	int	ra_count;
	int	push_count;
	
	if (stacks->a->size <= 1)
		return ;
    if (stacks->a->size == 2)
        sort_2(stacks->a);
    else if (stacks->a->size == 3)
        sort_3(stacks->a);
    else if (stacks->a->size == 5)
        sort_5_ab(stacks);
    else
    {
		push_count = 0;
		ra_count = 0;
		i = -1;
        pivot = get_pivot(stacks->a);
		while (++i < count)
		{
			if (stacks->a->top->content <= pivot)
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
		a_to_b(stacks, stacks->a->size);
		b_to_a(stacks, push_count);
    }
}