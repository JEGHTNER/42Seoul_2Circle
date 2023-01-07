/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehelee <jehelee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 17:07:02 by jehelee           #+#    #+#             */
/*   Updated: 2023/01/07 19:05:38 by jehelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	ft_putchar_fd(char c, int file_descriptor)
{
	if (file_descriptor < 0)
		return ;
	write (file_descriptor, &c, 1);
}
