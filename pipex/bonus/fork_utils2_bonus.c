/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_utils2_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehelee <jehelee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 20:47:51 by jehelee           #+#    #+#             */
/*   Updated: 2023/03/02 20:48:04 by jehelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/include/pipex_bonus.h"

int	wait_func(t_list *pid_list)
{
	int		status;
	t_list	*tmp;

	tmp = pid_list->next;
	while (tmp)
	{
		waitpid(tmp->content, &status, 0);
		tmp = tmp->next;
	}
	ft_lstfree(pid_list);
	return ((((*(int *)&(status)) >> 8) & 0x000000ff));
}
