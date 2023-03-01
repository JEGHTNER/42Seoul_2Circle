/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pipex_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehelee <jehelee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 17:04:31 by jehelee           #+#    #+#             */
/*   Updated: 2023/03/02 00:55:03 by jehelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/include/pipex_bonus.h"

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

void	init_pipex(t_pipex *pipex, int argc, char **argv, char *envp[])
{
	pipex->fd_infile = open(argv[1], O_RDONLY);
	if (pipex->here_doc_flag)
		pipex->fd_outfile = open(argv[argc - 1], \
		O_WRONLY | O_CREAT | O_APPEND, 0644);
	else
		pipex->fd_outfile = open(argv[argc - 1], \
		O_WRONLY | O_CREAT | O_TRUNC, 0644);
	pipex->envp_args = envp;
	pipex->path_args = get_path_args(envp);
	if (pipex->here_doc_flag)
	{
		pipex->limiter = ft_strjoin(argv[2], "\n");
		if (!pipex->limiter)
			exit(1);
	}
	else
		pipex->limiter = NULL;
}
