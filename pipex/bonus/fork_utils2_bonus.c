/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_utils2_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehelee <jehelee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 20:47:51 by jehelee           #+#    #+#             */
/*   Updated: 2023/03/03 23:55:46 by jehelee          ###   ########.fr       */
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

int	check_heredoc(t_pipex *pipex)
{
	int	i;

	i = 1;
	if (pipex->here_doc_flag)
		i = 2;
	return (i);
}
