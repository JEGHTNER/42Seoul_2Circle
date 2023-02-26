/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehelee <jehelee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 17:07:24 by jehelee           #+#    #+#             */
/*   Updated: 2023/02/26 17:07:40 by jehelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	parent_process(t_pipex *pipex)
{
	int		status;
	int		fd;

	waitpid(pipex->pid, NULL, WNOHANG);
	if (pipex->cmd2_path == NULL)
		exit(127);
	close(pipex->pipe[PIPE_WRITE]);
	if (dup2(pipex->pipe[PIPE_READ], STDIN_FILENO) == -1)
	{
		perror("dup2");
		exit(1);
	}
	if (dup2(pipex->fd_outfile, STDOUT_FILENO) == -1)
	{
		perror("dup2");
		exit(1);
	}
	close(pipex->pipe[PIPE_READ]);
	close(pipex->fd_outfile);
	if (execve(pipex->cmd2_path, pipex->cmd2_args, pipex->envp_args) == -1)
	{
		perror("execve: ");
		exit(127);
	}
}

void	child_process(t_pipex *pipex)
{
	int		fd;

	close(pipex->pipe[PIPE_READ]);
	if (pipex->fd_infile == -1)
		exit(1);
	if (pipex->cmd1_path == NULL)
		exit(127);
	if (dup2(pipex->fd_infile, STDIN_FILENO) == -1)
	{
		perror("dup2");
		exit(1);
	}
	if (dup2(pipex->pipe[PIPE_WRITE], STDOUT_FILENO) == -1)
	{
		perror("dup2");
		exit(1);
	}
	close(pipex->pipe[PIPE_WRITE]);
	close(pipex->fd_infile);
	if (execve(pipex->cmd1_path, pipex->cmd1_args, pipex->envp_args) == -1)
	{
		perror("execve: ");
		exit(127);
	}
}
