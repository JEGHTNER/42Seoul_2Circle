/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehelee <jehelee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 17:10:36 by jehelee           #+#    #+#             */
/*   Updated: 2023/03/04 14:00:02 by jehelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/include/pipex.h"

void	ft_lstfree(t_list *lst)
{
	t_list	*tmp;

	if (!lst)
		return ;
	while (lst)
	{
		tmp = lst->next;
		free(lst);
		lst = tmp;
	}
}

void	free_pipex(t_pipex *pipex)
{
	free_2d_arr(pipex->path_args);
	free(pipex->limiter);
	free(pipex);
}

char	**free_2d_arr(char **words)
{
	int	i;

	if (!words)
		return (NULL);
	i = 0;
	while (words[i])
	{
		free(words[i]);
		i++;
	}
	free(words);
	return (NULL);
}
