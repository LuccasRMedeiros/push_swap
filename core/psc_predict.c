/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psc_predict.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 15:38:50 by lrocigno          #+#    #+#             */
/*   Updated: 2021/12/03 21:49:01 by lrocigno         ###   ########.fr       */
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
	if (preds[0] == psm_pb)
	{
		if (*(int *)a->content > *(int *)b->content)
		{
			preds[1] = NULL;
			return ;
		}
		if (preds[1] == psm_sb || preds[1] == psm_rb || preds[1] == psm_rrb)
			preds[0] = preds[1];
		else if (*(int *)a->content > *(int *)b->next->content)
			preds[0] = psm_rb;
		else if (*(int *)a->content > *(int *)b->prev->content)
			preds[0] = psm_rrb;
		else
		{
			preds[1] = NULL;
			return ;
		}
		preds[1] = psm_pb;
	}
}

/*
** Fuse two actions case they behave similarly.
*/

static void	fuse(t_act *preds[3])
{
	if (preds[0] == psm_sa && preds[1] == psm_sb)
		preds[0] = psm_ss;
	else if (preds[0] == psm_ra && preds[1] == psm_rb)
		preds[0] = psm_rr;
	else if (preds[0] == psm_rra && preds[1] == psm_rrb)
		preds[0] = psm_rrr;
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

	if (!obs[stk_b])
		return (NULL);
	comp[item] = *(int *)prog->stack_a->content;
	comp[next] = *(int *)prog->stack_a->next->content;
	comp[nxt2] = *(int *)prog->stack_a->next->next->content;
	comp[prev] = *(int *)prog->stack_a->prev->content;
	if (comp[item] < comp[next] && comp[item] > comp[nxt2])
		return (psm_sb);
	else if (obs[stk_b] <= prog->a_size / 2 && comp[item] < comp[prev])
		return (psm_rb);
	else if (comp[item] < comp[prev] || comp[item] > comp[next])
		return (psm_rrb);
	return (psm_pa);
}

/*
** Select a apropriate action using the observations as reference. The return of
** the function is a function from push_swap_moves.
*/

static t_act	*predict_a(t_prog *prog, int obs[2])
{
	int		comp[4];

	if (!obs[stk_a])
		return (NULL);
	comp[item] = *(int *)prog->stack_a->content;
	comp[next] = *(int *)prog->stack_a->next->content;
	comp[nxt2] = *(int *)prog->stack_a->next->next->content;
	comp[prev] = *(int *)prog->stack_a->prev->content;
	if (comp[item] > comp[next] && comp[item] < comp[nxt2])
		return (psm_sa);
	else if (obs[stk_a] <= prog->a_size / 2 && comp[item] > comp[prev])
		return (psm_ra);
	else if (comp[item] > comp[prev] || comp[item] < comp[next])
		return (psm_rra);
	return (psm_pb);
}

/*
** Compare items in stacks and predict a movement, these predictions are 
** compared and then it return the presumed best course of action.
*/

void	psc_predict(t_prog *prog, int obs[2], t_act *preds[3])
{
	preds[0] = predict_a(prog, obs);
	preds[1] = predict_b(prog, obs);
	if (preds[0] == psm_pb || preds[1] == psm_pa)
		deal(prog->stack_a, prog->stack_b, preds);
	fuse(preds);
}
