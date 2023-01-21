/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehelee <jehelee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 23:36:20 by jehelee           #+#    #+#             */
/*   Updated: 2023/01/21 15:40:11 by jehelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./lib/include/so_long.h"

int print_err(t_map *map)
{
    char    *errors[6];

    errors[1] = "NO_COLLECTIBLE";
    errors[2] = "LINE_ERROR";
    errors[3] = "EXIT_ERROR";
    errors[4] = "PLAYER_ERROR";
    errors[5] = "NO_PATH";
    return (ft_printf("Error\n%s\n",errors[map->map_error]));
}