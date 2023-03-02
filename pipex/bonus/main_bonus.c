/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehelee <jehelee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 14:23:29 by jehelee           #+#    #+#             */
/*   Updated: 2023/03/02 20:31:03 by jehelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/include/pipex_bonus.h"

void	check_leaks(void)
{
	system("leaks pipex");
}

int	main(int argc, char *argv[], char *envp[])
{
	// atexit(check_leaks);
	t_pipex	*pipex;
	int		i;
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
	i = is_here_doc(pipex, argv[1]);
	init_pipex(pipex, argc, argv, envp);
	error_handle(pipex, argv, argc);
	while (++i < argc - 1)
	{
		error_no_pipe(pipex);
		if (pipe(pipex->pipe) == -1)
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
	status = wait_func(pid_list);
	free_pipex(pipex);
	return (status);
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
	return ((((*(int *)&(status)) >> 8) & 0x000000ff));
}
