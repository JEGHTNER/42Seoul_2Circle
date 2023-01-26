/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_util_find_max_min.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehelee <jehelee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 21:28:55 by jehelee           #+#    #+#             */
/*   Updated: 2023/01/26 21:42:27 by jehelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./lib/include/push_swap.h"

int	get_max(t_stack *stack)
{
	int		max;
	t_list	*tmp;

	max = -2147483648;
	tmp = stack->top;
	while (tmp)
	{
		if (max < tmp->content)
			max = tmp->content;
		tmp = tmp->next;
	}
	return (max);
}

int	get_min(t_stack *stack)
{
	int		min;
	t_list	*tmp;

	min = 2147483647;
	tmp = stack->top;
	while (tmp)
	{
		if (min > tmp->content)
			min = tmp->content;
		tmp = tmp->next;
	}
	return (min);
}


