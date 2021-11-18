/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 18:48:54 by lrocigno          #+#    #+#             */
/*   Updated: 2021/11/17 14:18:43 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

/*
** Find the tail of the list and return it.
*/

static t_stack	*new_stack_tail(t_dlist *list)
{
	while (list->next)
		list = list->next;
	return (list);
}

/*
** Create a new stack.
*/

t_stack	*new_stack(char **el)
{
	int		n_el;
	t_stack	*new;

	n_el = 0;
	new->list = ft_dlstnew(el[0]);
	new->head = new->list;
	while (el[n_el])
	{
		ft_dlstadd(el[n_el], &new);
		++n_el;
	}
	new->tail = new_stack_tail(new->list);
	new->list = ft_dlstcircle(new->list);
	return (new);
}
