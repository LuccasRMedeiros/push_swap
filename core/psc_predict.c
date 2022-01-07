/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psc_predict.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 15:38:50 by lrocigno          #+#    #+#             */
/*   Updated: 2022/01/07 16:54:51 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap_core.h>

/*
** Receive the predictions and define a better course of action.
*/

static void	refine(t_act *prds[3], int obs[2][2])
{
	if (prds[act1] == pscm_sa && prds[act2] == pscm_sb)
		prds[act1] = pscm_ss;
	else if (prds[act1] == pscm_ra && prds[act2] == pscm_rb)
		prds[act1] = pscm_rr;
	else if (prds[act1] == pscm_rra && prds[act2] == pscm_rrb)
		prds[act1] = pscm_rrr;
	else if (prds[act1] == pscm_pb && prds[act2] == pscm_sb)
		prds[await] = prds[act1];
	else if (prds[act1] == pscm_sa && prds[act2])
		prds[await] = prds[act1];
	else if (prds[act2] == pscm_sb && prds[act1])
		prds[await] = prds[act2];
	else if (prds[act1] == pscm_ra && prds[act2] && obs[a][d] < obs[b][d])
		prds[await] = prds[act1];
	else if (prds[act1] == pscm_rra && prds[act2] && obs[a][u] < obs[b][u])
		prds[await] = prds[act1];
	else if (prds[act1] == pscm_rb && prds[act2] && obs[b][d] < obs[a][d])
		prds[await] = prds[act2];
	else if (prds[act1] == pscm_rrb && prds[act2] && obs[b][u] < obs[a][u])
		prds[await] = prds[act2];
	if (psc_is_both_mv(prds[act1]) || prds[act2] == prds[await])
		prds[act2] = NULL;
	else if (prds[act1] == prds[await])
		prds[act1] = NULL;
}

/*
** Select a apropriate action using the observations as reference. The return of
** the function is a function from push_swap_moves.
*/

static t_act	*predict_b(t_prog *prog, int obs[2])
{
	int	one_quarter;
	int	ds[3];

	one_quarter = prog->b_size / 4;
	ds[t] = psc_find_next_b(prog->stack_b, prog->lts_b, prog->b_size);
	ds[n] = psc_find_next_b(prog->stack_b->next, prog->lts_b, prog->b_size);
	ds[p] = psc_find_next_b(prog->stack_b->prev, prog->lts_b, prog->b_size);
	if (one_quarter > 0 && (ds[t] >= 1 && ds[t] <= one_quarter))
			return (pscm_sb);
	else if (ds[t] == 1)
		return (pscm_sb);
	else if (prog->stack_b->next->rank - prog->stack_a->rank == 1 && ds[n])
		return (pscm_sb);
	else if (prog->stack_b->rank - prog->stack_a->prev->rank == 1)
		return (pscm_pa);
	else if ((ds[n] < ds[p] || !ds[p]) && ds[n] >= 1)
		return (pscm_rb);
	else if ((ds[p] < ds[n] || !ds[n]) && ds[p] >= 1)
		return (pscm_rrb);
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
	int	one_quarter;
	int	ds[3];

	one_quarter = prog->a_size / 4;
	ds[t] = psc_find_next_a(prog->stack_a, prog->lts_a, prog->a_size);
	ds[n] = psc_find_next_a(prog->stack_a->next, prog->lts_a, prog->a_size);
	ds[p] = psc_find_next_a(prog->stack_a->prev, prog->lts_a, prog->a_size);
	if (one_quarter > 0 && (ds[t] >= 1 && ds[t] <= one_quarter))
			return (pscm_sa);
	else if (ds[t] == 1 && ds[n] > 1)
		return (pscm_sa);
	else if (prog->stack_a->rank - prog->stack_a->next->rank == 1 && ds[n])
		return (pscm_sa);
	else if (prog->stack_a->rank > (size_t)prog->total_items / 2 &&
			ds[t] > 1)
		return (pscm_pb);
	else if ((ds[n] < ds[p] || !ds[p]) && ds[n] >= 1)
		return (pscm_ra);
	else if ((ds[p] < ds[n] || !ds[n]) && ds[p] >= 1)
		return (pscm_rra);
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

void	psc_predict(t_prog *prog, t_act *preds[3])
{
	int	obs[2][2];

	obs[a][d] = 0;
	obs[a][u] = 0;
	obs[b][d] = 0;
	obs[b][u] = 0;
	psc_observe(prog, obs);
	if (psc_is_stack_a_mv(preds[await]))
	{
		preds[act1] = preds[await];
		preds[await] = NULL;
	}
	else if (prog->a_size > 2 && obs[a][d] != prog->a_size)
		preds[act1] = predict_a(prog, obs[a]);
	if (psc_is_stack_b_mv(preds[await]))
	{
		preds[act2] = preds[await];
		preds[await] = NULL;
	}
	else if (prog->b_size > 2 && obs[b][d] != prog->b_size)
		preds[act2] = predict_b(prog, obs[b]);
	refine(preds, obs);
}
