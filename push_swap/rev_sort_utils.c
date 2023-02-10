/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_sort_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehelee <jehelee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 19:08:56 by jehelee           #+#    #+#             */
/*   Updated: 2023/02/10 19:31:56 by jehelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/include/push_swap.h"

void	rev_case_3_1(t_ab *stacks, t_stack *stack)
{
	rotate(stack, stacks->commands);
	swap(stack, stacks->commands);
	reverse_rotate(stack, stacks->commands);
	push(stacks->a, stacks->b, stacks->commands);
	push(stacks->a, stacks->b, stacks->commands);
	push(stacks->a, stacks->b, stacks->commands);
}

void	rev_case_3_2(t_ab *stacks)
{
	push(stacks->a, stacks->b, stacks->commands);
	push(stacks->a, stacks->b, stacks->commands);
	push(stacks->a, stacks->b, stacks->commands);
}

void	rev_case_3_3(t_ab *stacks, t_stack *stack)
{
	swap(stack, stacks->commands);
	push(stacks->a, stacks->b, stacks->commands);
	push(stacks->a, stacks->b, stacks->commands);
	push(stacks->a, stacks->b, stacks->commands);
}	

void	rev_case_3_4(t_ab *stacks, t_stack *stack)
{
	push(stacks->a, stacks->b, stacks->commands);
	swap(stack, stacks->commands);
	push(stacks->b, stacks->a, stacks->commands);
	swap(stack, stacks->commands);
	push(stacks->a, stacks->b, stacks->commands);
	push(stacks->a, stacks->b, stacks->commands);
	push(stacks->a, stacks->b, stacks->commands);
}

void	rev_case_3_5(t_ab *stacks)
{
	push(stacks->a, stacks->b, stacks->commands);
	push(stacks->a, stacks->b, stacks->commands);
	swap(stacks->a, stacks->commands);
	push(stacks->a, stacks->b, stacks->commands);
	swap(stacks->a, stacks->commands);
}
