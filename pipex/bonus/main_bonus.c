/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehelee <jehelee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 14:23:29 by jehelee           #+#    #+#             */
/*   Updated: 2023/03/02 01:13:12 by jehelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/include/pipex_bonus.h"

int	main(int argc, char *argv[], char *envp[])
{
	t_pipex	*pipex;
	// pid_t	pid;
	// int		pipe_fd[2];
	int		i;

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
	while (++i < argc - 1)
	{
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
			parent_process(pipex);
	}
	while (wait(NULL) > 0)
		;
	free_pipex(pipex);
	return (0);
}
