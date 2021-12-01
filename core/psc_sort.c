/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psc_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 12:32:08 by lrocigno          #+#    #+#             */
/*   Updated: 2021/11/30 23:06:36 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap_core.h>

/*
** Select a apropriate action using the notes as reference. The return of the
** function is a function from push_swap_moves.
*/

static t_act	*select_action(t_prog *prog, int obs[2])
{
	int		comp[4];

	comp[item] = *(int *)prog->stack_a->content;
	comp[next] = *(int *)prog->stack_a->next->content;
	comp[nxt2] = *(int *)prog->stack_a->next->next->content;
	comp[prev] = *(int *)prog->stack_a->prev->content;
	if (comp[item] < comp[next])
		if (comp[item] < comp[nxt2])
			if (obs[stk_a] <= prog->stack_size / 2)
				return (psm_ra);
			else
				return (psm_rra);
		else
			return (psm_ra);
	else if (comp[item] > comp[next]
		&& (comp[next] > comp[prev] || comp[item] < comp[nxt2]))
		return (psm_sa);
	else if (comp[item] > comp[prev])
		return (psm_ra);
	else if (obs[stk_a] <= prog->stack_size / 2)
		return (psm_rra);
	return (NULL);
}

/*
** Use anotations to sort the stack A. The function call for execute each time
** it finds the best action psc_execute will be called, and psc_execute will
** call it after each movement, creating a recursive routine.
**
** When psc_anotate return a array without imperfections, psc_sort understands
** it terminated the sort and return before call psc_executing finally exiting
** the loop allowign the program to finish.
*/

void	psc_sort(t_prog *prog)
{
	int		obs[2];
	t_act	*action;

	psc_observe(prog, obs);
	if (!(obs[stk_a] + obs[stk_b]))
		return ;
	action = select_action(prog, obs);
	if (!action)
		return ;
	action(&prog);
	psc_sort(prog);
}
