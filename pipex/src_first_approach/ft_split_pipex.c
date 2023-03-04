/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_pipex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehelee <jehelee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 14:24:19 by jehelee           #+#    #+#             */
/*   Updated: 2023/03/04 13:41:09 by jehelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/include/pipex.h"

size_t	ft_strlcpy_pipex(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (dstsize == 0)
		return (ft_strlen(src));
	while (src[i] && i < dstsize - 1)
	{
		if (src[i] == '\'' || src[i] == '\"')
			ft_strlcpy_quote(dst, src, &i, &j);
		else
		{
			dst[j] = src[i];
			i++;
			j++;
		}
	}
	dst[j] = '\0';
	return (j);
}

void	ft_strlcpy_quote_check(const char *src, size_t *i, char q, int *q_flag)
{
	int		k;

	*q_flag = 0;
	(*i)++;
	k = *i;
	while (src[k] && !*q_flag)
	{
		if (src[k] == q)
			*q_flag = 1;
		k++;
	}
}

size_t	ft_strlcpy_quote(char *dst, const char *src, size_t *i, size_t *j)
{
	char	quote;
	int		quote_flag;

	quote = src[*i];
	ft_strlcpy_quote_check(src, i, quote, &quote_flag);
	if (!quote_flag)
	{
		dst[*j] = quote;
		*j = *j + 1;
	}
	while (src[*i] && src[*i] != quote)
	{
		dst[*j] = src[*i];
		(*i)++;
		*j = *j + 1;
	}
	(*i)++;
	return (*i);
}

char	**ft_split_norm(char const *string, char seperator)
{
	int		i;
	int		j;
	char	**words;

	i = 0;
	j = 0;
	words = malloc(sizeof(char *) * (count_words(string, seperator) + 1));
	if (!words)
		return (0);
	while (string[i])
	{
		while (string[i] && check_sep(string[i], seperator))
			i++;
		if (string[i] && check_sep(string[i], seperator) == 0)
		{
			words[j] = make_string(&string[i], seperator, &i);
			if (!words[j])
				return (free_2d_arr(words));
			j++;
		}
		while (string[i] && check_sep(string[i], seperator) == 0)
			i++;
	}
	words[j] = 0;
	return (words);
}

char	**ft_split_pipex(char const *string, char seperator)
{
	if (check_string(string))
		return (case_awk(string));
	if (check_sh((char *)string))
	{
		if (access(string, X_OK == 0))
			return (case_sh(string));
	}
	return (ft_split_norm(string, seperator));
}
