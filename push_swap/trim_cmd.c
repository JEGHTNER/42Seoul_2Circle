/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehelee <jehelee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 23:05:12 by jehelee           #+#    #+#             */
/*   Updated: 2023/02/11 13:58:08 by jehelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/include/push_swap.h"

void	trim_rrr_2(t_ab *stacks)
{
	t_list	*tmp;
	t_list	*del;
	int		del_count;

	del_count = 0;
	tmp = stacks->commands->head;
	if (!tmp)
		return ;
	while (tmp->next)
	{
		while (!ft_strncmp(tmp->string, "rrb\n", 4) && \
		!ft_strncmp(tmp->next->string, "rra\n", 4))
		{
			del = tmp;
			tmp = tmp->prev;
			del_cmd(del);
			del_count++;
		}
		while (del_count > 0)
		{
			cmd_push_at(stacks->commands, ft_lstnew_cmd("rrr\n"), tmp);
			del_count--;
		}
		tmp = tmp->next;
	}
}

void	trim_rrr(t_ab *stacks)
{
	t_list	*tmp;
	t_list	*del;
	int		del_count;

	del_count = 0;
	tmp = stacks->commands->head;
	if (!tmp)
		return ;
	while (tmp->next)
	{
		while (!ft_strncmp(tmp->string, "rra\n", 4) && \
		!ft_strncmp(tmp->next->string, "rrb\n", 4))
		{
			del = tmp;
			tmp = tmp->prev;
			del_cmd(del);
			del_count++;
		}
		while (del_count > 0)
		{
			cmd_push_at(stacks->commands, ft_lstnew_cmd("rrr\n"), tmp);
			del_count--;
		}
		tmp = tmp->next;
	}
}

void	trim_rr(t_ab *stacks)
{
	t_list	*tmp;
	t_list	*del;
	int		del_count;

	del_count = 0;
	tmp = stacks->commands->head;
	if (!tmp)
		return ;
	while (tmp->next)
	{
		while (!ft_strncmp(tmp->string, "ra\n", 3) && \
		!ft_strncmp(tmp->next->string, "rb\n", 3))
		{
			del = tmp;
			tmp = tmp->prev;
			del_cmd(del);
			del_count++;
		}
		while (del_count > 0)
		{
			cmd_push_at(stacks->commands, ft_lstnew_cmd("rr\n"), tmp);
			del_count--;
		}
		tmp = tmp->next;
	}
}

void	trim_rr_2(t_ab *stacks)
{
	t_list	*tmp;
	t_list	*del;
	int		del_count;

	del_count = 0;
	tmp = stacks->commands->head;
	if (!tmp)
		return ;
	while (tmp->next)
	{
		while (!ft_strncmp(tmp->string, "rb\n", 3) && \
		!ft_strncmp(tmp->next->string, "ra\n", 3))
		{
			del = tmp;
			tmp = tmp->prev;
			del_cmd(del);
			del_count++;
		}
		while (del_count > 0)
		{
			cmd_push_at(stacks->commands, ft_lstnew_cmd("rr\n"), tmp);
			del_count--;
		}
		tmp = tmp->next;
	}
}

void	trim_rbr(t_ab *stacks)
{
	t_list	*tmp;
	t_list	*del;

	tmp = stacks->commands->head;
	while (tmp && tmp->next)
	{
		while (!ft_strncmp(tmp->string, "ra\n", 3) && \
		!ft_strncmp(tmp->next->string, "rrr\n", 4))
		{
			del = tmp;
			tmp = tmp->prev;
			del_cmd(del);
			cmd_push_at(stacks->commands, ft_lstnew_cmd("rrb\n"), tmp);
		}
		while (!ft_strncmp(tmp->string, "rb\n", 3) && \
		!ft_strncmp(tmp->next->string, "rrr\n", 4))
		{
			del = tmp;
			tmp = tmp->prev;
			del_cmd(del);
			cmd_push_at(stacks->commands, ft_lstnew_cmd("rra\n"), tmp);
		}
		tmp = tmp->next;
	}
}
