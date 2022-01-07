/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 11:42:50 by lrocigno          #+#    #+#             */
/*   Updated: 2022/01/03 23:41:56 by lrocigno         ###   ########.fr       */
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
	src = src->next;
	src->prev = src->prev->prev;
	src->prev->next = src;
	pop->next = pop;
	pop->prev = pop;
	del_stack(pop);
	return (src);
}
