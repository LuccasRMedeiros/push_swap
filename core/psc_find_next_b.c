/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psc_find_next_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 21:13:09 by lrocigno          #+#    #+#             */
/*   Updated: 2022/01/06 22:07:14 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap_core.h>

/*
** Count the distance between the top item on stack B and its ranked successor,
** then return a int containing the result.
**
** It differs from find_next_a when it considers the ranked successor to be the
** one that have a lower rank than the top (or the greater limit case the top
** item is the lower rank).
*/

int	psc_find_next_b(t_stack *b, size_t lts[2], size_t b_size)
{
	int		dist;
	size_t	this_rank;
	size_t	node_n;

	dist = 0;
	this_rank = b->rank;
	b = b->next;
	node_n = 2;
	while (node_n <= b_size)
	{
		if ((this_rank - b->rank == 1)
				|| (this_rank == lts[l] && b->rank == lts[g]))
			return (dist);
		++dist;
		b = b->next;
		++node_n;
	}
	return (dist);
}
