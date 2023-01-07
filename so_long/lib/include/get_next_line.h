/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehelee <jehelee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 16:42:28 by jehelee           #+#    #+#             */
/*   Updated: 2023/01/02 19:27:35 by jehelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

typedef struct s_list
{
	int				file_descriptor;
	char			*backup;
	char			*read_buff;
	struct s_list	*next;
	struct s_list	*prev;
}t_list;

t_list	*add_fd(int fd);
t_list	*find_fd(t_list **head, int fd);
char	*get_next_line(int fd);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *string);
char	*ft_strjoin(char const *string1, char const *string2);
char	*ft_strchr(const char *string, int c);
char	*remove_fd(t_list *current_fd, t_list **head);
char	*split_line(t_list *current_fd, t_list **head);
char	*read_line(int fd, t_list *cur_fd, t_list **head, ssize_t read_size);

#endif