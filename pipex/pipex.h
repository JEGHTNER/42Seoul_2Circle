/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehelee <jehelee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 20:16:51 by jehelee           #+#    #+#             */
/*   Updated: 2023/02/26 00:23:56 by jehelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

/* to write, read, close, access, pipe, dup, dup2, execve, fork */
# include <unistd.h>
/* malloc, free, exit */
# include <stdlib.h>
/* open, unlink */
# include <fcntl.h>
/* waitpid, wait */
# include <sys/wait.h>
/*for perror*/
# include <stdio.h>
//libft, ft_printf, get_next_line
# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"

//typedefs
typedef enum pipex_status
{
	PIPE_READ,
	PIPE_WRITE,
}	t_pipex_status;

typedef struct s_pipex
{
	int		fd_infile;
	int		fd_outfile;
	int		pipe[2];
	char	**cmd1_args;
	char	**cmd2_args;
	char	**envp_args;
	char	**path_args;
	char	*cmd1_path;
	char	*cmd2_path;
	pid_t	pid;
}			t_pipex;

//ft_split_pipex function
size_t      ft_strlcpy_pipex(char *dst, const char *src, size_t dstsize);
size_t      ft_strlcpy_quote(char *dst, const char *src, size_t *i, size_t *j);
int         skip_quoted_string(char const *string, int i);
char	    **free_2d_arr(char **words);
int	        count_words(char const *string, char c);
int	        check_sep(char c, char sep);
int         skip_quoted_string(char const *string, int i);
char	    *make_string(char const *string, char seperator, int *i);
char	    **ft_split_pipex(char const *string, char seperator);
int         check_sh(char *cmd);


#endif