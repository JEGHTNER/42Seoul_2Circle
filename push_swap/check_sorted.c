/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehelee <jehelee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 16:08:13 by jehelee           #+#    #+#             */
/*   Updated: 2023/02/08 16:09:46 by jehelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/include/push_swap.h"

int	is_rev_sorted(t_stack *stack, int size)
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

int	is_sorted(t_stack *stack, int size)
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

void	check_count_ab(t_ab *stacks, int count)
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