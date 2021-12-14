/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psc_is_stack_a_move.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 23:17:13 by lrocigno          #+#    #+#             */
/*   Updated: 2021/12/10 23:38:01 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap_core.h>

/*
** Check if the movement is part of the stack A only movements or it is pb.
**
** Case positive it return 1, otherwise it will be 0.
*/

int	psc_is_stack_a_move(t_act *pred)
{
	if (pred == pscm_ra || pred == pscm_rra 
			|| pred == pscm_sa || pred == pscm_pb)
		return (1);
	return (0);
}
