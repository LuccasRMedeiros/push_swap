/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_limits.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 12:06:16 by lrocigno          #+#    #+#             */
/*   Updated: 2022/01/06 22:46:40 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

/*
** Find which is the first and the last rank present in the stack.
*/

void	find_limits(t_stack *stack, size_t lts[2], size_t s)
{
	t_stack	*aux;
	size_t	node_n;

	aux = stack;
	node_n = 1;
	if (!stack->rank)
	{
		lts[l] = 0;
		lts[g] = 0;
		return ;
	}
	lts[l] = aux->rank;
	lts[g] = aux->rank;
	while (node_n <= s)
	{
		if (aux->rank < lts[l])
			lts[l] = aux->rank;
		else if (aux->rank > lts[g])
			lts[g] = aux->rank;
		aux = aux->next;
		++node_n;
	}
}
