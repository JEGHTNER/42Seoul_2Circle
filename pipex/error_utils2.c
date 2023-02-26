/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehelee <jehelee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 17:09:33 by jehelee           #+#    #+#             */
/*   Updated: 2023/02/26 17:10:01 by jehelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_no_outfile(t_pipex *pipex, char *argv[])
{
	if (pipex->fd_outfile == -1)
	{
		ft_putstr_fd("pipex: ", 2);
		ft_putstr_fd(argv[4], 2);
		ft_putstr_fd(": ", 2);
		perror(NULL);
	}
}

void	error_no_pipe(t_pipex *pipex)
{
	if (pipe(pipex->pipe) == -1)
	{
		perror("pipex: ");
		exit (1);
	}
}
