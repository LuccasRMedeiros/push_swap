/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psc_find_next_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 20:57:54 by lrocigno          #+#    #+#             */
/*   Updated: 2022/01/06 22:07:42 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap_core.h>

/*
** Count the distance between the top item on stack A and its ranked successor,
** then return a int containing the result.
*/

int	psc_find_next_a(t_stack *a, size_t lts[2], size_t a_size)
{
	int		dist;
	size_t	this_rank;
	size_t	node_n;

	dist = 0;
	this_rank = a->rank;
	a = a->next;
	node_n = 2;
	while (node_n <= a_size)
	{
		if ((a->rank - this_rank == 1)
				|| (this_rank == lts[g] && a->rank == lts[l]))
			return (dist);
		++dist;
		a = a->next;
		++node_n;
	}
	return (dist);
}
