/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehelee <jehelee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 17:10:36 by jehelee           #+#    #+#             */
/*   Updated: 2023/03/02 00:38:27 by jehelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/include/pipex_bonus.h"

void	free_pipex(t_pipex *pipex)
{
	free_2d_arr(pipex->path_args);
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
