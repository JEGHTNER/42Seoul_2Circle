/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehelee <jehelee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 16:12:09 by jehelee           #+#    #+#             */
/*   Updated: 2023/02/14 12:17:06 by jehelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/include/push_swap.h"

void	exit_with_error(char *str)
{
	ft_putstr_fd(str, 2);
	exit(EXIT_FAILURE);
}

void	parse_argv(int argc, char *argv[], t_ab *stacks)
{
	int	i;

	i = argc;
	while (--i >= 1)
	{
		if (!check_argv(argv[i], stacks->a))
			exit(EXIT_FAILURE);
	}
	if (!check_duplicate(stacks->a))
		exit(EXIT_FAILURE);
}

void	free_stacks(t_ab *stacks)
{
	t_list	*tmp;
	t_list	*del;

	tmp = stacks->a->top;
	free(stacks->b);
	while (tmp)
	{
		del = tmp;
		tmp = tmp->next;
		free(del);
	}
	free(stacks->a);
}

void	free_commands(t_ab *stacks)
{
	t_list	*tmp;
	t_list	*del;

	tmp = stacks->commands->head;
	while (tmp)
	{
		del = tmp;
		tmp = tmp->next;
		free(del->string);
		free(del);
	}
	free(stacks->commands);
}
