/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pscu_find_next.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 20:57:54 by lrocigno          #+#    #+#             */
/*   Updated: 2022/01/15 11:46:50 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap_core.h>

/*
** Count the distance between the item and its sucessor in the informed 
** sequence.
*/

int	pscu_find_next(t_prog *prog, int dch, int is_b)
{
	unsigned int	node_n;
	unsigned int	size;
	t_stack			*stk;

	node_n = 1;
	size = prog->a_size;
	stk = prog->stack_a;
	if (is_b)
	{
		size = prog->b_size;
		stk = prog->stack_b;
	}
	while (node_n <= size)
	{
		if (((stk->rank >> dch) & 1) == is_b)
			return (1);
		stk = stk->next;
		++node_n;
	}
	return (0);
}
