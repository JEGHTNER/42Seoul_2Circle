/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehelee <jehelee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 18:06:49 by jehelee           #+#    #+#             */
/*   Updated: 2023/01/07 19:17:11 by jehelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	ft_putstr_fd(char *string, int file_descriptor)
{
	int	i;

	i = 0;
	if (file_descriptor < 0)
		return ;
	while (string[i])
	{
		ft_putchar_fd(string[i], file_descriptor);
		i++;
	}
}
