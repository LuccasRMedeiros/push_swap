/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psc_simplesort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 20:50:14 by lrocigno          #+#    #+#             */
/*   Updated: 2022/01/20 22:33:54 by coder            ###   ########.fr       */
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
		if (((a->rank == 1 && a->prev->rank == 2)
			|| (a->rank == 1 && a->prev->rank == 0)) && prog->a_size <= 3)
			pscm_rra(&prog, &a);
		else if (a->rank == 2 && a->next->rank == 1 && b->next->rank == 4)
			pscm_ss(&prog, &a);
		else if (a->rank == 2 && a->next->rank == 1)
			pscm_sa(&prog, &a);
		else if (a->rank == 3 || a->rank == 4)
		{
			pscm_pb(&prog, &a);
			b = prog->stack_b;
		}
		else
			pscm_ra(&prog, &a);
	}
	if (b->next->rank == 4 && prog->b_size > 1)
		pscm_sb(&prog, &b);
	psc_merge(prog);
}
