/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehelee <jehelee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 20:16:51 by jehelee           #+#    #+#             */
/*   Updated: 2023/02/01 16:07:58 by jehelee          ###   ########.fr       */
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
    int     both_flag;
    char    name;
}               t_stack;

typedef struct s_ab
{
    t_stack *a;
    t_stack *b;
}               t_ab;

void    init_stack(t_stack *stack, char name);
void    ft_stack_push(t_stack *stack, t_list *n);
void    ft_stack_pop(t_stack *stack);
int     check_overflow(long long result);
int     check_duplicate(t_stack *stack);
int     check_argv(char *argv, t_stack *a);
void    swap(t_stack *stack);
void    push(t_stack *stack_to, t_stack *stack_from);
void    a_to_b(t_ab *stacks, int count);
void	b_to_a(t_ab *stacks, int count);
void    rotate(t_stack *stack);
void	reverse_rotate(t_stack *stack);
void    sort_2(t_stack *stack);
void	check_case_3(t_stack	*stack, int max, int min);
void    sort_3(t_stack *stack);
int	    get_max(t_stack *stack, int count);
int	    get_min(t_stack *stack);
void	sort_5_ab(t_ab *stacks);
void	sort_5_ba(t_ab *stacks);
int     get_max(t_stack *stack, int count);
int     get_min(t_stack *stack);
int     get_pivot(t_stack *stack);
int 	check_space_sign(char **argv, int *sign);
void	check_recur(char **argv, t_stack *a);
void	exit_with_error(char *str);
void    pa(t_ab *stacks);
void    pb(t_ab *stacks);
void    rra(t_ab *stacks);
void    rrb(t_ab *stacks);
void    rrr(t_ab *stacks);
void    ra(t_ab *stacks);
void    rb(t_ab *stacks);
void    rr(t_ab *stacks);
void    sa(t_ab *stacks);
void    sb(t_ab *stacks);
void    ss(t_ab *stacks);

#endif