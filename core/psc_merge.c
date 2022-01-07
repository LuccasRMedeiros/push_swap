/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psc_merge.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 11:33:27 by lrocigno          #+#    #+#             */
/*   Updated: 2022/01/07 16:33:17 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap_core.h>

/*
** Rotate stack_a till all the items be correctly placed.
*/

static void	organize(t_prog *prog)
{
	int		dist;
	t_stack	*a;
	t_act	*rot;

	dist = 0;
	a = prog->stack_a;
	while (a->rank != 1)
	{
		a = a->next;
		++dist;
	}
	if (dist <= prog->a_size / 2)
		rot = pscm_ra;
	else
	{
		rot = pscm_rra;
		dist = prog->a_size - dist;
	}
	while (dist)
	{
		rot(&prog);
		--dist;
	}
}

/*
** Search for a item on stack A which is less the the top item on stack B.
*/

static int	search(t_prog *prog)
{
	t_stack	*a;
	t_stack	*b;
	int		dist;

	a = prog->stack_a;
	b = prog->stack_b;
	dist = 0;
	while (b->rank - a->prev->rank != 1 && a->rank - b->rank != 1)
	{
		++dist;
		a = a->next;
	}
	return (dist);
}

/*
** Place all the items on stack B on top of stack A and them organize stack A.
*/

void	psc_merge(t_prog *prog)
{
	int		dist;
	t_act	*rot;

	if (!prog->b_size)
	{
		organize(prog);
		return ;
	}
	dist = search(prog);
	if (dist <= prog->a_size / 2)
		rot = pscm_ra;
	else
	{
		rot = pscm_rra;
		dist = prog->a_size - dist;
	}
	while (dist)
	{
		rot(&prog);
		--dist;
	}
	pscm_pa(&prog);
	psc_merge(prog);
}
