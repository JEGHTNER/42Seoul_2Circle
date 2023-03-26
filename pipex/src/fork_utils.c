/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehelee <jehelee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 17:07:24 by jehelee           #+#    #+#             */
/*   Updated: 2023/03/26 16:53:30 by jehelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/include/pipex.h"

void	parent_process(int pipe_fd[2], t_list *pid_list, t_pipex *pipex)
{
	ft_lstadd_back((&pid_list), ft_lstnew(pipex->pid));
	close(pipe_fd[PIPE_WRITE]);
	if (dup2(pipe_fd[PIPE_READ], STDIN_FILENO) == -1)
	{
		perror("dup2");
		exit(1);
	}
	close(pipe_fd[PIPE_READ]);
}

void	child_process(t_pipex *pipex, char **argv, int i, int pipe_fd[2])
{
	char	**cmd_args;
	char	*cmd_path;

	cmd_args = ft_split_pipex(argv[i], ' ');
	cmd_path = get_path(cmd_args[0], pipex->path_args);
	error_no_cmd_path(cmd_path, argv, i);
	close(pipe_fd[PIPE_READ]);
	if (dup2(pipe_fd[PIPE_WRITE], STDOUT_FILENO) == -1)
	{
		perror("dup2");
		exit(1);
	}
	close(pipe_fd[PIPE_WRITE]);
	if (execve(cmd_path, cmd_args, pipex->envp_args) == -1)
		exit(127);
}

void	first_child_process(t_pipex *pipex, int ac, char **av, int pipe_fd[2])
{
	char	**cmd_args;
	char	*cmd_path;
	int		i;

	close(pipe_fd[PIPE_READ]);
	if (pipex->here_doc_flag)
		first_child_heredoc(pipex, ac, av);
	else
		first_child_infile(pipex, &i);
	if (dup2(pipe_fd[PIPE_WRITE], STDOUT_FILENO) == -1)
	{
		perror("dup2");
		exit(1);
	}
	cmd_args = ft_split_pipex(av[i], ' ');
	cmd_path = get_path(cmd_args[0], pipex->path_args);
	error_no_cmd_path(cmd_path, av, i);
	close(pipe_fd[PIPE_WRITE]);
	if (execve(cmd_path, cmd_args, pipex->envp_args) == -1)
		exit(127);
}

void	last_child_process(t_pipex *pipex, char **argv, int i, int pipe_fd[2])
{
	char	**cmd_args;
	char	*cmd_path;

	cmd_args = ft_split_pipex(argv[i], ' ');
	cmd_path = get_path(cmd_args[0], pipex->path_args);
	error_no_cmd_path(cmd_path, argv, i);
	close(pipe_fd[PIPE_WRITE]);
	if (dup2(pipex->fd_outfile, STDOUT_FILENO) == -1)
	{
		perror("dup2");
		exit(1);
	}
	close(pipe_fd[PIPE_READ]);
	close(pipex->fd_outfile);
	if (execve(cmd_path, cmd_args, pipex->envp_args) == -1)
		exit(127);
}

void	multi_pipe(t_pipex *pipex, int argc, char *argv[], t_list *pid_list)
{
	int		pipe_fd[2];
	int		i;

	i = check_heredoc(pipex);
	while (++i < argc - 1)
	{
		if (pipe(pipe_fd) == -1)
			perror("pipe");
		pipex->pid = fork();
		if (pipex->pid == -1)
			perror("fork");
		else if (pipex->pid == 0)
		{
			if (i == 2 || (pipex->here_doc_flag && i == 3))
				first_child_process(pipex, argc, argv, pipe_fd);
			if (i == argc - 2)
				last_child_process(pipex, argv, i, pipe_fd);
			child_process(pipex, argv, i, pipe_fd);
		}
		else
			parent_process(pipe_fd, pid_list, pipex);
	}
}
