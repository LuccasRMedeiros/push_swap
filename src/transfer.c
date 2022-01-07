/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transfer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 20:39:54 by lrocigno          #+#    #+#             */
/*   Updated: 2021/12/28 21:28:59 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

/*
** Transfer one node from one stack to another stack.
*/

void	transfer(t_stack **node, t_stack **dst)
{
	t_stack	*s_node;
	t_stack	*s_dst;
	t_stack	*copy;

	copy = *node;
	s_node = *node;
	s_dst = *dst;
	s_node = s_node->next;
	s_node->prev = s_node->prev->prev;
	s_node->prev->next = s_node;
	copy->next = s_dst;
	copy->prev = s_dst->prev;
	s_dst->prev = copy;
	s_dst = s_dst->prev;
}
