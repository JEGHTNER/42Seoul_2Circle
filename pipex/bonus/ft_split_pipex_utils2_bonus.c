/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_pipex_utils2_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehelee <jehelee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 18:19:24 by jehelee           #+#    #+#             */
/*   Updated: 2023/03/04 13:39:08 by jehelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../lib/include/pipex_bonus.h"

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
		return (free_2d_arr(words));
	words[1] = make_quote_line(&string[i]);
	if (!words[1])
		return (free_2d_arr(words));
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
	while (string[i] && i < (int)ft_strlen(string) - 2)
	{
		if (string[i] == '.' && string[i + 1] == 's' && string[i + 2] == 'h')
		{
			words[0] = ft_strdup("sh");
			if (!words[0])
				return (free_2d_arr(words));
			break ;
		}
		i++;
	}
	words[1] = ft_strdup(string);
	if (!words[1])
		return (free_2d_arr(words));
	words[2] = 0;
	return (words);
}
