/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehelee <jehelee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:53:11 by jehelee           #+#    #+#             */
/*   Updated: 2023/02/11 14:18:06 by jehelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./lib/include/push_swap.h"

int	check_overflow(long long result)
{
	if (result != 0 && (result * 10 <= result))
		return (1);
	else
		return (0);
}

int	check_duplicate(t_stack *stack)
{
	int		num;
	int		sort_flag;
	t_list	*tmp;
	t_list	*tmp2;

	sort_flag = 0;
	num = 0;
	tmp = stack->top;
	while (tmp)
	{
		if (tmp->content >= num)
			sort_flag++;
		num = tmp->content;
		tmp2 = tmp->next;
		while (tmp2)
		{
			if (num == tmp2->content)
				exit_with_error("Error\nnum duplicate\n");
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
	if (sort_flag == stack->size)
		return (0);
	return (1);
}

int	check_space_sign(char **argv, int *sign)
{
	while (ft_isspace(**argv))
		(*argv)++;
	if (!(**argv))
		return (0);
	if (**argv == '-' || **argv == '+')
	{
		if (**argv == '-')
			*sign = -1;
		(*argv)++;
		if (!(**argv) || ft_isspace(**argv))
			exit_with_error("Error\nnon digit input\n");
	}
	return (1);
}

void	check_recur(char **argv, t_stack *a)
{
	while (**argv)
	{
		if (!ft_isdigit(**argv))
		{
			if (ft_isspace(**argv))
			{
				check_argv(*argv, a);
				break ;
			}
			exit_with_error("Error\nnon digit input\n");
		}
		(*argv)++;
	}
}

int	check_argv(char *argv, t_stack *a)
{
	int			i;
	int			sign;
	int			overflow;
	long long	lnum;

	sign = 1;
	i = 0;
	lnum = 0;
	overflow = 0;
	if (!check_space_sign(&argv, &sign))
		return (0);
	while (ft_isdigit(argv[i]))
	{
		overflow = check_overflow(lnum);
		lnum = lnum * 10 + (argv[i] - '0');
		overflow = check_overflow(lnum);
		i++;
	}
	if (lnum * sign > 2147483647 || lnum * sign < -2147483648 || overflow != 0)
		exit_with_error("Error\nInput range : -2147483648 ~ 2147483647");
	check_recur(&argv, a);
	ft_stack_push(a, ft_lstnew(lnum * sign));
	return (1);
}
