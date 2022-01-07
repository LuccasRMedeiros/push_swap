/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 11:38:25 by lrocigno          #+#    #+#             */
/*   Updated: 2022/01/03 23:41:56 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

/*
** Copy a node from stack src to stack dst then return dst.
*/

t_stack	*copy(t_stack *src, t_stack *dst)
{
	t_stack	*copy;

	copy = new_stack(1);
	copy->item = src->item;
	copy->rank = src->rank;
	copy->next = dst;
	copy->prev = dst->prev;
	copy->prev->next = copy;
	dst->prev = copy;
	return (copy);
}
