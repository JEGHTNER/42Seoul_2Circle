/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehelee <jehelee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 14:23:29 by jehelee           #+#    #+#             */
/*   Updated: 2023/02/26 01:24:39 by jehelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/types.h>

char	**get_path_args(char *envp[])
{
	int		i;
	char	*path;
	char	*new_envp;

	if (!envp || !envp[0])
	{
		new_envp = "PATH=/usr/local/bin:/usr/bin:/bin";
		if (ft_strncmp(new_envp, "PATH=", 5) == 0)
		{
			path = new_envp + 5;
			return (ft_split(path, ':'));
		}
	}
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

int	check_sh(char *cmd)
{
	int		cmd_len;
	int		i;
	char	*tmp;

	cmd_len = ft_strlen(cmd);
	i = -1;
	while (++i < 3)
		cmd_len--;
	cmd = cmd + cmd_len;
	if (ft_strncmp(cmd, ".sh", 3) == 0)
		return (1);
	return (0);
}

char	*get_path(char *cmd, char **path_args)
{
	int		i;
	char	*tmp;
	char	*tmp2;

	if (!cmd || !path_args)
		return (NULL);
	if (access(cmd, X_OK) == 0)
		return (ft_strdup(cmd));
	i = 0;
	while (path_args[i])
	{
		if (check_sh(cmd))
			return (ft_strdup("/bin/sh"));
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

void	*init_pipex(t_pipex *pipex, char **argv, char *envp[])
{
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
	free_2d_arr(pipex->cmd1_args);
	free_2d_arr(pipex->cmd2_args);
	free_2d_arr(pipex->path_args);
	free(pipex->cmd1_path);
	free(pipex->cmd2_path);
	free(pipex);
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

void	error_no_outfile(t_pipex *pipex, char *argv[])
{
	// if (pipex->fd_outfile == -1)
	// 	perror("pipex: ");
	
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

void	error_handle(t_pipex *pipex, char *argv[])
{
	error_no_infile(pipex, argv);
	error_no_outfile(pipex, argv);
	error_no_cmd(pipex);
	error_no_cmd1_path(pipex, argv);
	error_no_cmd2_path(pipex, argv);
	error_no_pipe(pipex);
}

int	main(int argc, char *argv[], char *envp[])
{
	t_pipex	*pipex;

	pipex = malloc(sizeof(t_pipex));
	if (!pipex)
		exit (EXIT_FAILURE);
	if (argc != 5)
	{
		perror("usage: ./pipex file1 cmd1 cmd2 file2\n");
		exit (EXIT_FAILURE);
	}
	init_pipex(pipex, argv, envp);
	error_handle(pipex, argv);
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
