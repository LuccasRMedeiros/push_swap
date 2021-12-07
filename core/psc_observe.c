/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psc_observe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 16:04:59 by lrocigno          #+#    #+#             */
/*   Updated: 2021/12/06 17:20:01 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap_core.h>

/*
** Look from the top to the bottom and the reverse way for the first 
** imperfection it find on the stack_a.
*/

static void	observe_stack_b(t_prog *prog, int imps_b[2])
{
	t_dlist	*stack;
	int		pos;

	stack = prog->stack_b;
	pos = 1;
	while (pos <= prog->b_size && !imps_b[down])
	{
		if (*(int *)stack->content < *(int *)stack->next->content
				&& (*(int *)stack->content != prog->limits_b[lower]
				|| *(int *)stack->next->content != prog->limits_b[greater]))
			imps_b[down] = pos;
		stack = stack->next;
		++pos;
	}
	stack = prog->stack_b;
	pos = 1;
	while (pos <= prog->b_size && !imps_b[up])
	{
		if (*(int *)stack->content > *(int *)stack->prev->content
				&& (*(int *)stack->content != prog->limits_b[greater]
				|| *(int *)stack->prev->content != prog->limits_b[lower]))
			imps_b[up] = pos;
		stack = stack->prev;
		++pos;
	}
}

/*
** Look from the top to the bottom and the reverse way for the first 
** imperfection it find on the stack_a.
*/

static void	observe_stack_a(t_prog *prog, int imps_a[2])
{
	t_dlist	*stack;
	int		pos;

	stack = prog->stack_a;
	pos = 1;
	while (pos <= prog->a_size && !imps_a[down])
	{
		if (*(int *)stack->content > *(int *)stack->next->content
				&& (*(int *)stack->content != prog->limits_a[greater]
				|| *(int *)stack->next->content != prog->limits_a[lower]))
			imps_a[down] = pos;
		stack = stack->next;
		++pos;
	}
	stack = prog->stack_a;
	pos = 1;
	while (pos <= prog->a_size && !imps_a[up])
	{
		if (*(int *)stack->content < *(int *)stack->prev->content
				&& (*(int *)stack->content != prog->limits_a[lower]
				|| *(int *)stack->prev->content != prog->limits_a[greater]))
			imps_a[up] = pos;
		stack = stack->prev;
		++pos;
	}
}

/*
** Look for imperfections on stacks A and B.
**
** The imperfection is a pair of disordend values and the objective of a
** observation is to tell in which direction is the nearest imperfection. To do
** this the function read all the items of the stack, for each item that is in a
** expected order (for stack A is low value above a greater one, and in stack B
** is a great value above a lower one), the observer will go to the next item,
** when a imperfection is found it anotate the position of that.
*/

void psc_observe(t_prog *prog, int obs[2][2])
{
	obs[stk_a][down] = 0;
	obs[stk_a][up] = 0;
	obs[stk_b][down] = 0;
	obs[stk_b][up] = 0;
	if (prog->a_size > 2)
		observe_stack_a(prog, obs[stk_a]);
	if (prog->b_size > 2)
		observe_stack_b(prog, obs[stk_b]);
}
