/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psc_merge.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 11:33:27 by lrocigno          #+#    #+#             */
/*   Updated: 2021/12/03 14:03:29 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap_core.h>

/*
** Rotate stack_a till all the items be correctly placed.
*/

static void	organize(t_prog *prog)
{
	int		n_rots;
	t_dlist	*stack_a;
	t_act	*rot;

	n_rots = 1;
	stack_a = prog->stack_a;
	while (*(int *)stack_a->content < *(int *)stack_a->next->content)
	{
		stack_a = stack_a->next;
		++n_rots;
	}
	if (n_rots <= prog->a_size / 2)
		rot = psm_ra;
	else
	{
		rot = psm_rra;
		n_rots = prog->a_size - n_rots;
	}
	while (n_rots)
	{
		rot(&prog);
		--n_rots;
	}
}

/*
** Search for a item on stack A which is less the the top item on stack B.
*/

static int	search(t_prog *prog)
{
	t_dlist	*stack_a;
	int		top_b;
	int		place;

	stack_a = prog->stack_a;
	top_b = *(int *)prog->stack_b->content;
	place = 0;
	while (*(int *)stack_a->content < top_b)
	{
		stack_a = stack_a->next;
		++place;
	}
	return (place);
}

/*
** Place all the items on stack B on top of stack A and them organize stack A.
*/

void	psc_merge(t_prog *prog)
{
	int		n_rots;
	t_act	*rot;

	if (!prog->b_size)
	{
		organize(prog);
		return ;
	}
	n_rots = search(prog);
	if (n_rots <= prog->a_size / 2)
		rot = psm_ra;
	else
	{
		rot = psm_rra;
		n_rots = prog->a_size - n_rots;
	}
	while (n_rots)
	{
		rot(&prog);
		--n_rots;
	}
	psm_pa(&prog);
	psc_merge(prog);
}
