/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_util_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehelee <jehelee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 21:39:17 by jehelee           #+#    #+#             */
/*   Updated: 2023/01/26 21:39:47 by jehelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./lib/include/push_swap.h"

void    sa(t_ab *stacks)
{
    swap(stacks->a);
    ft_printf("sa\n");
}

void    sb(t_ab *stacks)
{
    swap(stacks->b);
    ft_printf("sb\n");
}

void    ss(t_ab *stacks)
{
    swap(stacks->a);
    swap(stacks->b);
    ft_printf("ss\n");
}