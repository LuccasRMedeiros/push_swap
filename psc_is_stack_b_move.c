/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psc_is_stack_b_move.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 23:38:19 by lrocigno          #+#    #+#             */
/*   Updated: 2021/12/10 23:38:59 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap_core.h>

/*
** Check if the movement is part of the stack B only movements or it is pa.
**
** Case positive it return 1, otherwise it will be 0.
*/

int	psc_is_stack_b_move(t_act *pred)
{
	if (pred == pscm_rb || pred == pscm_rrb 
			|| pred == pscm_sb || pred == pscm_pa)
		return (1);
	return (0);
}
