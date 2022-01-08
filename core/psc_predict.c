/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psc_predict.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 15:38:50 by lrocigno          #+#    #+#             */
/*   Updated: 2022/01/08 09:55:19 by lrocigno         ###   ########.fr       */
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
	if ((preds[act1] == pscm_ra && preds[3] == pscm_rra)
			|| (preds[act1] == pscm_rra && preds[3] == pscm_ra))
	{
		preds[act1] = preds[3];
		preds[3] = NULL;
	}
	if ((preds[act2] == pscm_rb && preds[4] == pscm_rrb)
			|| (preds[act2] == pscm_rrb && preds[4] == pscm_rb))
	{
		preds[act2] = preds[4];
		preds[4] = NULL;
	}
	if ((preds[act1] == pscm_rr && preds[3] == pscm_rrr)
			|| (preds[act1] == pscm_rrr && preds[3] == pscm_rr))
	{
		preds[act1] = preds[3];
		preds[3] = NULL;
	}
}

/*
** Receive the predictions and define a better course of action.
*/

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
	if (psc_is_both_mv(preds[act1]) || preds[act2] == preds[await])
		preds[act2] = NULL;
	else if (preds[act1] == preds[await])
		preds[act1] = NULL;
}

/*
** Select a apropriate action using the observations as reference. The return of
** the function is a function from push_swap_moves.
*/

static t_act	*predict_b(t_prog *prog, int obs[2])
{
	int	threshold;
	int	ds[3];

	threshold = prog->total_items / 4;
	if (threshold < 2)
		threshold = 2;
	ds[t] = psc_find_next_b(prog->stack_b, prog->lts_b, prog->b_size);
	ds[n] = psc_find_next_b(prog->stack_b->next, prog->lts_b, prog->b_size);
	ds[p] = psc_find_next_b(prog->stack_b->prev, prog->lts_b, prog->b_size);
	if (ds[t] >= 1 && ds[t] <= threshold && ds[n] != 1 && ds[p] > 0)
		return (pscm_sb);
	else if (prog->stack_b->next->rank - prog->stack_a->rank == 1)
		return (pscm_sb);
	else if (obs[d] <= obs[u] && obs[d] < prog->b_size)
		return (pscm_rb);
	else if (obs[u] < obs[d])
		return (pscm_rrb);
	return (NULL);
}

/*
** Select a apropriate action using the observations as reference. The return of
** the function is a function from push_swap_core_moves.
*/

static t_act	*predict_a(t_prog *prog, int obs[2])
{
	int	threshold;
	int	ds[3];

	threshold = prog->total_items / 4;
	if (threshold < 2)
		threshold = 2;
	ds[t] = psc_find_next_a(prog->stack_a, prog->lts_a, prog->a_size);
	ds[n] = psc_find_next_a(prog->stack_a->next, prog->lts_a, prog->a_size);
	ds[p] = psc_find_next_a(prog->stack_a->prev, prog->lts_a, prog->a_size);
	if (ds[t] >= 1 && ds[t] <= threshold && ds[n] != 1 && ds[p] > 0)
		return (pscm_sa);
	else if (prog->stack_a->rank - prog->stack_a->next->rank == 1)
		return (pscm_sa);
	else if (prog->stack_a->rank > (size_t)prog->total_items / 2)
		return (pscm_pb);
	else if (obs[d] <= obs[u] && obs[d] < prog->a_size)
		return (pscm_ra);
	else if (obs[u] < obs[d])
		return (pscm_rra);
	return (NULL);
}

/*
** Compare items in stacks and predict a movement, these predictions are 
** compared and then it return the presumed best course of action.
*/

void	psc_predict(t_prog *prog, t_act *preds[5], int obs[2][2])
{
	if (psc_is_stack_a_mv(preds[await]))
	{
		preds[act1] = preds[await];
		preds[await] = NULL;
	}
	else if (prog->a_size > 2 && obs[a][d] < prog->a_size)
		preds[act1] = predict_a(prog, obs[a]);
	if (psc_is_stack_b_mv(preds[await]))
	{
		preds[act2] = preds[await];
		preds[await] = NULL;
	}
	else if (prog->b_size > 2 && obs[b][d] < prog->b_size)
		preds[act2] = predict_b(prog, obs[b]);
	history(preds);
	refine(preds, obs);
}
