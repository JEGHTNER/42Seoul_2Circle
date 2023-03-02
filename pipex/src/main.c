/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehelee <jehelee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 14:23:29 by jehelee           #+#    #+#             */
/*   Updated: 2023/03/02 17:25:27 by jehelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/include/pipex.h"

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
	waitpid(pipex->pid, NULL, WNOHANG);
	free_pipex(pipex);
	return (0);
}
