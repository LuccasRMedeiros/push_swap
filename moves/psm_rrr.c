/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psm_rrr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 23:50:32 by lrocigno          #+#    #+#             */
/*   Updated: 2021/11/22 00:09:46 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap_moves.h>

/*
** Shift down all the items of both stacks.
*/

void	psm_rrr(t_prog **prog)
{
	t_prog	*aux;

	aux = *prog;
	aux->stack_a = aux->stack_a->prev;
	aux->stack_b = aux->stack_b->prev;
	ft_putendl_fd("rrr", 1);
}
