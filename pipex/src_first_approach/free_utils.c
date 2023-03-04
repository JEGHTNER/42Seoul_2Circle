/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehelee <jehelee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 17:10:36 by jehelee           #+#    #+#             */
/*   Updated: 2023/03/02 19:26:10 by jehelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/include/pipex.h"

void	free_pipex(t_pipex *pipex)
{
	free_2d_arr(pipex->cmd1_args);
	free_2d_arr(pipex->cmd2_args);
	free_2d_arr(pipex->path_args);
	free(pipex->cmd1_path);
	free(pipex->cmd2_path);
	free(pipex);
}

char	**free_2d_arr(char **words)
{
	int	i;

	i = 0;
	if (!words)
		return (NULL);
	while (words[i])
	{
		free(words[i]);
		i++;
	}
	free(words);
	return (NULL);
}
