/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psm_pa.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 21:52:10 by lrocigno          #+#    #+#             */
/*   Updated: 2021/12/01 14:21:34 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap_moves.h>

/*
** Push the top item on stack b to the top of stack a.
*/

void	psm_pa(t_prog **prog)
{
	t_prog	*aux;

	aux = *prog;
	if (aux->stack_a->content)
	{
		ft_dlstadd_circle(aux->stack_b->content, &aux->stack_a);
		aux->stack_a = aux->stack_a->prev;
	}
	else
		aux->stack_a->content = aux->stack_b->content;
	aux->stack_b = ft_dlstpop_circle(aux->stack_b);
	aux->a_size += 1;
	aux->b_size -= 1;
	ft_putendl_fd("pa", 1);
}
