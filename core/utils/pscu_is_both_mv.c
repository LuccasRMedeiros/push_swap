/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pscu_is_both_mv.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 15:23:07 by lrocigno          #+#    #+#             */
/*   Updated: 2022/01/08 11:53:01 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap_core.h>

/*
** See if a informed movement is part of both stack movements, return 1 case 
** true, 0 case false.
*/

int	pscu_is_both_mv(t_act *mv)
{
	if (mv == pscm_ss || mv == pscm_rr || mv == pscm_rrr)
		return (1);
	return (0);
}
