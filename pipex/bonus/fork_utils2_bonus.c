/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_utils2_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehelee <jehelee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 20:47:51 by jehelee           #+#    #+#             */
/*   Updated: 2023/03/04 13:38:55 by jehelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/include/pipex_bonus.h"

int	ft_w_exit_status(int status)
{
	int		ft_w_int_status;

	ft_w_int_status = ((*(int *)&(status)));
	return (ft_w_int_status >> 8 & 0x000000ff);
}

int	wait_func(t_list *pid_list)
{
	int		status;
	t_list	*tmp;

	tmp = pid_list->next;
	while (tmp)
	{
		waitpid(tmp->content, &status, 0);
		tmp = tmp->next;
	}
	ft_lstfree(pid_list);
	return (ft_w_exit_status(status));
}

int	check_heredoc(t_pipex *pipex)
{
	int	i;

	i = 1;
	if (pipex->here_doc_flag)
		i = 2;
	return (i);
}

void	first_child_heredoc(t_pipex *pipex, int ac, char **av)
{
	char	**cmd_args;
	char	*cmd_path;
	int		i;

	i = 3;
	here_doc(pipex->limiter);
	free(pipex->limiter);
	if (ac == 5)
	{
		cmd_args = ft_split_pipex(av[i], ' ');
		cmd_path = get_path(cmd_args[0], pipex->path_args);
		error_no_cmd_path(cmd_path, av, i);
		if (dup2(pipex->fd_outfile, STDOUT_FILENO) == -1)
		{
			perror("dup2");
			exit(1);
		}
		close(pipex->fd_outfile);
		if (execve(cmd_path, cmd_args, pipex->envp_args) == -1)
		{
			perror("execve_1cmd");
			exit(127);
		}
	}
}

void	first_child_infile(t_pipex *pipex, int *i)
{
	*i = 2;
	if (pipex->fd_infile == -1)
		exit(1);
	if (dup2(pipex->fd_infile, STDIN_FILENO) == -1)
	{
		perror("dup2");
		exit(1);
	}
	close(pipex->fd_infile);
}
