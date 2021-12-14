/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psc_act.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 12:32:08 by lrocigno          #+#    #+#             */
/*   Updated: 2021/12/12 13:34:01 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap_core.h>

/*
** Use anotations to sort the stack A. The function call for execute each time
** it finds the best action psc_execute will be called, and psc_execute will
** call it after each movement, creating a recursive routine.
**
** When psc_anotate return a array without imperfections, psc_sort understands
** it terminated the sort and return before call psc_executing finally exiting
** the loop allowign the program to finish.
*/

void	psc_act(t_prog *prog, t_act *acts[4])
{
	int		obs[2][2];
	size_t	act_i;

	psc_observe(prog, obs);
	act_i = 0;
	if (!((obs[stk_a][down] + obs[stk_a][up])
				+ (obs[stk_b][down] + obs[stk_b][up])))
	{
		psc_merge(prog);
		return ;
	}
	psc_predict(prog, obs, acts);
	if (!acts[act1] && !acts[act2])
		return ;
	while (act_i < 3)
	{
		if (acts[act_i])
			acts[act_i](&prog);
		++act_i;
	}
	psc_act(prog, acts);
}
