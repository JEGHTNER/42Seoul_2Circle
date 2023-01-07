/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehelee <jehelee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 16:42:31 by jehelee           #+#    #+#             */
/*   Updated: 2023/01/02 19:27:18 by jehelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

t_list	*add_fd(int fd)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->file_descriptor = fd;
	new_node->read_buff = malloc((size_t)BUFFER_SIZE + 1);
	if (!(new_node->read_buff))
	{
		free (new_node);
		return (NULL);
	}
	new_node->backup = NULL;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

size_t	ft_strlen(const char *string)
{
	size_t	i;

	i = 0;
	if (!string)
		return (0);
	while (*string)
	{
		i++;
		string++;
	}
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (!src || !dst)
		return (0);
	if (size != 0)
	{
		while (src[i] && i + 1 < size)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}

char	*ft_strjoin(char const *string1, char const *string2)
{
	size_t	string1_len;
	size_t	string2_len;
	char	*tmp_string;

	string2_len = ft_strlen(string2);
	string1_len = ft_strlen(string1);
	tmp_string = malloc(sizeof(char) * (string1_len + string2_len) + 1);
	if (!tmp_string)
		return (0);
	ft_strlcpy(tmp_string, string1, string1_len + 1);
	ft_strlcpy(tmp_string + string1_len, string2, string2_len + 1);
	return (tmp_string);
}

char	*ft_strchr(const char *string, int c)
{
	char	*tmp;

	tmp = (char *)string;
	while (*tmp)
	{
		if (*tmp == (char)c)
			return (tmp);
		tmp++;
	}
	if ((char)c == '\0')
		return (tmp);
	return (0);
}
