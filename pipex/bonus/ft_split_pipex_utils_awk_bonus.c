/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_pipex_utils_awk_bonus.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehelee <jehelee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 18:26:45 by jehelee           #+#    #+#             */
/*   Updated: 2023/03/01 20:07:10 by jehelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/include/pipex.h"

int	check_awk(char const *string)
{
	int	i;

	if (!string)
		return (0);
	i = 0;
	while (ft_isspace(string[i]))
		i++;
	while (string[i] && i < (int)ft_strlen(string) - 3)
	{
		if (string[i] == 'a' && string[i + 1] == 'w' && string[i + 2] == 'k')
			return (AWK);
		i++;
	}
	return (NO_AWK);
}

int	check_string(char const *string)
{
	if (!check_awk(string))
		return (NO_AWK);
	return (AWK);
}

char	*make_awk(const char *string, int *i)
{
	char	*line;

	line = NULL;
	while (string[(*i)] && (*i) < (int)ft_strlen(string) - 3)
	{
		if (string[(*i)] == 'a' && string[(*i) + 1] == 'w' \
		&& string[(*i) + 2] == 'k')
		{
			line = ft_strdup("awk");
			if (!line)
				return (NULL);
			(*i) += 3;
			break ;
		}
		(*i)++;
	}
	return (line);
}

char	*quote_line(char const *string, int i, int str_len, char quote)
{
	char	*line;

	while (str_len > 0 && str_len > i)
	{
		if (string[str_len] == quote)
			break ;
		str_len--;
	}
	if (!quote)
	{
		i = 0;
		str_len = ft_strlen(string);
	}
	line = ft_substr(string, i + 1, str_len - i - 1);
	if (!line)
		return (NULL);
	return (line);
}

char	*make_quote_line(char const *string)
{
	int		i;
	int		str_len;
	char	quote;

	str_len = ft_strlen(string) - 1;
	i = 0;
	quote = 0;
	while (string[i])
	{
		if (string[i] == '\'' || string[i] == '\"')
		{
			quote = string[i];
			break ;
		}
		i++;
	}
	return (quote_line(string, i, str_len, quote));
}
