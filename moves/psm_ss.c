/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psm_ss.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 01:05:35 by lrocigno          #+#    #+#             */
/*   Updated: 2021/11/21 23:56:12 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap_moves.h>

/*
** Swap the two items at the top of both stacks.
*/

void	psm_ss(t_prog **prog)
{
	t_prog	*aux;
	void	*old_top_a;
	void	*old_top_b;

	aux = *prog;
	old_top_a = aux->stack_a->content;
	old_top_b = aux->stack_b->content;
	aux->stack_a->content = aux->stack_a->next->content;
	aux->stack_b->content = aux->stack_b->next->content;
	aux->stack_a->next->content = old_top_a;
	aux->stack_b->next->content = old_top_b;
	ft_putendl_fd("ss", 1);
}

