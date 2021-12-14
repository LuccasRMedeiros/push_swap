/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psc_observe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 16:04:59 by lrocigno          #+#    #+#             */
/*   Updated: 2021/12/07 22:38:50 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap_core.h>

/*
** Look from the top to the next item (going the reverse way) for the first 
** imperfection it find on the stack B.
*/

static void	observe_stack_b_up(t_prog *prog, int imps_b[2])
{
	t_dlist	*stack;
	int		cp[2];
	int		lts[2];
	int		pos;

	stack = prog->stack_b;
	cp[item] = *(int *)stack->content;
	cp[next] = *(int *)stack->prev->content;
	lts[l] = prog->limits_b[l];
	lts[g] = prog->limits_b[g];
	pos = 1;
	while (pos <= prog->b_size && !imps_b[up])
	{
		if ((cp[item] > cp[next] && (cp[item] != lts[g] || cp[next] != lts[l]))
				|| (cp[item] == lts[l] && cp[next] == lts[g]))
			imps_b[up] = pos;
		stack = stack->prev;
		cp[item] = *(int *)stack->content;
		cp[next] = *(int *)stack->prev->content;
		++pos;
	}
}

/*
** Look from the top to the bottom for the first imperfection it find on the
** stack B.
*/

static void	observe_stack_b_down(t_prog *prog, int imps_b[2])
{
	t_dlist	*stack;
	int		cp[2];
	int		lts[2];
	int		pos;

	stack = prog->stack_b;
	cp[item] = *(int *)stack->content;
	cp[next] = *(int *)stack->next->content;
	lts[l] = prog->limits_b[l];
	lts[g] = prog->limits_b[g];
	pos = 1;
	while (pos <= prog->b_size && !imps_b[down])
	{
		if ((cp[item] < cp[next] && (cp[item] != lts[l] || cp[next] != lts[g]))
				|| (cp[item] == lts[g] && cp[next] == lts[l]))
			imps_b[down] = pos;
		stack = stack->next;
		cp[item] = *(int *)stack->content;
		cp[next] = *(int *)stack->next->content;
		++pos;
	}
}
/*
** Look from the top to the next item (going the reverse way) for the first 
** imperfection it find on the stack_a.
*/

static void	observe_stack_a_up(t_prog *prog, int imps_a[2])
{
	t_dlist	*stack;
	int		cp[2];
	int		lts[2];
	int		pos;

	stack = prog->stack_a;
	cp[item] = *(int *)stack->content;
	cp[next] = *(int *)stack->prev->content;
	lts[l] = prog->limits_a[l];
	lts[g] = prog->limits_a[g];
	pos = 1;
	while (pos <= prog->a_size && !imps_a[up])
	{
		if ((cp[item] < cp[next] && (cp[item] != lts[l] || cp[next] != lts[g]))
				|| (cp[item] == lts[g] && cp[next] == lts[l]))
			imps_a[up] = pos;
		stack = stack->prev;
		cp[item] = *(int *)stack->content;
		cp[next] = *(int *)stack->prev->content;
		++pos;
	}
}

/*
** Look from the top to the bottom for the first imperfection it find on the
** stack_a.
*/

static void	observe_stack_a_down(t_prog *prog, int imps_a[2])
{
	t_dlist	*stack;
	int		cp[2];
	int		lts[2];
	int		pos;

	stack = prog->stack_a;
	cp[item] = *(int *)stack->content;
	cp[next] = *(int *)stack->next->content;
	lts[l] = prog->limits_a[l];
	lts[g] = prog->limits_a[g];
	pos = 1;
	while (pos <= prog->a_size && !imps_a[down])
	{
		if ((cp[item] > cp[next] && (cp[item] != lts[g] || cp[next] != lts[l]))
				|| (cp[item] == lts[l] && cp[next] == lts[g]))
			imps_a[down] = pos;
		stack = stack->next;
		cp[item] = *(int *)stack->content;
		cp[next] = *(int *)stack->next->content;
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
	{
		observe_stack_a_down(prog, obs[stk_a]);
		observe_stack_a_up(prog, obs[stk_a]);
	}
	if (prog->b_size > 2)
	{
		observe_stack_b_down(prog, obs[stk_b]);
		observe_stack_b_up(prog, obs[stk_b]);
	}
}
