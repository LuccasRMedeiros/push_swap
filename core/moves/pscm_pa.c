/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pscm_pa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 21:52:10 by lrocigno          #+#    #+#             */
/*   Updated: 2022/01/11 23:57:58 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap_core_moves.h>

/*
** Push the top item on stack b to the top of stack a.
*/

void	pscm_pa(t_prog **prog)
{
	t_prog	*aux;

	aux = *prog;
	aux->stack_a = copy(aux->stack_b, aux->stack_a);
	aux->stack_b = pop(aux->stack_b);
	aux->a_size += 1;
	aux->b_size -= 1;
	ft_putendl_fd("pa", 1);
}
