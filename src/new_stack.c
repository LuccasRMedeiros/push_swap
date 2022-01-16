/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 14:33:28 by lrocigno          #+#    #+#             */
/*   Updated: 2022/01/16 13:38:37 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

/*
** Recursively create all the asked nodes of the stack.
*/

static t_stack	*create_nodes(unsigned int n_nodes, t_stack *prev)
{
	t_stack	*new;

	new = malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->item = 0;
	new->rank = -1;
	new->prev = prev;
	if (n_nodes > 1)
	{
		new->next = create_nodes(n_nodes - 1, new);
		if (!new->next)
		{
			free(new);
			return (NULL);
		}
	}
	return (new);
}

/*
** Create a new t_stack with the amount of nodes informed, circle it and return
** the new stack.
*/

t_stack	*new_stack(unsigned int n_nodes)
{
	t_stack			*new;
	unsigned int	i;
	t_stack			*head;
	t_stack			*tail;

	new = create_nodes(n_nodes, NULL);
	if (!new)
		return (NULL);
	i = 0;
	head = new;
	while (i < n_nodes - 1)
	{
		new = new->next;
		++i;
	}
	tail = new;
	tail->next = head;
	head->prev = tail;
	new = head;
	return (new);
}
