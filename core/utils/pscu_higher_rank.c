/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pscu_higher_rank.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 11:03:52 by lrocigno          #+#    #+#             */
/*   Updated: 2022/01/08 11:43:43 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap_core_utils.h>

/*
** Return the diference between the "this" node rank and "comp" node rank.
*/

int	pscu_higher_rank(size_t this_rank, size_t comp_rank)
{
	return (this_rank - comp_rank);
}
