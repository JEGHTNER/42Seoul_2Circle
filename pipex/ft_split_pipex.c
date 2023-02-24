/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_pipex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehelee <jehelee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 14:24:19 by jehelee           #+#    #+#             */
/*   Updated: 2023/02/24 23:52:35 by jehelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include "pipex.h"

typedef enum e_quote
{
	NO_QUOTE,
	SINGLE_QUOTE,
	DOUBLE_QUOTE,
}	t_quote;

typedef enum awk
{
	NO_AWK,
	AWK,
}	t_awk;

size_t	ft_strlcpy_pipex_quote(char *dst, const char *src, size_t *i, size_t *j);
int	skip_quoted_string(char const *string, int i);

// size_t ft_strlen(const char *s)
// {
// 	size_t	i;

// 	i = 0;
// 	while (s[i])
// 		i++;
// 	return (i);
// }

// int	check_sh(char *cmd)
// {
// 	int		cmd_len;
// 	int		i;
// 	char	*tmp;

// 	cmd_len = ft_strlen(cmd);
// 	i = -1;
// 	while (++i < 3)
// 		cmd_len--;
// 	cmd = cmd + cmd_len;
// 	if (ft_strncmp(cmd, ".sh", 3) == 0)
// 		return (1);
// 	return (0);
// }

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

size_t	ft_strlcpy_pipex_quote(char *dst, const char *src, size_t *i, size_t *j)
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


char	**free_all(char **words)
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

int	check_awk(char const *string)
{
	int	i;
	int	str_len;

	if (!string)
		return (0);
	i = 0;
	while (ft_isspace(string[i]))
		i++;
	while (string[i] && i < ft_strlen(string) - 3)
	{
		if (string[i] == 'a' && string[i + 1] == 'w' && string[i + 2] == 'k')
			return (AWK);
		i++;
	}
	return (NO_AWK);
}

int check_string(char const *string)
{
	if (!check_awk(string))
		return (NO_AWK);
	return (AWK);
}

char	*quote_line(char const *string, int i, int str_len, char quote)
{
	char	*line;
	int		j;

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
	char	*line;

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

char	*make_awk(const char *string, int *i)
{
	char	*line;

	while (string[(*i)] && (*i) < ft_strlen(string) - 3)
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

char	**case_awk(const char *string)
{
	char	**words;
	int		i;

	words = malloc(sizeof(char *) * 3);
	if (!words)
		return (0);
	i = 0;
	while (ft_isspace(string[i]))
		i++;
	words[0] = make_awk(string, &i);
	if (!words[0])
		return (free_all(words));
	words[1] = make_quote_line(&string[i]);
	if (!words[1])
		return (free_all(words));
	words[2] = 0;
	return (words);
}

char	**case_sh(const char *string)
{
	char	**words;
	int		i;

	words = malloc(sizeof(char *) * 3);
	if (!words)
		return (0);
	i = 0;
	while (ft_isspace(string[i]))
		i++;
	while (string[i] && i < ft_strlen(string) - 2)
	{
		if (string[i] == '.' && string[i + 1] == 's' && string[i + 2] == 'h')
		{
			words[0] = ft_strdup("sh");
			if (!words[0])
				return (free_all(words));
			break ;
		}
		i++;
	}
	words[1] = ft_strdup(string);
	if (!words[1])
		return (free_all(words));
	words[2] = 0;
	return (words);
}

char **ft_split_norm(char const *string, char seperator)
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
		return (case_sh(string));
	return (ft_split_norm(string, seperator));
}

// int main()
// {
// 	// char *str = "awk \"\"'{count++} END {print count}'\"\"";
// 	// char *str = "awk '{count++} END {print count}'";
// 	// char *str = "awk \"{count++} END {print count}'\"";
// 	// char *str = "awk \"''{count++} END {print count}''\"";
// 	// char *str = "awk \'\"{count++} END {print count}\"\'";
// 	// char *str = "awk \"\'{count++} END {print count}\'\"";
// 	// char *str = "awk \'\"\'\"\'{count++} END {printf \"count: %i\", count}\'\"\'\"\'";
// 	// char *str = "awk \"{count++} END {printf \\\"count: %i\\\" , count}\"";


// 	char *str = "wc -l";

// 	char **result = ft_split_pipex(str, ' ');
// 	int i = 0;
// 	while (result[i])
// 	{
// 		printf("%s\n", result[i]);
// 		i++;
// 	}
// 	free_all(result);
// }

// int main(int argc, char *argv[], char *envp[])
// {
// 	int	oldstdout;
// 	int	oldstdin;
// 	int	fd1;
// 	int	fd2;
// 	char	buf[1024];

// 	// fd1 = open("./infile",O_RDONLY);
//     // if (fd1 == -1)
//     // {
//     // 	printf("Error\n");
//     //     return (1);
//     // }
// 	// fd2 = open("./outfile", O_WRONLY | O_CREAT | O_TRUNC, 00644);
//     // if (fd2 == -1)
//     // {
//     // 	printf("Error\n");
//     //     return (1);
//     // }
// 	// char *args[] = {"usr/bin/awk", "{count++}", "END", "{print count}", NULL}; 
// 	// dup2(fd1, 0);
// 	// close(fd1);	
// 	// // dup2(fd2, 1);
//     // // close(fd2);
// 	// execve("usr/bin/awk", args, NULL);
// 	// char *str = "wc \\\\ -l";
// 	char *str = "awk \"{count++} END {printf \\\"count: %i\\\" , count}\"";
// 	char **args2 = ft_split_pipex(str, ' ');
// 	//print args2
// 	int i = 0;
// 	while (args2[i])
// 	{
// 		printf("%s\n", args2[i]);
// 		i++;
// 	}
// 	fd1 = open("./infile.txt", O_RDONLY);
// 	dup2(fd1, STDIN_FILENO);
// 	// char *args[] = {"grep Hello", "ls -l", NULL};
// 	// execve("/usr/bin/grep", args, envp);
// 	//  char *args2[] = {"awk", "{count++} END {printf \"count: %i\", count}", NULL}; 
// 	// char *args2[] = {"sh", "no_x_script.sh", NULL};
// 	// char *str = "./script\"quote.sh";
	
// 	execve("/usr/bin/awk", args2, envp);
// 	// execve("/usr/bin/wc", args2, envp);
// 	return (0);
// }
