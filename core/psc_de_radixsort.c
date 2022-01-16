/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psc_de_radixsort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 20:25:35 by lrocigno          #+#    #+#             */
/*   Updated: 2022/01/16 12:00:07 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap_core.h>

/*
** Sort the stack usign the double-edge radix sort.
**
** The "double-edge" radix sort is basically a radix sort with radix = 2 (this
** value because push_swap only have two boxes, so we need to use binary to make
** the count subroutine), but each time it finishes counting, instead of merging
** the two stacks it goes to the next digit that should be availed, and only
** pushes (to stack A) when the n-th digit does not belongs to box B (that would
** correspond to box "0").
*/

static void	de_radixsort(t_prog *prog, t_stack *stk, t_act *mvs[3], int dch)
{
	int		is_b;
	int		rots;

	if (dch == prog->max_bits)
		return ;
	is_b = pscu_is_stack_b_mv(mvs[rotn]);
	rots = 0;
	dch += is_b;
	while (pscu_find_next(prog, dch, is_b))
	{
		if (((stk->rank >> dch) & 1) == is_b)
			mvs[push](&prog, &stk);
		else
		{
			mvs[rotn](&prog, &stk);
			++rots;
		}
	}
	rots = pscu_calccred(prog, mvs, rots, is_b);
	while (--rots > -1)
		mvs[cred](&prog, &stk);
	pscu_invertmv(mvs);
	de_radixsort(prog, pscu_selstack(prog, is_b), mvs, dch);
}

/*
** After sorting the stack with the double-edge radix sort, merge A and B.
*/

void	psc_de_radixsort(t_prog *prog)
{
	t_act	*mvs[3];
	
	if (!pscu_observe(prog->stack_a, pscu_flwnx))
		return ;
	mvs[rotn] = pscm_ra;
	mvs[push] = pscm_pb;
	mvs[cred] = pscm_rra;
	de_radixsort(prog, prog->stack_a, mvs, 0);
	psc_merge(prog);
}
