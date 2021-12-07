/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psc_predict.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 15:38:50 by lrocigno          #+#    #+#             */
/*   Updated: 2021/12/06 22:22:41 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap_core.h>

/*
** Decide if the stacks should exchange items or not.
*/

static void	deal(t_dlist *a, t_dlist *b, t_act *preds[3])
{
	if (!a->content || !b->content)
		return ;
	if (preds[0] == pscm_pb)
	{
		if (preds[1] == pscm_sb || preds[1] == pscm_rb || preds[1] == pscm_rrb)
			preds[0] = preds[1];
		else
		{
			preds[1] = NULL;
			return ;
		}
		preds[1] = pscm_pb;
	}
}

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

	if (!obs[down])
		return (NULL);
	comp[item] = *(int *)prog->stack_b->content;
	comp[next] = *(int *)prog->stack_b->next->content;
	comp[nxt2] = *(int *)prog->stack_b->next->next->content;
	if ((comp[item] < comp[next] || comp[next] < comp[nxt2])
		&& (comp[item] > comp[nxt2] || comp[nxt2] == prog->limits_b[greater]))
		return (pscm_sb);
	else if (obs[down] < obs[up] && obs[down] != 1)
		return (pscm_rb);
	else if (obs[down] > obs[up])
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

	if (!obs[down])
		return (NULL);
	comp[item] = *(int *)prog->stack_a->content;
	comp[next] = *(int *)prog->stack_a->next->content;
	comp[nxt2] = *(int *)prog->stack_a->next->next->content;
	if ((comp[item] > comp[next] || comp[next] > comp[nxt2])
		&& (comp[item] < comp[nxt2] || comp[nxt2] == prog->limits_b[lower]))
		return (pscm_sa);
	else if (obs[down] < obs[up] && obs[down] != 1)
		return (pscm_ra);
	else if (obs[down] > obs[up])
		return (pscm_rra);
	return (pscm_pb);
}

/*
** Compare items in stacks and predict a movement, these predictions are 
** compared and then it return the presumed best course of action.
*/

void	psc_predict(t_prog *prog, int obs[2][2], t_act *preds[2])
{
	preds[0] = predict_a(prog, obs[stk_a]);
	preds[1] = predict_b(prog, obs[stk_b]);
	if (preds[0] == pscm_pb || preds[1] == pscm_pa)
		deal(prog->stack_a, prog->stack_b, preds);
	fuse(preds);
}
