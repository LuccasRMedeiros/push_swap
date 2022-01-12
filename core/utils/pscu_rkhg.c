/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pscu_rkhg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 11:03:52 by lrocigno          #+#    #+#             */
/*   Updated: 2022/01/09 23:53:57 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap_core_utils.h>

/*
** Return the diference between the "this" node rank and "comp" node rank.
*/

int	pscu_rkhg(unsigned int this_rank, unsigned int comp_rank)
{
	return (this_rank - comp_rank);
}
