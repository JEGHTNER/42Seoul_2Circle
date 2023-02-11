/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehelee <jehelee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 15:52:39 by jehelee           #+#    #+#             */
/*   Updated: 2023/02/11 18:46:44 by jehelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"

typedef struct s_cmd_lst
{
	t_list	*head;
	t_list	*tail;
}				t_cmd_lst;

typedef struct s_stack
{
	t_list	*top;
	t_list	*bottom;
	int		size;
	int		both_flag;
	char	name;
}				t_stack;

typedef struct s_ab
{
	t_stack		*a;
	t_stack		*b;
	t_cmd_lst	*commands;
}				t_ab;

//bonus functions
void	do_cmd(char *line, t_ab *stacks);

//recursive functions
void	a_to_b(t_ab *stacks, int count);
void	b_to_a(t_ab *stacks, int count);

//error functions
void	parse_argv(int argc, char *argv[], t_ab *stacks);
void	exit_with_error(char *str);
void	check_recur(char **argv, t_stack *a);
int		check_space_sign(char **argv, int *sign);

//stack functions
void	init_stack(t_stack *stack, char name);
void	ft_stack_push(t_stack *stack, t_list *n);
void	ft_stack_pop(t_stack *stack);
void	free_stacks(t_ab *stacks);

//command functions
void	swap_bn(t_stack *stack);
void	push_bn(t_stack *stack_to, t_stack *stack_from);
void	rotate_bn(t_stack *stack);
void	reverse_rotate_bn(t_stack *stack);

//sort 5 under functions
void	sort_2(t_ab *stacks, t_stack *stack);
void	check_case_3_above(t_ab *stacks, t_stack *stack, int max, int min);
void	check_case_3(t_ab *stacks, t_stack *stack, int max, int min);
void	sort_3(t_ab *stacks, t_stack *stack);
void	sort_4_ab(t_ab *stacks);
void	sort_5_ab(t_ab *stacks);
void	sort_5_ab_above(t_ab *stacks);
void	sort_5_norm(t_ab *stacks, int ra_count);
void	case_3_1(t_ab *stacks, t_stack *stack);
void	case_3_2(t_ab *stacks, t_stack *stack);
void	case_3_3(t_ab *stacks, t_stack *stack);
void	case_3_4(t_ab *stacks, t_stack *stack);
void	rev_case_3_1(t_ab *stacks, t_stack *stack);
void	rev_case_3_2(t_ab *stacks);
void	rev_case_3_3(t_ab *stacks, t_stack *stack);
void	rev_case_3_4(t_ab *stacks, t_stack *stack);
void	rev_case_3_5(t_ab *stacks);
void	rev_case_3_6(t_ab *stacks, t_stack *stack);
void	rev_check_case_3(t_ab *stacks, t_stack *stack, int max, int min);
void	rev_sort_3(t_ab *stacks, t_stack *stack);
void	rev_sort_2(t_ab *stacks, t_stack *stack);
void	rev_sort_3(t_ab *stacks, t_stack *stack);
void	rev_sort_4_ba(t_ab *stacks);
void	rev_sort_5_ba(t_ab *stacks, int i);

//quick_sort functions
void	move_rev(t_ab *stacks, int count_arr[3], int count, int *pivots);
void	quick_sort_rev(t_ab *stacks, int count, int *pivots);
void	move(t_ab *stacks, int count_arr[3], int count, int *pivots);
void	quick_sort(t_ab *stacks, int count, int *pivots);
void	push_max(t_ab *stacks, t_stack *stack, int min);
void	push_max_min(t_ab *stacks, t_stack *stack, int max);
void	get_pivot(t_stack *stack, int size, int *big_pivot, int *small_pivot);
void	make_index(t_stack *stack, int size);
int		get_max(t_stack *stack, int count);
int		get_min(t_stack *stack, int count);

//checks
void	check_count_ab(t_ab *stacks, int count);
void	check_count_ba(t_ab *stacks, int count);
int		is_rev_sorted(t_stack *stack, int size);
int		is_sorted(t_stack *stack, int size);
int		check_overflow(long long result);
int		check_duplicate(t_stack *stack);
int		check_argv(char *argv, t_stack *a);

//command utils functions
void	init_commands(t_ab *stacks);
void	cmd_push_at(t_cmd_lst *commands, t_list *n, t_list *tmp);
void	cmd_push(t_cmd_lst *commands, t_list *n);
void	print_cmd(t_ab *stacks);
void	free_commands(t_ab *stacks);
t_list	*ft_lstnew_cmd(char *string);

// command trim functions
void	trim_cmd(t_ab *stacks);
void	print_cmd(t_ab *stacks);
void	trim_rbr(t_ab *stacks);
void	trim_rrr(t_ab *stacks);
void	trim_rrr_2(t_ab *stacks);
void	trim_rr(t_ab *stacks);
void	trim_rr_2(t_ab *stacks);
void	trim_rbr(t_ab *stacks);
void	trim_useless(t_ab *stacks);
void	del_cmd(t_list *del);

#endif