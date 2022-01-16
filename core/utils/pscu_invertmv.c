/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psc_invertmv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 15:38:50 by lrocigno          #+#    #+#             */
/*   Updated: 2022/01/15 11:21:37 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap_core.h>

/*
** Invert the movements based on the rotation.
*/

void	pscu_invertmv(t_act *mvs[3])
{
	if (pscu_is_stack_a_mv(mvs[rotn]))
	{
		mvs[rotn] = pscm_rb;
		mvs[push] = pscm_pa;
		mvs[cred] = pscm_rrb;
	}
	else
	{
		mvs[rotn] = pscm_ra;
		mvs[push] = pscm_pb;
		mvs[cred] = pscm_rra;
	}
}
