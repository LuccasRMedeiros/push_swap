/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pscu_is_stack_b_mv.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 15:21:43 by lrocigno          #+#    #+#             */
/*   Updated: 2022/01/08 11:53:01 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap_core.h>

/*
** See if a informed movement is part of stack B movements, return 1 case true,
** 0 case false.
*/

int	pscu_is_stack_b_mv(t_act *mv)
{
	if (mv == pscm_sb || mv == pscm_rb || mv == pscm_rrb || mv == pscm_pa)
		return (1);
	return (0);
}
