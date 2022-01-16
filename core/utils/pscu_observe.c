/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pscu_observe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 16:04:59 by lrocigno          #+#    #+#             */
/*   Updated: 2022/01/15 22:33:33 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap_core_utils.h>

/*
** Look for misplaced items.
*/

int	pscu_observe(t_prog *prog)
{
	t_stack			*a;
	unsigned int	node_n;

	a = prog->stack_a;
	node_n = 1;
	while (node_n < prog->a_size)
	{
		if (a->rank > a->next->rank)
			return (1);
		a = a->next;
		++node_n;
	}
	return (0);
}
