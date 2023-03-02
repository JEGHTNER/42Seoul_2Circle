/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehelee <jehelee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 14:23:29 by jehelee           #+#    #+#             */
/*   Updated: 2023/03/02 21:04:21 by jehelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/include/pipex_bonus.h"

void	check_leaks(void)
{
	system("leaks pipex");
}

int	main(int argc, char *argv[], char *envp[])
{
	t_pipex	*pipex;
	int		status;
	t_list	*pid_list;

	pid_list = malloc(sizeof(t_list));
	if (argc < 5)
	{
		ft_putstr_fd("usage: ./pipex infile cmd1 cmd2 ... outfile\n", 2);
		exit (EXIT_FAILURE);
	}
	pipex = malloc(sizeof(t_pipex));
	if (!pipex)
		exit (EXIT_FAILURE);
	is_here_doc(pipex, argv[1]);
	init_pipex(pipex, argc, argv, envp);
	error_handle(pipex, argv, argc);
	multi_pipe(pipex, argc, argv, pid_list);
	status = wait_func(pid_list);
	free_pipex(pipex);
	return (status);
}

void	multi_pipe(t_pipex *pipex, int argc, char *argv[], t_list *pid_list)
{
	int		pipe_fd[2];
	int		i;

	if (pipex->here_doc_flag)
		i = 2;
	else
		i = 1;
	while (++i < argc - 1)
	{
		error_no_pipe(pipex);
		if (pipe(pipe_fd) == -1)
			perror(NULL);
		pipex->pid = fork();
		if (pipex->pid == -1)
			perror(NULL);
		else if (pipex->pid == 0)
		{
			if (i == 2 || (pipex->here_doc_flag && i == 3))
				first_child_process(pipex, argv);
			if (i == argc - 2)
				last_child_process(pipex, argv[i]);
			child_process(pipex, argv[i]);
		}
		else
		{
			ft_lstadd_back((&pid_list), ft_lstnew(pipex->pid));
			parent_process(pipex);
		}
	}
}
