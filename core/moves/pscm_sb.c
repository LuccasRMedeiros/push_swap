/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pscm_sb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 01:05:35 by lrocigno          #+#    #+#             */
/*   Updated: 2022/01/04 22:06:04 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap_core_moves.h>

/*
** Swap the two items at the top of stack B.
*/

void	pscm_sb(t_prog **prog)
{
	t_prog	*aux;
	int		old_top;
	size_t	old_rank;

	aux = *prog;
	old_top = aux->stack_b->item;
	old_rank = aux->stack_b->rank;
	aux->stack_b->item = aux->stack_b->next->item;
	aux->stack_b->rank = aux->stack_b->next->rank;
	aux->stack_b->next->item = old_top;
	aux->stack_b->next->rank = old_rank;
	ft_putendl_fd("sb", 1);
}

