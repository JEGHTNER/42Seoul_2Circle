/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehelee <jehelee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 19:46:40 by jehelee           #+#    #+#             */
/*   Updated: 2023/02/06 19:11:36 by jehelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./lib/include/push_swap.h"

void	sort_2(t_ab *stacks, t_stack *stack)
{
	if (stack->top->content > stack->top->next->content)
		swap(stack, stacks->commands);
}

void	check_case_3(t_ab *stacks, t_stack *stack, int max, int min)
{
	if (stack->top->content == min && stack->top->next->content == max)
	{
		swap(stack, stacks->commands);
		rotate(stack, stacks->commands);
	}
	else if (stack->top->content != max && stack->top->content != min)
	{
		if (stack->top->next->content == max)
			reverse_rotate(stack, stacks->commands);
		else
			swap(stack, stacks->commands);
	}
	else if (stack->top->content == max)
	{
		if (stack->top->next->content == min)
			rotate(stack, stacks->commands);
		else
		{
			swap(stack, stacks->commands);
			reverse_rotate(stack, stacks->commands);
		}
	}
}


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

void	sort_3(t_ab *stacks, t_stack *stack)
{
	int		max;
	int		min;
	int		i;
	t_list	*tmp;

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
	if (tmp)
		check_case_3_above(stacks, stack, max, min);
	else
		check_case_3(stacks, stack, max, min);
}

void	sort_4_ab(t_ab *stacks)
{
	int	min;
	int	i;
	int	ra_count;

	min = get_min(stacks->a, 4);
	ra_count = 0;
	i = -1;
	while (++i < 4)
	{
		if (stacks->a->top->content == min)
			push(stacks->b, stacks->a, stacks->commands);
		else if (stacks->a->size > 3)
		{
			rotate(stacks->a, stacks->commands);
			ra_count++;
		}
	}
	while (--ra_count >= 0)
		reverse_rotate(stacks->a, stacks->commands);
	sort_3(stacks, stacks->a);
	push(stacks->a, stacks->b, stacks->commands);
}

void	sort_5_ab(t_ab *stacks)
{
	int	max;
	int	min;
	int	i;
	int	ra_count;

	max = get_max(stacks->a, 5);
	min = get_min(stacks->a, 5);
	ra_count = 0;
	i = -1;
	while (++i < 5)
	{
		if (stacks->a->top->content == max || stacks->a->top->content == min)
			push(stacks->b, stacks->a, stacks->commands);
		else if (stacks->a->size > 3)
		{
			rotate(stacks->a, stacks->commands);
			ra_count++;
		}
	}
	if (stacks->b->top->content > stacks->b->top->next->content)
		swap(stacks->b, stacks->commands);
	sort_3(stacks, stacks->a);
	push(stacks->a, stacks->b, stacks->commands);
	push(stacks->a, stacks->b, stacks->commands);
	rotate(stacks->a, stacks->commands);
}

void	sort_5_ab_above(t_ab *stacks)
{
	int	max;
	int	min;
	int	i;
	int	ra_count;

	max = get_max(stacks->a, 5);
	min = get_min(stacks->a, 5);
	ra_count = 0;
	i = -1;
	while (++i < 5)
	{
		if (stacks->a->top->content == max || stacks->a->top->content == min)
			push(stacks->b, stacks->a, stacks->commands);
		else
		{
			rotate(stacks->a, stacks->commands);
			ra_count++;
		}
	}
	sort_5_norm(stacks, ra_count);
}

void	sort_5_norm(t_ab *stacks, int ra_count)
{
	if (stacks->b->top->content < stacks->b->top->next->content)
		swap(stacks->b, stacks->commands);
	push(stacks->a, stacks->b, stacks->commands);
	while (--ra_count >= 0)
		reverse_rotate(stacks->a, stacks->commands);
	sort_3(stacks, stacks->a);
	push(stacks->a, stacks->b, stacks->commands);
}
