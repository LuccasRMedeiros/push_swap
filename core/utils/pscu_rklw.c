/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pscu_rklw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 11:03:52 by lrocigno          #+#    #+#             */
/*   Updated: 2022/01/09 23:53:57 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap_core_utils.h>

/*
** Return the diference between the "comp" node rank and "this" node rank.
*/

int	pscu_rklw(unsigned int this_rank, unsigned int comp_rank)
{
	return (comp_rank - this_rank);
}
