/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 20:39:54 by lrocigno          #+#    #+#             */
/*   Updated: 2021/12/13 23:42:11 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

/*
** Update the position of each node.
*/

static void	update_positions(t_stack **stack)
{
	t_stack	*aux;

	aux = *stack;
	while (aux->pos != 1)
	{
		aux = aux->next;
		aux->pos += 1;
	}
}

/*
** Simply create a new node to save some lines of code.
*/

static t_stack	*new_node(void)
{
	t_stack	*node;

	node = malloc(sizeof(*node));
	if (!node)
		return (NULL);
	node->pos = 1;
	return (node);
}

/*
** Add a item to the top of a stack, then update positions.
*/

t_stack	*add(int item, size_t rank, t_stack *stack)
{
	t_stack	*old_head;
	t_stack	*new_head;

	old_head = stack;
	new_head = new_node();
	if (!new_head)
		return (NULL);
	new_head->item = item;
	new_head->rank = rank;
	new_head->prev = old_head;
	new_head->next = old_head->next;
	old_head->next = new_head;
	update_positions(&new_head);
	return (new_head);
}
