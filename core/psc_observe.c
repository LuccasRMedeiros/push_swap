/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psc_observe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 16:04:59 by lrocigno          #+#    #+#             */
/*   Updated: 2021/11/30 20:18:10 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap_core.h>

/*
** Check if each item on the stack is greater than the next one.
*/

static int	observe_stack_b(t_prog *prog)
{
	t_dlist	*stack;
	t_dlist	*tail;
	int		imp;

	stack = prog->stack_b;
	if (!stack->content)
		return (0);
	tail = stack->prev;
	imp = prog->stack_size;
	while (stack != tail)
	{
		if (*(int *)stack->content > *(int *)stack->next->content)
			--imp;
		else
			imp = prog->stack_size;
		stack = stack->next;
	}
	if (*(int *)stack->content < *(int *)stack->next->content)
		--imp;
	return (imp);
}

/*
** Check if each item on the stack is lower than the next one.
*/

static int	observe_stack_a(t_prog *prog)
{
	t_dlist	*stack;
	t_dlist	*tail;
	int		imp;

	stack = prog->stack_a;
	if (!stack->content)
		return (0);
	tail = stack->prev;
	imp = prog->stack_size;
	while (stack != tail)
	{
		if (*(int *)stack->content < *(int *)stack->next->content)
			--imp;
		else
			imp = prog->stack_size;
		stack = stack->next;
	}
	if (*(int *)stack->content > *(int *)stack->next->content)
		--imp;
	else
		imp = prog->stack_size;
	return (imp);
}

/*
** Look to a stack from up to down and the reverse way, in the end it returns a
** notation telling how much imperfections there are in the stacks.
**
** The imperfection is a pair of disordend values and the objective of a
** notation is to tell in which direction there are more imperfections. To do
** this the function read all the items of the stack, for each item that is in a
** expected order (for stack A is low value above a greater one, and in stack B
** is a great value above a lower one), a counter that start with the size of
** the stack it is reading decrease by one, when it find a imperfection its
** value resets.
**
** In the end, it return a notation.
*/

void psc_observe(t_prog *prog, int obs[2])
{
	obs[stk_a] = observe_stack_a(prog);
	obs[stk_b] = observe_stack_b(prog);
}
