/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psc_tournament.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 13:23:43 by lrocigno          #+#    #+#             */
/*   Updated: 2021/12/12 13:34:03 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap_core.h>

/*
** Make a tournament to decide the order of each item and return the rank.
**
** The rank will be a pointer to pointer of void where the first pointer index
** represent the rank itself and the second pointer represents the pointer of
** the item.
*/

void	**psc_tournament(t_prog *prog)
{
	void	**rank;

	rank = ft_calloc()
