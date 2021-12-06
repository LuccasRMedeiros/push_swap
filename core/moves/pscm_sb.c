/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pscm_sb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 01:05:35 by lrocigno          #+#    #+#             */
/*   Updated: 2021/12/05 22:06:03 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap_core_moves.h>

/*
** Swap the two items at the top of stack B.
*/

void	pscm_sb(t_prog **prog)
{
	t_prog	*aux;
	void	*old_top;

	aux = *prog;
	old_top = aux->stack_b->content;
	aux->stack_b->content = aux->stack_b->next->content;
	aux->stack_b->next->content = old_top;
	ft_putendl_fd("sb", 1);
}

