/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pscm_ss.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 01:05:35 by lrocigno          #+#    #+#             */
/*   Updated: 2022/01/04 22:06:04 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap_core_moves.h>

/*
** Swap the two items at the top of both stacks.
*/

void	pscm_ss(t_prog **prog)
{
	t_prog	*aux;
	int		old_top_a;
	size_t	old_rank_a;
	int		old_top_b;
	size_t	old_rank_b;

	aux = *prog;
	old_top_a = aux->stack_a->item;
	old_rank_a = aux->stack_a->rank;
	old_top_b = aux->stack_b->item;
	old_rank_b = aux->stack_a->rank;
	aux->stack_a->item = aux->stack_a->next->item;
	aux->stack_a->rank = aux->stack_a->next->rank;
	aux->stack_b->item = aux->stack_b->next->item;
	aux->stack_b->rank = aux->stack_b->next->rank;
	aux->stack_a->next->item = old_top_a;
	aux->stack_a->next->rank = old_rank_a;
	aux->stack_b->next->item = old_top_b;
	aux->stack_b->next->rank = old_rank_b;
	ft_putendl_fd("ss", 1);
}

