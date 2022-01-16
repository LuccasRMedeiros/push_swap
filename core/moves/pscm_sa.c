/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pscm_sa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 01:05:35 by lrocigno          #+#    #+#             */
/*   Updated: 2022/01/15 10:41:19 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap_core_moves.h>

/*
** Swap the two items at the top of stack A.
*/

void	pscm_sa(t_prog **prog, t_stack **stk)
{
	t_prog	*aux;
	int		old_top;
	size_t	old_rank;

	aux = *prog;
	old_top = aux->stack_a->item;
	old_rank = aux->stack_a->rank;
	aux->stack_a->item = aux->stack_a->next->item;
	aux->stack_a->rank = aux->stack_a->next->rank;
	aux->stack_a->next->item = old_top;
	aux->stack_a->next->rank = old_rank;
	*stk = aux->stack_a;
	ft_putendl_fd("sa", 1);
}

