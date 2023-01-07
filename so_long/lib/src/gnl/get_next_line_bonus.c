/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehelee <jehelee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 16:40:17 by jehelee           #+#    #+#             */
/*   Updated: 2023/01/07 19:03:27 by jehelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/get_next_line_bonus.h"

t_list	*find_fd(t_list **head, int fd)
{
	t_list	*tmp;

	if (!(*head))
	{
		*head = add_fd(fd);
		if (!*head)
			return (NULL);
	}
	tmp = *head;
	while (tmp)
	{
		if (tmp->file_descriptor == fd)
			return (tmp);
		if (tmp->next == NULL)
		{
			tmp->next = add_fd(fd);
			if (!(tmp->next))
				return (NULL);
			tmp->next->prev = tmp;
		}
		tmp = tmp->next;
	}
	return (NULL);
}

char	*remove_fd(t_list *current_fd, t_list **head)
{
	if (!current_fd || !*head)
		return (NULL);
	if (current_fd->prev)
		current_fd->prev->next = current_fd->next;
	if (current_fd->next)
		current_fd->next->prev = current_fd->prev;
	if (current_fd == *head)
		*head = current_fd->next;
	free (current_fd->backup);
	current_fd->backup = NULL;
	free (current_fd->read_buff);
	current_fd->read_buff = NULL;
	free (current_fd);
	return (NULL);
}

char	*split_line(t_list *current_fd, t_list **head)
{
	char	*line;
	char	*tmp;

	line = NULL;
	if (!(current_fd->backup && *(current_fd->backup)))
		return (remove_fd(current_fd, head));
	tmp = ft_strchr(current_fd->backup, '\n');
	if (tmp)
	{	
		*tmp = '\0';
		line = ft_strjoin(current_fd->backup, "\n");
		if (!line)
			return (remove_fd(current_fd, head));
		ft_strlcpy(current_fd->backup, tmp + 1, ft_strlen(tmp + 1) + 1);
		return (line);
	}
	else
	{
		line = ft_strjoin(current_fd->backup, "");
		if (!line)
			return (remove_fd(current_fd, head));
		remove_fd(current_fd, head);
		return (line);
	}
}

char	*read_line(int fd, t_list *current_fd, t_list **head, ssize_t read_size)
{
	char			*line;
	char			*tmp;

	while (1)
	{
		read_size = read(fd, current_fd->read_buff, BUFFER_SIZE);
		if (read_size == 0)
		{
			line = split_line(current_fd, head);
			return (line);
		}
		if (read_size == -1)
			return (remove_fd(current_fd, head));
		current_fd->read_buff[read_size] = '\0';
		tmp = ft_strjoin(current_fd->backup, current_fd->read_buff);
		if (!tmp)
			return (remove_fd(current_fd, head));
		free(current_fd->backup);
		current_fd->backup = tmp;
		if (ft_strchr(current_fd->backup, '\n') != NULL)
		{
			line = split_line(current_fd, head);
			return (line);
		}
	}
}

char	*get_next_line(int fd)
{
	static t_list	*head;
	t_list			*current_fd;
	char			*line;
	ssize_t			read_size;

	line = NULL;
	read_size = 0;
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	current_fd = find_fd(&head, fd);
	if (!current_fd)
		return (NULL);
	line = read_line(fd, current_fd, &head, read_size);
	return (line);
}
