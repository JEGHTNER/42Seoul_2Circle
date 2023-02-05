/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehelee <jehelee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 20:25:10 by jehelee           #+#    #+#             */
/*   Updated: 2023/02/05 16:33:21 by jehelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./lib/include/push_swap.h"

t_list	*ft_lstnew_cmd(char *string)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (0);
	new_node -> string = ft_strdup(string);
	new_node -> next = NULL;
	new_node -> prev = NULL;
	return (new_node);
}


void	cmd_push(t_cmd_lst *commands, t_list *new)
{
	if (!new || !commands)
		return ;
	if (!(commands->head))
		commands->head = new;
	if (commands->tail)
		commands->tail->next = new;
	new->prev = commands->tail;
	commands->tail = new;
}

void	cmd_push_at(t_cmd_lst *commands, t_list *new, t_list *tmp)
{
	if (!new || !commands)
		return ;
	if (!(commands->head))
		commands->head = new;
	new->next = tmp->next;
	tmp->next = new;
	new->prev = tmp;
}

void	swap(t_stack *stack, t_cmd_lst *commands)
{
	t_list	*tmp;

	if (stack->size <= 1)
		return ;
	tmp = stack->top->next;
	if (tmp->next)
		tmp->next->prev = stack->top;
	stack->top->next = tmp->next;
	stack->top->prev = tmp;
	tmp->prev = NULL;
	tmp->next = stack->top;
	stack->top = tmp;
	if (stack->size == 2)
		stack->bottom = stack->top->next;
	if (stack->name == 'a')
		cmd_push(commands, ft_lstnew_cmd("sa\n"));
	else if (stack->name == 'b')
		cmd_push(commands, ft_lstnew_cmd("sb\n"));
}

void	push(t_stack *stack_to, t_stack *stack_from, t_cmd_lst *commands)
{
	int	push_num;

	if (stack_from->size == 0)
		return ;
	push_num = stack_from->top->content;
	ft_stack_pop(stack_from);
	ft_stack_push(stack_to, ft_lstnew(push_num));
	if (stack_to->name == 'a')
		cmd_push(commands, ft_lstnew_cmd("pa\n"));
	else if (stack_to->name == 'b')
		cmd_push(commands, ft_lstnew_cmd("pb\n"));

}

void	rotate(t_stack *stack, t_cmd_lst *commands)
{
	t_list	*tmp;

	if (stack->size <= 1)
		return ;
	tmp = stack->top;
	stack->top->next->prev = NULL;
	stack->top = stack->top->next;
	stack->bottom->next = tmp;
	tmp->next = NULL;
	tmp->prev = stack->bottom;
	stack->bottom = tmp;
	if (stack->both_flag == 1)
		return ;
	if (stack->name == 'a')
		cmd_push(commands, ft_lstnew_cmd("ra\n"));
	else if (stack->name == 'b')
		cmd_push(commands, ft_lstnew_cmd("rb\n"));
}

void	reverse_rotate(t_stack *stack, t_cmd_lst *commands)
{
	t_list	*tmp;

	if (stack->size <= 1)
		return ;
	tmp = stack->bottom->prev;
	if (tmp)
		tmp->next = NULL;
	stack->bottom->prev = NULL;
	stack->bottom->next = stack->top;
	stack->top->prev = stack->bottom;
	stack->top = stack->bottom;
	stack->bottom = tmp;
	if (stack->both_flag == 1)
		return ;
	if (stack->name == 'a')
		cmd_push(commands, ft_lstnew_cmd("rra\n"));
	else if (stack->name == 'b')
		cmd_push(commands, ft_lstnew_cmd("rrb\n"));
}
