/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehelee <jehelee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 22:10:22 by jehelee           #+#    #+#             */
/*   Updated: 2023/03/04 01:27:32 by jehelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/include/pipex_bonus.h"

void	here_doc(char *limiter)
{
	int		fd;
	char	*line;

	fd = open("tmp_here_doc.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		perror("here_doc");
	while (1)
	{
		ft_putstr_fd("here_doc> ", STDOUT_FILENO);
		line = get_next_line(STDIN_FILENO);
		if (ft_strncmp(line, limiter, ft_strlen(limiter)) == 0)
		{
			free(line);
			break ;
		}
		ft_putstr_fd(line, fd);
		free(line);
	}
	close(fd);
	fd = open("tmp_here_doc.txt", O_RDONLY);
	if (fd == -1)
	{
		unlink("tmp_here_doc.txt");
		perror("here_doc");
	}
	dup2(fd, STDIN_FILENO);
	close(fd);
}

int	is_here_doc(t_pipex *pipex, char *argv_i)
{
	if (ft_strncmp(argv_i, "here_doc", 8) == 0 && ft_strlen(argv_i) == 8)
	{
		pipex->here_doc_flag = 1;
		return (2);
	}
	return (1);
}
