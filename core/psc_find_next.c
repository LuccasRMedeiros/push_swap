/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psc_find_next.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 20:57:54 by lrocigno          #+#    #+#             */
/*   Updated: 2022/01/12 00:10:20 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap_core.h>

/*
** Count the distance between the item and its sucessor in the informed 
** sequence.
*/

void	psc_find_next(t_prog *prog, int dists[2], unsigned int dch)
{
	t_stack			*a;
	unsigned int	node_n;

	a = prog->stack_a;
	node_n = 1;
	while (node_n <= prog->a_size)
	{
		if (((a->rank >> dch) & 1) == 0)
			break ;
		dists[d] += 1;
		a = a->next;
		++node_n;
	}
	node_n = 1;
	while (node_n <= prog->a_size)
	{
		if (((a->rank >> dch) & 1) == 0)
			return ;
		dists[u] += 1;
		a = a->prev;
		++node_n;
	}
}
