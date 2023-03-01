/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehelee <jehelee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 17:07:24 by jehelee           #+#    #+#             */
/*   Updated: 2023/03/02 01:23:37 by jehelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/include/pipex_bonus.h"

void	parent_process(t_pipex *pipex)
{
	waitpid(pipex->pid, NULL, WNOHANG);
	close(pipex->pipe[PIPE_WRITE]);
	if (dup2(pipex->pipe[PIPE_READ], STDIN_FILENO) == -1)
	{
		perror("dup2");
		exit(1);
	}
	close(pipex->pipe[PIPE_READ]);
}

void	child_process(t_pipex *pipex, char *argv_i)
{
	char	**cmd_args;
	char	*cmd_path;

	cmd_args = ft_split_pipex(argv_i, ' ');
	cmd_path = get_path(cmd_args[0], pipex->path_args);
	if (cmd_path == NULL)
		exit(127);
	close(pipex->pipe[PIPE_READ]);
	if (dup2(pipex->pipe[PIPE_WRITE], STDOUT_FILENO) == -1)
	{
		perror("dup2");
		exit(1);
	}
	close(pipex->pipe[PIPE_WRITE]);
	if (execve(cmd_path, cmd_args, pipex->path_args) == -1)
	{
		perror("execve_child");
		exit(127);
	}
}

void	first_child_process(t_pipex *pipex, char **argv)
{
	char	**cmd_args;
	char	*cmd_path;
	int		i;

	close(pipex->pipe[PIPE_READ]);
	if (pipex->here_doc_flag)
	{
		i = 3;
		here_doc(pipex->limiter);
		free(pipex->limiter);
	}
	else
	{
		if (pipex->fd_infile == -1)
			exit(1);
		i = 2;
		if (dup2(pipex->fd_infile, STDIN_FILENO) == -1)
		{
			perror("dup2");
			exit(1);
		}
		close(pipex->fd_infile);
	}
	cmd_args = ft_split_pipex(argv[i], ' ');
	cmd_path = get_path(cmd_args[0], pipex->path_args);
	if (cmd_path == NULL)
		exit(127);
	if (dup2(pipex->pipe[PIPE_WRITE], STDOUT_FILENO) == -1)
	{
		perror("dup2");
		exit(1);
	}
	close(pipex->pipe[PIPE_WRITE]);
	if (execve(cmd_path, cmd_args, pipex->envp_args) == -1)
	{
		perror("execve_first_child");
		exit(127);
	}
}

void	last_child_process(t_pipex *pipex, char *argv_i)
{
	char	**cmd_args;
	char	*cmd_path;

	cmd_args = ft_split_pipex(argv_i, ' ');
	cmd_path = get_path(cmd_args[0], pipex->path_args);
	if (cmd_path == NULL)
		exit(127);
	close(pipex->pipe[PIPE_WRITE]);
	if (dup2(pipex->fd_outfile, STDOUT_FILENO) == -1)
	{
		perror("dup2");
		exit(1);
	}
	close(pipex->pipe[PIPE_READ]);
	close(pipex->fd_outfile);
	if (execve(cmd_path, cmd_args, pipex->envp_args) == -1)
	{
		perror("execve_last_child");
		exit(127);
	}
}
