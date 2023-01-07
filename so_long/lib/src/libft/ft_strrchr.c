/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehelee <jehelee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:31:49 by jehelee           #+#    #+#             */
/*   Updated: 2023/01/07 19:05:38 by jehelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

char	*ft_strrchr(const char *string, int c)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = (char *)string;
	while (*tmp)
		tmp++;
	if ((char)c == '\0')
		return (tmp);
	while (tmp != string)
	{
		if (*tmp == (char)c)
			return (tmp);
		tmp--;
	}
	if (*tmp == (char)c)
		return (tmp);
	return (0);
}
