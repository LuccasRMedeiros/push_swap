/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pscu_btwlmt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 22:23:32 by lrocigno          #+#    #+#             */
/*   Updated: 2022/01/09 22:32:28 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap_core_utils.h>

/*
** Return 1 if a distance is between one and the threshold. 0 if not.
*/

int	pscu_inlmt(int dist, int threshold)
{
	if (dist >= 1 && dist <= threshold)
		return (1);
	return (0);
}
