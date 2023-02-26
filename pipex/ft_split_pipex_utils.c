/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_pipex_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehelee <jehelee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 17:54:33 by jehelee           #+#    #+#             */
/*   Updated: 2023/02/26 18:28:46 by jehelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	check_sep(char c, char sep)
{
	if (c == sep)
		return (1);
	return (0);
}

int	count_words(char const *string, char seperator)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (string[i])
	{
		while (string[i] && check_sep(string[i], seperator))
			i++;
		if (string[i])
		{
			count++;
			i = skip_quoted_string(string, i);
		}
		while (string[i] && !check_sep(string[i], seperator))
			i++;
	}
	return (count);
}

int	skip_quoted_string(char const *string, int i)
{
	int		quote_flag;
	char	quote;

	quote_flag = 0;
	if (string[i] == '\'' || string[i] == '\"')
	{
		quote = string[i];
		quote_flag = 1;
		while (string[i] && quote_flag)
		{
			if (string[i] == quote)
				quote_flag = 0;
			i++;
		}
	}
	return (i);
}

int	find_len(char const *string, int len, char seperator)
{
	while (string[len])
	{
		if (string[len] == '\'' || string[len] == '\"')
		{
			len++;
			while (string[len] && string[len] != string[0])
				len++;
			if (string[len])
				len++;
		}
		else
			break ;
	}
	while (string[len] && string[len] != seperator)
		len++;
	return (len);
}

char	*make_string(char const *string, char seperator, int *i)
{
	char	*tmp_string;
	int		len;
	int		tmp_len;

	len = 0;
	len = find_len(string, len, seperator);
	tmp_string = malloc(sizeof(char) * len + 1);
	if (!tmp_string)
		return (0);
	tmp_len = ft_strlcpy_pipex(tmp_string, string, len + 1);
	if (tmp_len > len)
		(*i) += tmp_len;
	else
		(*i) += len;
	return (tmp_string);
}
