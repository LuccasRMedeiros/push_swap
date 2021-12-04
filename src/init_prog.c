/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_prog.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 13:49:03 by lrocigno          #+#    #+#             */
/*   Updated: 2021/12/01 21:57:11 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

/*
** Make each item of the stack compete with the others. Everytime one "champion"
** is beaten by a "challenger", this challenger becomes the new champion and it
** will compete with the rest of the items that weren't compared yet.
*/

static void	find_limits(int *pre_stack, int size, int limits[2])
{
	int		i;
	int		l_champion;
	int		g_champion;
	int		challenger;

	i = 1;
	l_champion = pre_stack[0];
	g_champion = l_champion;
	challenger = 0;
	while (i < size)
	{
		challenger = pre_stack[i];
		if (challenger < l_champion)
			l_champion = challenger;
		else if (challenger > g_champion)
			g_champion = challenger;
		++i;
	}
	limits[lower] = l_champion;
	limits[greater] = g_champion;
}

/*
** Place a empty list inside a stack and return it.
*/

static t_dlist	*set_stack_b(void)
{
	t_dlist	*stack_b;

	stack_b = ft_dlstnew(NULL);
	if (!stack_b)
		return (NULL);
	stack_b = ft_dlstcircle(stack_b);
	return (stack_b);
}

/*
** Place a array of numbers inside a stack and return it.
*/

static t_dlist	*set_stack_a(int *items, int size)
{
	t_dlist	*stack_a;
	int		i;

	stack_a = ft_dlstnew(&items[0]);
	if (!stack_a)
		return (NULL);
	i = 1;
	while (i < size)
	{
		ft_dlstadd(&items[i], &stack_a);
		++i;
	}
	stack_a = ft_dlstcircle(stack_a);
	return (stack_a);
}

/*
** Create a stack called "stack_a" with the n items informed into the arguments,
** then create a empty stack called "stack_b".
**
** The prog structure hold the pre_stack (which is created to test the 
** arguments) to clean it in the end of the progra	.
*/

t_prog	*init_prog(int *pre_stack, int size)
{
	t_prog	*prog;

	prog = malloc(sizeof(*prog));
	if (!prog)
		return (NULL);
	prog->pre_stack = pre_stack;
	find_limits(pre_stack, size, prog->limits);
	prog->stack_a = set_stack_a(pre_stack, size);
	if (!prog->stack_a)
	{
		free(prog);
		return (NULL);
	}
	prog->a_size = size;
	prog->stack_b = set_stack_b();
	if (!prog->stack_b)
	{
		ft_dlstclear_circle(&prog->stack_a, del_item);
		free(prog);
		return (NULL);
	}
	prog->b_size = 0;
	return (prog);
}
