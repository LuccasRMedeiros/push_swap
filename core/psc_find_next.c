/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psc_find_next.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 20:57:54 by lrocigno          #+#    #+#             */
/*   Updated: 2022/01/14 23:30:39 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap_core.h>

/*
** Count the distance between the item and its sucessor in the informed 
** sequence.
*/

int	psc_find_next(t_stack *stk, unsigned int s, unsigned int dch)
{
	unsigned int	node_n;

	node_n = 1;
	while (node_n <= s)
	{
		if (!((stk->rank >> dch) & 1))
			return (1);
		stk = stk->next;
		++node_n;
	}
	return (0);
}
