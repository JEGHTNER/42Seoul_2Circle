/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_util_reverse_rotate.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehelee <jehelee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 21:38:29 by jehelee           #+#    #+#             */
/*   Updated: 2023/01/26 21:38:55 by jehelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./lib/include/push_swap.h"

void    rra(t_ab *stacks)
{
    reverse_rotate(stacks->a);
    ft_printf("ra\n");
}

void    rrb(t_ab *stacks)
{
    reverse_rotate(stacks->b);
    ft_printf("rb\n");
}

void    rrr(t_ab *stacks)
{
    reverse_rotate(stacks->a);
    reverse_rotate(stacks->b);
    ft_printf("rr\n");
}
