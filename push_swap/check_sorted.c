/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehelee <jehelee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 16:08:13 by jehelee           #+#    #+#             */
/*   Updated: 2023/02/11 18:41:59 by jehelee          ###   ########.fr       */
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
