/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psc_predict.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 15:38:50 by lrocigno          #+#    #+#             */
/*   Updated: 2022/01/11 23:54:09 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap_core.h>

/*
** Check the history to avoid a contradiction (a swap after a swap, or rotation
** to a direction after a rotation to the oposite direction). When this happens
** the prefered action will be the last one.
*/

static void history(t_act *preds[5])
{
	if ((preds[act1] == pscm_ra && preds[hst1] == pscm_rra)
			|| (preds[act1] == pscm_rra && preds[hst1] == pscm_ra))
		preds[act1] = preds[hst1];
	if ((preds[act2] == pscm_rb && preds[hst2] == pscm_rrb)
			|| (preds[act2] == pscm_rrb && preds[hst2] == pscm_rb))
		preds[act2] = preds[hst2];
	if ((preds[act1] == pscm_rr && preds[hst1] == pscm_rrr)
			|| (preds[act1] == pscm_rrr && preds[hst1] == pscm_rr))
		preds[act1] = preds[hst1];
}

/*
** Receive the predictions and define a better course of action.

static void	refine(t_act *preds[5], int obs[2][2])
{
	if (preds[act1] == pscm_sa && preds[act2] == pscm_sb)
		preds[act1] = pscm_ss;
	else if (preds[act1] == pscm_ra && preds[act2] == pscm_rb)
		preds[act1] = pscm_rr;
	else if (preds[act1] == pscm_rra && preds[act2] == pscm_rrb)
		preds[act1] = pscm_rrr;
	else if (preds[act1] == pscm_pb && preds[act2] == pscm_sb)
		preds[await] = preds[act1];
	else if (preds[act1] == pscm_sa && preds[act2])
		preds[await] = preds[act1];
	else if (preds[act2] == pscm_sb && preds[act1])
		preds[await] = preds[act2];
	else if (preds[act1] == pscm_ra && preds[act2] && obs[a][d] < obs[b][d])
		preds[await] = preds[act1];
	else if (preds[act1] == pscm_rra && preds[act2] && obs[a][u] < obs[b][u])
		preds[await] = preds[act1];
	else if (preds[act2] == pscm_rb && preds[act1] && obs[b][d] < obs[a][d])
		preds[await] = preds[act2];
	else if (preds[act2] == pscm_rrb && preds[act1] && obs[b][u] < obs[a][u])
		preds[await] = preds[act2];
	if (pscu_is_both_mv(preds[act1]) || preds[act2] == preds[await]
			|| (preds[act1] == pscm_pb && preds[act2] == pscm_pa))
		preds[act2] = NULL;
	else if (preds[act1] == preds[await])
		preds[act1] = NULL;
}

** Use observations as reference together with radix = 2 to select the most 
** apropriate movement.
*/

static t_act	*predict_a(t_prog *pg, int obs[2], int dch)
{
	if (((pg->stack_a->rank >> dch) & 1) == 1)
	{
		if (obs[d] <= obs[u])
			return (pscm_ra);
		else
			return (pscm_rra);
	}
	else
		return (pscm_pb);
}

/*
** The subroutines predict a and b uses bitwise operations on ranks to select a
** movement. Then the history will confirm if the predicted movement counteract
** the last executed, then it refine the movements making them await or 
** combining them, then it confirm again if the movement will not counteract the
** previous. This is done twice because the first return of history maybe can be
** combined, and in the second time a combination (that only exists after the
** refine), a combined movement could counteract the last one.
**
** When the subroutine finishes it goes back to the caller, who must deal with
** whatever was processed by psc_predict.
*/

void	psc_predict(t_prog *pg, t_act *preds[5], int obs[2], unsigned int dch)
{
	preds[act1] = predict_a(pg, obs, dch);
	history(preds);
}
