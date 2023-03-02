/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils2_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehelee <jehelee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 17:09:33 by jehelee           #+#    #+#             */
/*   Updated: 2023/03/02 15:46:22 by jehelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/include/pipex_bonus.h"

void	error_no_pipe(t_pipex *pipex)
{
	if (pipe(pipex->pipe) == -1)
	{
		perror("pipex: ");
		exit (1);
	}
}
