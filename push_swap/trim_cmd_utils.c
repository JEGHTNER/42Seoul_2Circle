/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim_cmd_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehelee <jehelee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 13:42:27 by jehelee           #+#    #+#             */
/*   Updated: 2023/02/11 13:57:27 by jehelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/include/push_swap.h"

void	trim_useless(t_ab *stacks)
{
	t_list	*tmp;
	t_list	*del;

	tmp = stacks->commands->head;
	if (!tmp)
		return ;
	while (tmp->next)
	{
		while (!ft_strncmp(tmp->string, "ra\n", 3) && \
		!ft_strncmp(tmp->next->string, "rra\n", 4))
		{
			del = tmp;
			tmp = tmp->prev;
			del_cmd(del);
		}
		while (!ft_strncmp(tmp->string, "rb\n", 3) && \
		!ft_strncmp(tmp->next->string, "rrb\n", 4))
		{
			del = tmp;
			tmp = tmp->prev;
			del_cmd(del);
		}
		tmp = tmp->next;
	}
}

void	trim_cmd(t_ab *stacks)
{
	int	i;

	i = -1;
	while (++i < 3)
	{
		trim_useless(stacks);
		trim_rrr(stacks);
		trim_rrr_2(stacks);
		trim_rbr(stacks);
		trim_rr_2(stacks);
		trim_rr(stacks);
	}
}
