/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_pipex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehelee <jehelee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 14:24:19 by jehelee           #+#    #+#             */
/*   Updated: 2023/02/20 23:29:18 by jehelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

size_t	ft_strlcpy_pipex_quote(char *dst, const char *src, size_t *i, size_t *j);
static int	skip_quoted_string(char const *string, int i);

size_t ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

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
			ft_strlcpy_pipex_quote(dst, src, &i, &j);
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

size_t	ft_strlcpy_pipex_quote(char *dst, const char *src, size_t *i, size_t *j)
{
	char	quote;
	int		quote_flag;
	int		k;
	int		count;

	quote = src[*i];
	quote_flag = 0;
	(*i)++;
	k = *i;
	count = 0;
	while (src[k] && !quote_flag)
	{
		if (src[k] == quote)
			quote_flag = 1;
		k++;
		count++;
	}
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


static char	**free_all(char **words)
{
	int	i;

	i = 0;
	while (words[i])
	{
		free(words[i]);
		i++;
	}
	free(words);
	return (0);
}

static int	check_sep(char c, char sep)
{
	if (c == sep)
		return (1);
	return (0);
}

static int	count_words(char const *string, char seperator)
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

static int	skip_quoted_string(char const *string, int i)
{
	int	quote_flag;
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

static char	*make_string(char const *string, char seperator, int *i)
{
	char	*tmp_string;
	int		len;
	int		quote_flag;

	len = 0;
	quote_flag = 0;
	while (string[len])
	{
		if (string[len] == '\'' || string[len] == '\"')
		{
			quote_flag = 1;
			len++;
			while (string[len] && string[len] != string[0])
				len++;
			if (string[len])
				len++;
		}
		else
			break ;
	}
	if (!quote_flag)
	{
		while (string[len] && string[len] != seperator)
			len++;
		tmp_string = malloc(sizeof(char) * len + 1);
		if (!tmp_string)
			return (0);
		ft_strlcpy_pipex(tmp_string, string, len + 1);
		(*i) += len;
		return (tmp_string);
	}
	else
	{
		tmp_string = malloc(sizeof(char) * len + 1);
		if (!tmp_string)
			return (0);
		ft_strlcpy_pipex(tmp_string, string, len + 1);
		(*i) += len;
		return (tmp_string);
	}
}

char	**ft_split_pipex(char const *string, char seperator)
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
				return (free_all(words));
			j++;
		}
		// while (string[i] && check_sep(string[i], seperator) == 0)
		// 	i++;
	}
	words[j] = 0;
	return (words);
}


// int main()
// {
// 	// char *str = "awk \"\"'{count++} END {print count}'\"\"";
// 	// char *str = "awk '{count++} END {print count}'";
// 	// char *str = "awk \"{count++} END {print count}'\"";
// 	// char *str = "awk \"''{count++} END {print count}''\"";
// 	// char *str = "awk \'\"{count++} END {print count}\"\'";
// 	// char *str = "awk \"\'{count++} END {print count}\'\"";


// 	// char *str = "wc -l  a b c def g ";

// 	char **result = ft_split_pipex(str, ' ');
// 	int i = 0;
// 	while (result[i])
// 	{
// 		printf("%s\n", result[i]);
// 		i++;
// 	}
// }
