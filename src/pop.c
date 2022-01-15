/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 11:42:50 by lrocigno          #+#    #+#             */
/*   Updated: 2022/01/14 14:56:37 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

/*
** Delete one node from the stack src then return it.
*/

t_stack	*pop(t_stack *src)
{
	t_stack	*pop;

	pop = src;
	if (pop != pop->next)
	{
		src = src->next;
		src->prev = src->prev->prev;
		src->prev->next = src;
		pop->next = pop;
		pop->prev = pop;
		del_stack(pop);
	}
	else
	{
		pop->item = 0;
		pop->rank = -1;
	}
	return (src);
}
