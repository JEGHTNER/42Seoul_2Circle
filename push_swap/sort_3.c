/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehelee <jehelee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 18:51:34 by jehelee           #+#    #+#             */
/*   Updated: 2023/02/10 18:52:18 by jehelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/include/push_swap.h"

void	check_case_3_above(t_ab *stacks, t_stack *stack, int max, int min)
{
	if (stack->top->content == min && stack->top->next->content == max)
		case_3_1(stacks, stack);
	else if (stack->top->content != max && stack->top->content != min)
	{
		if (stack->top->next->content == max)
			case_3_2(stacks, stack);
		else
			swap(stack, stacks->commands);
	}
	else if (stack->top->content == max)
	{
		if (stack->top->next->content == min)
			case_3_3(stacks, stack);
		else
			case_3_4(stacks, stack);
	}
}

void	case_3_1(t_ab *stacks, t_stack *stack)
{
	push(stacks->b, stacks->a, stacks->commands);
	swap(stack, stacks->commands);
	push(stacks->a, stacks->b, stacks->commands);
}

void	case_3_2(t_ab *stacks, t_stack *stack)
{
	push(stacks->b, stacks->a, stacks->commands);
	swap(stack, stacks->commands);
	push(stacks->a, stacks->b, stacks->commands);
	swap(stack, stacks->commands);
}

void	case_3_3(t_ab *stacks, t_stack *stack)
{
	swap(stack, stacks->commands);
	rotate(stack, stacks->commands);
	swap(stack, stacks->commands);
	reverse_rotate(stack, stacks->commands);
}	

void	case_3_4(t_ab *stacks, t_stack *stack)
{
	swap(stack, stacks->commands);
	rotate(stack, stacks->commands);
	swap(stack, stacks->commands);
	reverse_rotate(stack, stacks->commands);
	swap(stack, stacks->commands);
}
