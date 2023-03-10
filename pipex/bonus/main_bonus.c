/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehelee <jehelee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 14:23:29 by jehelee           #+#    #+#             */
/*   Updated: 2023/03/05 13:18:52 by jehelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/include/pipex_bonus.h"

int	main(int argc, char *argv[], char *envp[])
{
	t_pipex	*pipex;
	int		status;
	t_list	*pid_list;

	pid_list = malloc(sizeof(t_list));
	pid_list->next = NULL;
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
