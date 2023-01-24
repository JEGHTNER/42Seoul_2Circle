/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehelee <jehelee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 20:16:51 by jehelee           #+#    #+#             */
/*   Updated: 2023/01/24 21:13:51 by jehelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "ft_printf.h"

typedef struct s_stack
{
    t_list  *top;
    t_list  *bottom;
    int     size;
}               t_stack;

typedef struct s_ab
{
    t_stack *a;
    t_stack *b;
}               t_ab;

void    init_stack(t_stack *stack);
void    ft_stack_push(t_stack *stack, t_list *n);
void    ft_stack_pop(t_stack *stack);
int     check_overflow(long long result);
int     check_duplicate(t_stack *stack);
int     check_argv(char *argv, t_stack *a);
void    swap(t_stack *stack);
void    push(t_stack *stack_to, t_stack *stack_from);
void    rotate(t_stack *stack);
void	reverse_rotate(t_stack *stack);
void    sort_2(t_stack *stack);
void	check_case_3(t_stack	*stack, int max, int mid, int min);
void    sort_3(t_stack *stack);
int	    get_max(t_stack *stack);
int	    get_min(t_stack *stack);
void	sort_5(t_ab *stacks);


#endif