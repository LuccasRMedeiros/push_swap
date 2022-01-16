/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psc_tournamentsort.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 20:50:14 by lrocigno          #+#    #+#             */
/*   Updated: 2022/01/15 22:30:02 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap_core.h>

/*
** Use the tournament algorithm to sort the stack A.
**
** The tournament algorithm is pretty simple. It ranks each item, then simply
** place them all in sequence.
**
** This would work perfectly if we could just use three arrays and place the
** items directly on their key index, in push_swap it wouldn't work, by the way
** it can easly sort a short stack.
*/

void	tournamentsort(t_prog *prog)
{
	t_stack	*dummy;
	int		max_rank;

	dummy = NULL;
	max_rank = (int)prog->max_rank - 1;
	if (!prog->b_size)
		return ;
	if (prog->stack_a->rank - prog->stack_b->rank == 1
			|| (prog->stack_a->rank == 0 && prog->stack_b->rank == max_rank))
		pscm_pa(&prog, &dummy);
	else if (prog->stack_a->rank - prog->stack_a->prev->rank == 1)
		pscm_rra(&prog, &dummy);
	else
		pscm_rb(&prog, &dummy);
	tournamentsort(prog);
}

/*
** Place the even ranks on stack B and let the odd's on A.
*/

void	psc_tournamentsort(t_prog *prog)
{
	unsigned int	n;
	t_stack			*dummy;
	t_act			*dir;

	n = 0;
	dummy = NULL;
	dir = pscm_ra;
	while (pscu_observe(prog) && n < prog->max_rank)
	{
		if (prog->stack_a->rank % 2 == 0 
				&& prog->stack_a->next->rank - prog->stack_a->rank != 1
				&& prog->stack_a->rank - prog->stack_a->prev->rank != 1)
			pscm_pb(&prog, &dummy);
		else
			pscm_ra(&prog, &dummy);
		++n;
	}
	tournamentsort(prog);
	if (prog->stack_a->rank < (int)prog->max_rank / 2)
		dir = pscm_rra;
	while (prog->stack_a->rank != 0)
		dir (&prog, &dummy);
}
