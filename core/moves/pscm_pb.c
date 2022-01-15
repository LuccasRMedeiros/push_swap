/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pscm_pb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 21:52:10 by lrocigno          #+#    #+#             */
/*   Updated: 2022/01/14 21:52:27 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap_core_moves.h>

/*
** Push the top item on stack a to the top of stack b.
*/

void	pscm_pb(t_prog **prog)
{
	t_prog	*aux;

	aux = *prog;
	aux->stack_b = copy(aux->stack_a, aux->stack_b);
	aux->stack_a = pop(aux->stack_a);
	if (aux->stack_b->next->rank == -1)
		aux->stack_b = pop(aux->stack_b->next);
	aux->a_size -= 1;
	aux->b_size += 1;
	ft_putendl_fd("pb", 1);
}
