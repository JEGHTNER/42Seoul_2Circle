/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehelee <jehelee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 20:46:07 by jehelee           #+#    #+#             */
/*   Updated: 2023/02/07 21:09:05 by jehelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./lib/include/push_swap.h"

void	del_cmd(t_list *del)
{
	t_list	*tmp1;
	t_list	*tmp2;

	tmp1 = del;
	tmp2 = del->next;
	del->prev->next = del->next->next;
	del->next->next->prev = del->prev;
	free(tmp1);
	free(tmp2);
}

void	trim_rrr(t_ab *stacks)
{
	t_list	*tmp;
	t_list	*del;
	int		del_count;

	del_count = 0;
	tmp = stacks->commands->head;
	while (tmp->next)
	{
		while (!ft_strncmp(tmp->string, "rra\n", 4) && \
		!ft_strncmp(tmp->next->string, "rrb\n", 4))
		{
			del = tmp;
			tmp = tmp->prev;
			del_cmd(del);
			del_count++;
		}
		while (del_count > 0)
		{
			cmd_push_at(stacks->commands, ft_lstnew_cmd("rrr\n"), tmp);
			del_count--;
		}
		tmp = tmp->next;
	}
}

void	trim_rr(t_ab *stacks)
{
	t_list	*tmp;
	t_list	*del;
	int		del_count;

	del_count = 0;
	tmp = stacks->commands->head;
	while (tmp->next)
	{
		while (!ft_strncmp(tmp->string, "ra\n", 3) && \
		!ft_strncmp(tmp->next->string, "rb\n", 3))
		{
			del = tmp;
			tmp = tmp->prev;
			del_cmd(del);
			del_count++;
		}
		while (del_count > 0)
		{
			cmd_push_at(stacks->commands, ft_lstnew_cmd("rr\n"), tmp);
			del_count--;
		}
		tmp = tmp->next;
	}
}
void	trim_rr_2(t_ab *stacks)
{
	t_list	*tmp;
	t_list	*del;
	int		del_count;

	del_count = 0;
	tmp = stacks->commands->head;
	while (tmp->next)
	{
		while (!ft_strncmp(tmp->string, "rb\n", 3) && \
		!ft_strncmp(tmp->next->string, "ra\n", 3))
		{
			del = tmp;
			tmp = tmp->prev;
			del_cmd(del);
			del_count++;
		}
		while (del_count > 0)
		{
			cmd_push_at(stacks->commands, ft_lstnew_cmd("rr\n"), tmp);
			del_count--;
		}
		tmp = tmp->next;
	}
}

void	trim_cmd(t_ab *stacks)
{
	t_list	*tmp;
	t_list	*del;
	//int		del_count;

	//del_count = 0;
	tmp = stacks->commands->head;
	while (tmp->next)
	{
		while (!ft_strncmp(tmp->string, "ra\n", 3) && \
		!ft_strncmp(tmp->next->string, "rra\n", 4))
		{
			del = tmp;
			tmp = tmp->prev;
			del_cmd(del);
		}
		while (!ft_strncmp(tmp->string, "rb\n", 3) && \
		!ft_strncmp(tmp->next->string, "rrb\n", 4))
		{
			del = tmp;
			tmp = tmp->prev;
			del_cmd(del);
		}
		while (!ft_strncmp(tmp->string, "ra\n", 3) && \
		!ft_strncmp(tmp->next->string, "rrr\n", 4))
		{
			del = tmp;
			tmp = tmp->prev;
			del_cmd(del);
			cmd_push_at(stacks->commands, ft_lstnew_cmd("rrb\n"), tmp);
		}
		while (!ft_strncmp(tmp->string, "rb\n", 3) && \
		!ft_strncmp(tmp->next->string, "rrr\n", 4))
		{
			del = tmp;
			tmp = tmp->prev;
			del_cmd(del);
			cmd_push_at(stacks->commands, ft_lstnew_cmd("rra\n"), tmp);
		}
		tmp = tmp->next;
	}
}

void	print_cmd(t_ab *stacks)
{
	t_list *tmp = stacks->commands->head;
	while (tmp)
	{
		ft_printf("%s", tmp->string);
		tmp = tmp->next;
	}
}

void	init_commands(t_ab *stacks)
{
	stacks->commands = malloc(sizeof(t_cmd_lst));
	if (!stacks->commands)
		return (0);
	stacks->commands->head = NULL;
	stacks->commands->tail = NULL;
	stacks->a = malloc(sizeof(t_stack));
	if (!stacks->a)
		return (0);
}

int main(int argc, char *argv[])
{
	t_ab		stacks;
	int			i;

	stacks.commands = malloc(sizeof(t_cmd_lst));
	if (!stacks.commands)
		return (0);
	stacks.commands->head = NULL;
	stacks.commands->tail = NULL;
	stacks.a = malloc(sizeof(t_stack));
	if (!stacks.a)
		return (0);
	init_stack(stacks.a, 'a');
	i = argc;
	while (--i >= 1)
	{
		if (!check_argv(argv[i], stacks.a))
			return (0);
	}
	if (!check_duplicate(stacks.a))
		return (ft_printf("ERROR:sorted"));
	make_index(stacks.a, stacks.a->size);
	stacks.b = malloc(sizeof(t_stack));
	if (!stacks.b)
		return (0);
	init_stack(stacks.b, 'b');
	a_to_b(&stacks, stacks.a->size);
	b_to_a(&stacks, stacks.b->size);

	for(int i = 0; i < 5; i++)
	{
		trim_rrr(&stacks);
		trim_cmd(&stacks);
		trim_rr_2(&stacks);
		trim_rr(&stacks);
	}
	print_cmd(&stacks);
	
	// t_list *tmp = stacks.a->top;
	// t_list *tmp2 = stacks.b->top;
	// ft_printf("a= ");
	// for (int i = 0; i < stacks.a->size; i++)
	// {
	// 	ft_printf("%d ", tmp->content);
	// 	tmp = tmp->next;
	// }
	// ft_printf("\n");
	// ft_printf("b= ");
	// for (int i = 0; i < stacks.b->size; i++)
	// {
	// 	ft_printf("%d ", tmp2->content);
	// 	tmp2 = tmp2->next;
	// }
}
