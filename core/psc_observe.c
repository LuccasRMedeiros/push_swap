/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psc_observe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 16:04:59 by lrocigno          #+#    #+#             */
/*   Updated: 2022/01/07 15:29:46 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap_core.h>

/*
** Do the same as observe_a, but take into consideration that the ranked items
** order must be decrescent.
*/

static void	observe_b(t_prog *prog, int obs[2])
{
	t_stack	*b;

	b = prog->stack_b;
	while (obs[d] < prog->b_size)
	{
		if ((b->rank < b->next->rank) &&
				(b->rank != prog->lts_b[l] || b->next->rank != prog->lts_b[g]))
			break;
		obs[d] += 1;
		b = b->next;
	}
	b = prog->stack_b;
	while (obs[u] < prog->b_size)
	{
		if ((b->rank > b->prev->rank) &&
				(b->rank != prog->lts_b[g] || b->prev->rank != prog->lts_b[l]))
			return ;
		obs[u] += 1;
		b = b->prev;
	}
}

/*
** Observe the stack A from top to bottom and in the oposite way looking for the
** first ocurrence of misplaced items.
**
** When it find such ocurrence it goes to the next stage of the search (from 
** bottom to top), and when it find another ocurrence it finishes the routine.
*/

static void	observe_a(t_prog *prog, int obs[2])
{
	t_stack	*a;

	a = prog->stack_a;
	while (obs[d] < (int)prog->a_size)
	{
		if ((a->rank > a->next->rank) &&
				(a->rank != prog->lts_a[g] || a->next->rank != prog->lts_a[l]))
			break;
		obs[d] += 1;
		a = a->next;
	}
	a = prog->stack_a;
	while (obs[u] < (int)prog->a_size)
	{
		if ((a->rank < a->prev->rank) &&
				(a->rank != prog->lts_a[l] || a->prev->rank != prog->lts_a[g]))
			return ;
		obs[u] += 1;
		a = a->prev;
	}
}

/*
** Observes stacks A and B to see how they are organized at the moment this 
** routine is called.
**
** Its objective is to notate how much steps exists between a item and its
** successor according to their ranks.
*/

void psc_observe(t_prog *prog, int obs[2][2])
{
	if (prog->a_size > 2)
		observe_a(prog, obs[a]);
	if (prog->b_size > 2)
		observe_b(prog, obs[b]);
}
