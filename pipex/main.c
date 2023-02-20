/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehelee <jehelee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 14:23:29 by jehelee           #+#    #+#             */
/*   Updated: 2023/02/20 23:51:54 by jehelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

typedef enum pipex_error
{
	NO_ERROR,
	ARGUMENT_ERROR,
	OPEN_ERROR,
	FORK_ERROR,
	DUP2_ERROR,
	EXECVE_ERROR,
}	t_pipex_error;

typedef enum pipex_status
{
	PIPE_READ,
	PIPE_WRITE,
}	t_pipex_status;

typedef struct s_pipex
{
	int		fd_infile;
	int		fd_outfile;
	int		pipe[2];
	char	**cmd1_args;
	char	**cmd2_args;
	char	**envp_args;
	char	**path_args;
	char	*cmd1_path;
	char	*cmd2_path;
	pid_t	pid;
}			t_pipex;

char	**get_path_args(char **envp)
{
	int		i;
	char	*path;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			path = envp[i] + 5;
			return (ft_split(path, ':'));
		}
		i++;
	}
	return (NULL);
}

char	*get_path(char *cmd, char **path_args)
{
	int		i;
	char	*tmp;
	char	*tmp2;

	if (access(cmd, X_OK) == 0)
		return (ft_strdup(cmd));
	i = 0;
	while (path_args[i])
	{
		tmp = ft_strjoin(path_args[i], "/");
		if (!tmp)
			return (NULL);
		tmp2 = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(tmp2, X_OK) == 0)
			return (tmp2);
		free(tmp2);
		i++;
	}
	return (NULL);
}

t_pipex	*init_pipex(char **argv, char **envp)
{
	t_pipex	*pipex;

	pipex = malloc(sizeof(t_pipex));
	if (!pipex)
		return (NULL);
	pipex->fd_infile = open(argv[1], O_RDONLY);
	pipex->fd_outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	pipex->cmd1_args = ft_split_pipex(argv[2], ' ');
	pipex->cmd2_args = ft_split_pipex(argv[3], ' ');
	pipex->envp_args = envp;
	pipex->path_args = get_path_args(envp);
	pipex->cmd1_path = get_path(pipex->cmd1_args[0], pipex->path_args);
	pipex->cmd2_path = get_path(pipex->cmd2_args[0], pipex->path_args);
	return (pipex);
}

void	parent_process(t_pipex *pipex)
{
	int		status;
	int 	fd;

	waitpid(pipex->pid, &status, WNOHANG);
	close(pipex->pipe[PIPE_WRITE]);
	fd = dup2(pipex->pipe[PIPE_READ], STDIN_FILENO);
	if ( fd == -1)
	{
		perror("dup2 fail");
		exit(1);
	}
	fd = dup2(pipex->fd_outfile, STDOUT_FILENO);
	if (fd  == -1)
	{
		perror("dup2 fail");
		exit(1);
	}
	close(pipex->pipe[PIPE_READ]);
	close(pipex->fd_outfile);
	if (execve(pipex->cmd2_path, pipex->cmd2_args, pipex->envp_args) == -1)
	{
		perror("command not found");
		exit(127);
	}
}

void	child_process(t_pipex *pipex)
{
	int		fd;

	close(pipex->pipe[PIPE_READ]);
	fd = dup2(pipex->fd_infile, STDIN_FILENO);
	if (fd == -1)
	{
		perror("dup2 fail");
		exit(1);
	}
	fd = dup2(pipex->pipe[PIPE_WRITE], STDOUT_FILENO);
	if (fd == -1)
	{
		perror("dup2 fail");
		exit(1);
	}
	close(pipex->pipe[PIPE_WRITE]);
	close(pipex->fd_infile);
	if (execve(pipex->cmd1_path, pipex->cmd1_args, pipex->envp_args) == -1)
	{
		perror("command not found");
		exit(127);
	}
}

void	free_cmd(char **cmd)
{
	int	i;

	i = 0;
	while (cmd[i])
	{
		free(cmd[i]);
		i++;
	}
	free(cmd);
}

void	free_pipex(t_pipex *pipex)
{
	free_cmd(pipex->cmd1_args);
	free_cmd(pipex->cmd2_args);
	free(pipex);
}

void	error_handle(t_pipex *pipex)
{
	if (pipex->cmd1_args == NULL || pipex->cmd2_args == NULL)
	{
		perror("command not found");
		exit(127);
	}
	if (pipex->fd_infile == -1)
		perror("Error: cannot open file1");
	if (pipex->fd_outfile == -1)
	{
		perror("Error: cannot open file2");
		exit (1);
	}
	if (pipe(pipex->pipe) == -1)
	{
		perror("Error: cannot create pipe");
		exit (1);
	}
}

int	main(int argc, char *argv[], char *envp[])
{
	t_pipex	*pipex;

	if (argc != 5)
	{
		perror("usage: ./pipex file1 cmd1 cmd2 file2\n");
		exit (EXIT_FAILURE);
	}
	pipex = init_pipex(argv, envp);
	error_handle(pipex);
	pipex->pid = fork();
	if (pipex->pid == -1)
	{
		perror("Error: cannot create child process");
		exit (127);
	}
	if (pipex->pid == 0)
		child_process(pipex);
	else
		parent_process(pipex);
	free_pipex(pipex);
	return (0);
}
