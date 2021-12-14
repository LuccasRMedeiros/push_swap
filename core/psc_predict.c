/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psc_predict.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 15:38:50 by lrocigno          #+#    #+#             */
/*   Updated: 2021/12/12 17:10:46 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap_core.h>

/*
** Fuse two actions case they behave similarly.
*/

static void	fuse(t_act *preds[3])
{
	if (preds[0] == pscm_sa && preds[1] == pscm_sb)
		preds[0] = pscm_ss;
	else if (preds[0] == pscm_ra && preds[1] == pscm_rb)
		preds[0] = pscm_rr;
	else if (preds[0] == pscm_rra && preds[1] == pscm_rrb)
		preds[0] = pscm_rrr;
	else
		return ;
	preds[1] = NULL;
}

/*
** Select a apropriate action using the observations as reference. The return of
** the function is a function from push_swap_moves.
*/

static t_act	*predict_b(t_prog *prog, int obs[2])
{
	int		comp[4];

	if (!obs[down] && !obs[up])
		return (NULL);
	comp[item] = *(int *)prog->stack_b->content;
	comp[next] = *(int *)prog->stack_b->next->content;
	comp[nxt2] = *(int *)prog->stack_b->next->next->content;
	comp[prev] = *(int *)prog->stack_b->prev->content;
	if ((comp[item] < comp[next]
			&& (comp[item] > comp[nxt2] || comp[next] < comp[prev]))
		|| (comp[item] == prog->limits_b[l] && comp[nxt2] == prog->limits_b[g]))
		return (pscm_sb);
	else if (obs[down] < obs[up] && obs[down] != 1)
		return (pscm_rb);
	else if (obs[down] > obs[up] || obs[up] <= 2)
		return (pscm_rrb);
	return (pscm_pa);
}

/*
** Select a apropriate action using the observations as reference. The return of
** the function is a function from push_swap_moves.
*/

static t_act	*predict_a(t_prog *prog, int obs[2])
{
	int		comp[4];

	if (!obs[down] && !obs[up])
		return (NULL);
	comp[item] = *(int *)prog->stack_a->content;
	comp[next] = *(int *)prog->stack_a->next->content;
	comp[nxt2] = *(int *)prog->stack_a->next->next->content;
	comp[prev] = *(int *)prog->stack_a->prev->content;
	if ((comp[item] > comp[next]
			&& (comp[item] < comp[nxt2] || comp[next] > comp[prev]))
		|| (comp[item] == prog->limits_a[g] && comp[nxt2] == prog->limits_a[l]))
		return (pscm_sa);
	else if (obs[down] < obs[up] && obs[down] != 1)
		return (pscm_ra);
	else if (obs[down] > obs[up] || obs[up] <= 2)
		return (pscm_rra);
	return (pscm_pb);
}

/*
** Compare items in stacks and predict a movement, these predictions are 
** compared and then it return the presumed best course of action.
*/

void	psc_predict(t_prog *prog, int obs[2][2], t_act *preds[4])
{
//	if (!psc_is_stack_a_move(preds[wait]))
		preds[act1] = predict_a(prog, obs[stk_a]);
//	if (!psc_is_stack_b_move(preds[wait]))
		preds[act2] = predict_b(prog, obs[stk_b]);
//	debate(prog->stack_a, prog->stack_b, preds);
	fuse(preds);
}
