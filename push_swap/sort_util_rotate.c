/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_util_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehelee <jehelee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 21:37:53 by jehelee           #+#    #+#             */
/*   Updated: 2023/01/26 21:38:07 by jehelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./lib/include/push_swap.h"

void    ra(t_ab *stacks)
{
    rotate(stacks->a);
    ft_printf("ra\n");
}

void    rb(t_ab *stacks)
{
    rotate(stacks->b);
    ft_printf("rb\n");
}

void    rr(t_ab *stacks)
{
    rotate(stacks->a);
    rotate(stacks->b);
    ft_printf("rr\n");
}