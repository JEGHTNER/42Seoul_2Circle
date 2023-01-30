/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehelee <jehelee@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 20:46:07 by jehelee           #+#    #+#             */
/*   Updated: 2023/01/30 22:20:18 by jehelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"./lib/include/push_swap.h"

void    init_stack(t_stack *stack, char name)
{
    stack->bottom = NULL;
    stack->top = NULL;
    stack->size = 0;
    stack->name = name;  
    stack->both_flag = 0;
}

void	ft_stack_push(t_stack *stack, t_list *new)
{
	if (!new || !stack)
		return ;
    if (stack->size == 0)
        stack->bottom = new;
	new ->next = stack->top;
    if (stack->top)
        stack->top->prev = new;
	stack->top = new;
    stack->size++;
}

void    ft_stack_pop(t_stack *stack)
{
    t_list  *tmp;

    if (!stack)
        return ;
    tmp = stack->top;
    stack->top = stack->top->next;
    if (stack->top)
        stack->top->prev = NULL;
    free(tmp);
    stack->size--;
    if (stack->size == 0)
        stack->bottom = NULL;
}

int	check_overflow(long long result)
{
	if (result != 0 && (result * 10 <= result))
		return (1);
	else
		return (0);
}

int check_duplicate(t_stack *stack)
{
    int     num;
    int     sort_flag;
    t_list  *tmp;
    t_list  *tmp2;

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
            {
                ft_printf("num duplicate\n");
                return (0);
            }
            tmp2 = tmp2->next;
        }
        tmp = tmp->next;
    }
	if (sort_flag == stack->size)
		return (0);
    return (1);
}

int check_argv(char *argv, t_stack *a)
{
    int         i;
    int         sign;
    int         overflow;
    long long   lnum;

    sign = 1;
    i = 0;
    lnum = 0;
    overflow = 0;
    while (ft_isspace(*argv))
        argv++;
    if (!*argv)
        return (0);
    if (*argv == '-')
    {
        sign = -1;
        argv++;
        if (!*argv || ft_isspace(*argv))
        {
            ft_printf("non digit input\n");
            return (0);
        }
    }
    while (ft_isdigit(argv[i]))
    {
        overflow = check_overflow(lnum);
        lnum = lnum * 10 + (argv[i] - '0');
        overflow = check_overflow(lnum);
        i++;
    }
    if (lnum * sign > 2147483647 || lnum * sign < -2147483648 || overflow != 0)
    {
        ft_printf("Input range : -2147483648 ~ 2147483647");
        return(0);
    }
    while (*argv)
    {
        if (!ft_isdigit(*argv))
        {
            if (ft_isspace(*argv))
            {
                check_argv(argv, a);
                break;
            }
            ft_printf("non digit input\n");
            return(0);
        }
        argv++;
    }
    ft_stack_push(a, ft_lstnew(lnum * sign));
    return (1);
}

int main(int argc, char *argv[])
{
    t_ab    stacks;
    
    stacks.a = malloc(sizeof(t_stack));
    if (!stacks.a)
        return (0);
    init_stack(stacks.a, 'a');
    for(int i = argc - 1; i >= 1; i--)
    {
        if (!check_argv(argv[i],stacks.a))
            return (0);
    }
    if (!check_duplicate(stacks.a))
		return (ft_printf("ERROR:sorted"));
    stacks.b = malloc(sizeof(t_stack));
    if (!stacks.b)
        return (0);
    init_stack(stacks.b, 'b');
    a_to_b(&stacks, stacks.a->size);
    b_to_a(&stacks, stacks.b->size);
    //sort_3(stacks.a);
    //sort_5(&stacks);
    t_list  *tmp = stacks.a->top;
    t_list  *tmp2 = stacks.b->top;
    ft_printf("a= ");
    for(int i = 0; i < stacks.a->size; i++)
    {
        ft_printf("%d ",tmp->content);
        tmp = tmp->next;
    }
    ft_printf("\n");
    ft_printf("b= ");
    for(int i = 0; i < stacks.b->size; i++)
    {
        ft_printf("%d ",tmp2->content);
        tmp2 = tmp2->next;
    }
}