/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehelee <jehelee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 17:08:42 by jehelee           #+#    #+#             */
/*   Updated: 2023/03/03 18:17:06 by jehelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/include/pipex_bonus.h"

void	error_handle(t_pipex *pipex, char *argv[], int argc)
{
	error_no_infile(pipex, argv);
	error_no_outfile(pipex, argv, argc);
}

void	error_no_cmd(char **cmd_args, char *argv_i)
{
	if (cmd_args == NULL)
	{
		ft_putstr_fd("pipex: ", 2);
		ft_putstr_fd(argv_i, 2);
		ft_putstr_fd(": command not found\n", 2);
	}
}

void	error_no_cmd_path(char *cmd_path, char *argv[], int i)
{
	if (cmd_path == NULL)
	{
		ft_putstr_fd("pipex: ", 2);
		ft_putstr_fd(argv[i], 2);
		ft_putstr_fd(": command not found\n", 2);
		exit(127);
	}
}

void	error_no_infile(t_pipex *pipex, char *argv[])
{
	if (pipex->here_doc_flag)
		return ;
	if (pipex->fd_infile == -1)
	{
		ft_putstr_fd("pipex: ", 2);
		ft_putstr_fd(argv[1], 2);
		ft_putstr_fd(": ", 2);
		perror(NULL);
	}
}

void	error_no_outfile(t_pipex *pipex, char *argv[], int argc)
{
	if (pipex->fd_outfile == -1)
	{
		ft_putstr_fd("pipex: ", 2);
		ft_putstr_fd(argv[argc - 1], 2);
		ft_putstr_fd(": ", 2);
		perror(NULL);
	}
}
