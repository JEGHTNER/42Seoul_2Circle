/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehelee <jehelee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 17:08:42 by jehelee           #+#    #+#             */
/*   Updated: 2023/03/01 14:06:30 by jehelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/include/pipex_bonus.h"

void	error_handle(t_pipex *pipex, char *argv[])
{
	error_no_infile(pipex, argv);
	error_no_outfile(pipex, argv);
	error_no_cmd(pipex);
	error_no_cmd1_path(pipex, argv);
	error_no_cmd2_path(pipex, argv);
	error_no_pipe(pipex);
}

void	error_no_cmd(t_pipex *pipex)
{
	if (pipex->cmd1_args == NULL || pipex->cmd2_args == NULL)
	{
		perror("pipex: ");
		exit(127);
	}
}

void	error_no_cmd1_path(t_pipex *pipex, char *argv[])
{
	if (pipex->cmd1_path == NULL)
	{
		ft_putstr_fd("pipex: ", 2);
		ft_putstr_fd(argv[2], 2);
		ft_putstr_fd(": command not found\n", 2);
	}
}

void	error_no_cmd2_path(t_pipex *pipex, char *argv[])
{
	if (pipex->cmd2_path == NULL)
	{
		ft_putstr_fd("pipex: ", 2);
		ft_putstr_fd(argv[3], 2);
		ft_putstr_fd(": command not found\n", 2);
	}
}

void	error_no_infile(t_pipex *pipex, char *argv[])
{
	if (pipex->fd_infile == -1)
	{
		ft_putstr_fd("pipex: ", 2);
		ft_putstr_fd(argv[1], 2);
		ft_putstr_fd(": ", 2);
		perror(NULL);
	}
}
