/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pscm_ra.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 23:50:32 by lrocigno          #+#    #+#             */
/*   Updated: 2022/01/15 10:41:19 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap_core_moves.h>

/*
** Shift up all the items on stack A.
*/

void	pscm_ra(t_prog **prog, t_stack **stk)
{
	t_prog	*aux;

	aux = *prog;
	aux->stack_a = aux->stack_a->next;
	*stk = aux->stack_a;
	ft_putendl_fd("ra", 1);
}
