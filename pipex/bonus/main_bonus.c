/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehelee <jehelee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 14:23:29 by jehelee           #+#    #+#             */
/*   Updated: 2023/03/01 15:55:17 by jehelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/include/pipex_bonus.h"

int	main(int argc, char *argv[], char *envp[])
{
	t_pipex	*pipex;
	pid_t	pid;
	int		pipe_fd[2];
	int		i;

	pipex = malloc(sizeof(t_pipex));
	if (!pipex)
		exit (EXIT_FAILURE);
	init_pipex(pipex, argc, argv, envp);
	i = 1;
	while (++i < argc - 1)
	{
		if (pipe(pipex->pipe) == -1)
			perror(NULL);
		pipex->pid = fork();
		if (pipex->pid == -1)
			perror(NULL);
		else if (pipex->pid == 0)
		{
			if (i == 2)
				first_child_process(pipex, argc, argv[i]);
			else if (i == argc - 2)
				last_child_process(pipex, argc, argv[i]);
			else
				child_process(pipex, argc, argv[i]);
		}
		else
			parent_process(pipex, argc, argv[i]);
	}
	free_pipex(pipex);
	return (0);
}
