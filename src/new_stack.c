/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 14:33:28 by lrocigno          #+#    #+#             */
/*   Updated: 2021/12/14 00:29:57 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

/*
** Recursively create all the asked nodes of the stack.
*/

static t_stack	*create_nodes(size_t n_nodes, size_t pos, t_stack *prev)
{
	t_stack	*new;

	new = malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->item = 0;
	new->pos = pos;
	new->rank = 0;
	new->prev = prev;
	if (n_nodes > 1)
	{
		new->next = create_nodes(n_nodes - 1, pos + 1, new);
		if (!new->next)
		{
			free(new);
			return (NULL);
		}
	}
	return (new);
}

/*
** Create a new t_stack with the amount of nodes informed, create a circular
** reference and return the new stack.
*/

t_stack	*new_stack(size_t n_nodes)
{
	t_stack	*new;
	t_stack	*head;
	t_stack	*tail;

	new = create_nodes(n_nodes, 1, NULL);
	if (!new)
		return (NULL);
	head = new;
	while (new->pos != n_nodes)
		new = new->next;
	tail = new;
	tail->next = head;
	head->prev = tail;
	new = head;
	return (new);
}
