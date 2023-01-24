/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehelee <jehelee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 19:46:40 by jehelee           #+#    #+#             */
/*   Updated: 2023/01/24 21:41:42 by jehelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./lib/include/push_swap.h"

void    sort_2(t_stack *stack)
{   
	
    if (stack->size != 2)
        return ;
	
    if (stack->top->content > stack->top->next->content)
        swap(stack);
}

void	check_case_3(t_stack	*stack, int max, int mid, int min)
{
	if (stack->top->content == min && stack->top->next->content == max)
	{
		swap(stack);
		rotate(stack);
	}
	else if (stack->top->content == mid)
	{
		if (stack->top->next->content == max)
			reverse_rotate(stack);
		else
			swap(stack);
	}
	else if (stack->top->content == max)
	{
		if (stack->top->next->content == min)
			rotate(stack);
		else
		{
			swap(stack);
			reverse_rotate(stack);
		}
	}
}

void    sort_3(t_stack *stack)
{
    int 	max;
	int		mid;
    int 	min;
	t_list	*tmp;

	if (stack->size != 3)
		return ;
	max = stack->top->content;
	min = stack->top->content;
	tmp = stack->top;
	while (tmp)
	{
		if (max < tmp->content)
			max = tmp->content;
		if (min > tmp->content)
			min = tmp->content;
		if (tmp->content != max && tmp->content != min)
			mid = tmp->content;
		tmp = tmp->next;
	}
	check_case_3(stack, max, mid, min);
}

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

void	sort_5(t_ab *stacks)
{
	int		max;
	int		min;
	int		i;
	
	if (stacks->a->size != 5)
		return ;
	max = get_max(stacks->a);
	min = get_min(stacks->a);
	i = 0;
	while (i < 5)
	{
		if (stacks->a->top->content == max || stacks->a->top->content == min)
			push(stacks->b, stacks->a);
		else
			rotate(stacks->a);
		i++;
	}
	sort_3(stacks->a);
	sort_2(stacks->b);
	push(stacks->a, stacks->b);
	push(stacks->a, stacks->b);
	rotate(stacks->a);
}
