/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psc_simplesort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 20:50:14 by lrocigno          #+#    #+#             */
/*   Updated: 2022/01/16 18:57:04 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap_core.h>

/*
** Simply sort the stack.
*/

void	psc_simplesort(t_prog *prog)
{
	t_stack	*a;
	t_stack	*b;

	a = prog->stack_a;
	b = prog->stack_b;
	while (pscu_observe(a, pscu_flwnx))
	{
		if (a->rank == 0 && (a->prev->rank == 3 || a->prev->rank == 4))
			pscm_rra(&prog, &a);
		if (a->rank == 2 && a->next->rank == 1 && b->next->rank == 3)
			pscm_ss(&prog, &a);
		else if (a->rank == 2 && a->next->rank == 1)
			pscm_sa(&prog, &a);
		else if (a->rank == 3 || a->rank == 4)
			pscm_pb(&prog, &a);
		else
			pscm_ra(&prog, &a);
	}
	if (b->next->rank == 4 && prog->b_size > 1)
		pscm_sb(&prog, &b);
	psc_merge(prog);
}
