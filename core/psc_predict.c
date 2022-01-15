/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psc_predict.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 15:38:50 by lrocigno          #+#    #+#             */
/*   Updated: 2022/01/14 23:04:16 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap_core.h>

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

void	psc_predict(t_prog *prog, t_act *preds[5], unsigned int dch)
{
	if (!((prog->stack_a->rank >> dch) & 1))
		preds[act1] = (pscm_pb);
	else
		preds[act1] = (pscm_ra);
}
