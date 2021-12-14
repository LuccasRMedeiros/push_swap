/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psc_debate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 10:58:26 by lrocigno          #+#    #+#             */
/*   Updated: 2021/12/12 13:34:03 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap_core.h>

/*
** Refine the course of action.
*/

void	debate(t_prog *prog, t_act *preds[3])
{
	if (prog->a_size <= 2 || !prog->b_size <= 2)
		return ;
	if (preds[act1] == pscm_pb || preds[act2] == pscm_pa)
}

