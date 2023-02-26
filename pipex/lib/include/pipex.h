/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehelee <jehelee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 20:16:51 by jehelee           #+#    #+#             */
/*   Updated: 2023/02/26 23:03:56 by jehelee          ###   ########.fr       */
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
/* libft, ft_printf, get_next_line */
# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"

//typedefs
typedef enum pipex_status
{
	PIPE_READ,
	PIPE_WRITE,
}	t_pipex_status;

typedef enum awk
{
	NO_AWK,
	AWK,
}	t_awk;

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

//init_pipex functions
char		**get_path_args(char *envp[]);
int			check_sh(char *cmd);
char		*get_path(char *cmd, char **path_args);
void		init_pipex(t_pipex *pipex, char **argv, char *envp[]);

//ft_split_pipex function
size_t		ft_strlcpy_pipex(char *dst, const char *src, size_t dstsize);
size_t		ft_strlcpy_quote(char *dst, const char *src, size_t *i, size_t *j);
void		ft_strlcpy_quote_check(const char *s, size_t *i, char q, int *q_f);
char		**ft_split_pipex(char const *string, char seperator);
char		**ft_split_norm(char const *string, char seperator);
int			check_string(char const *string);
int			check_awk(char const *string);
char		*make_awk(const char *string, int *i);
char		**case_awk(const char *string);
char		*quote_line(char const *string, int i, int str_len, char quote);
char		*make_quote_line(char const *string);
char		**case_sh(const char *string);
int			check_sep(char c, char sep);
int			count_words(char const *string, char seperator);
int			skip_quoted_string(char const *string, int i);
int			find_len(char const *string, int len, char seperator);
char		*make_string(char const *string, char seperator, int *i);

//fork function
void		parent_process(t_pipex *pipex);
void		child_process(t_pipex *pipex);

//error_utils
void		error_handle(t_pipex *pipex, char *argv[]);
void		error_no_cmd(t_pipex *pipex);
void		error_no_cmd1_path(t_pipex *pipex, char *argv[]);
void		error_no_cmd2_path(t_pipex *pipex, char *argv[]);
void		error_no_infile(t_pipex *pipex, char *argv[]);
void		error_no_pipe(t_pipex *pipex);
void		error_no_outfile(t_pipex *pipex, char *argv[]);

//free functions
void		free_pipex(t_pipex *pipex);
char		**free_2d_arr(char **words);



#endif