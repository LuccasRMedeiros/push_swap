/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 20:13:49 by lrocigno          #+#    #+#             */
/*   Updated: 2021/12/14 01:51:14 by lrocigno         ###   ########.fr       */
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
		aux->pos -= 1;
		aux = aux->next;
	}
}

/*
** Remove one node and relink the list again.
*/

t_stack	*pop(t_stack *stack)
{
	t_stack	*next;
	t_stack	*prev;

	next = stack->next;
	if (stack == next)
	{
		stack->item = 0;
		return (stack);
	}
	prev = stack->prev;
	prev->next = next;
	next->prev = prev;
	ft_bzero(stack, sizeof(*stack));
	free(stack);
	update_positions(&next);
	return (next);
}
