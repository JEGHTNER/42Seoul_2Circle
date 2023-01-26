/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_util_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehelee <jehelee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 21:40:41 by jehelee           #+#    #+#             */
/*   Updated: 2023/01/26 21:40:50 by jehelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./lib/include/push_swap.h"

void    pa(t_ab *stacks)
{
    push(stacks->a, stacks->b);
    ft_printf("pa\n");
}

void    pb(t_ab *stacks)
{
    push(stacks->b, stacks->a);
    ft_printf("pb\n");
}