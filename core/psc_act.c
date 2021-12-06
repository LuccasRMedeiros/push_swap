/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psc_act.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 12:32:08 by lrocigno          #+#    #+#             */
/*   Updated: 2021/12/05 23:55:27 by lrocigno         ###   ########.fr       */
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

void	psc_act(t_prog *prog)
{
	t_act	*preds[2];
	int		obs[2][2];
	size_t	act_i;

	preds[0] = NULL;
	preds[1] = NULL;
	psc_observe(prog, obs);
	act_i = 0;
	if (!((obs[stk_a][down] + obs[stk_a][up])
				+ (obs[stk_b][down] + obs[stk_b][up])))
	{
		psc_merge(prog);
		return ;
	}
	psc_predict(prog, obs, preds);
	if (!preds[0] && !preds[1])
		return ;
	while (act_i < 2)
	{
		if (preds[act_i])
			preds[act_i](&prog);
		++act_i;
	}
	psc_act(prog);
}
