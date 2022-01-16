/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pscu_calccred.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 11:24:17 by lrocigno          #+#    #+#             */
/*   Updated: 2022/01/15 20:18:03 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap_core_utils.h>

/*
** Return the number of reverse rotation a stack must do to back to its expected
** order.
*/

int	pscu_calccred(t_prog *prog, t_act *mvs[3], int rots, int is_b)
{
	unsigned int	size;

	size = prog->a_size;
	if (is_b)
		size = prog->b_size;
	if (rots > (int)size / 2)
	{
		mvs[cred] = mvs[rotn];
		return (size - rots);
	}
	else if (rots > 0)
		return (rots);
	return (0);
}
