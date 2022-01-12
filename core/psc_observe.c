/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psc_observe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 16:04:59 by lrocigno          #+#    #+#             */
/*   Updated: 2022/01/11 23:54:44 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap_core.h>

/*
** Look for items with even ranks because their representations in binary will
** always terminate in 0 (for example, 2 is in binary is 10, 4 is 1010).
*/

int	psc_observe(t_prog *prog)
{
	t_stack			*a;
	unsigned int	node_n;

	a = prog->stack_a;
	node_n = 1;
	while (node_n <= prog->a_size)
	{
		if (a->rank > a->next->rank)
			return (0);
		a = a->next;
		++node_n;
	}
	return (1);
}
