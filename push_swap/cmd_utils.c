/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehelee <jehelee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 23:25:24 by jehelee           #+#    #+#             */
/*   Updated: 2023/02/12 13:37:27 by jehelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/include/push_swap.h"

void	print_cmd(t_ab *stacks)
{
	t_list	*tmp;

	tmp = stacks->commands->head;
	while (tmp)
	{
		ft_printf("%s", tmp->string);
		tmp = tmp->next;
	}
}

void	del_cmd(t_list *del)
{
	t_list	*tmp1;
	t_list	*tmp2;

	tmp1 = del;
	tmp2 = del->next;
	del->prev->next = del->next->next;
	del->next->next->prev = del->prev;
	free(tmp1->string);
	free(tmp1);
	free(tmp2->string);
	free(tmp2);
}

t_list	*ft_lstnew_cmd(char *string)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (0);
	new_node -> string = ft_strdup(string);
	if (!(new_node->string))
		exit_with_error("Error\nmalloc error\n");
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
	new->next->prev = new;
	tmp->next = new;
	new->prev = tmp;
}
