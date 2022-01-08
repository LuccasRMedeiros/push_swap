/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psc_find_next.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 20:57:54 by lrocigno          #+#    #+#             */
/*   Updated: 2022/01/08 10:28:58 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap_core.h>

/*
** Count the distance between the item and its sucessor in the informed 
** sequence.
*/

int	psc_find_next(
		t_stack *stk,
		t_stack (*flow)(t_stack *),
		int (*seq)(size_t, size_t))
{
	int		dist;
	size_t	this_rank;
	t_stack	*head;

	dist = 0;
	this_rank = stk->rank;
	stk = flow(stk);
	while (stk != head)
	{
		if (seq(stk->rank, flow(stk)->rank) == 1)
			return (dist);
		++dist;
		stk = flow(stk);
		++node_n;
	}
	return (dist);
}
