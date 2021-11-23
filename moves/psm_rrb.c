/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psm_rrb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 23:50:32 by lrocigno          #+#    #+#             */
/*   Updated: 2021/11/22 00:09:23 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap_moves.h>

/*
** Shift down all the items on stack B.
*/

void	psm_rrb(t_prog **prog)
{
	t_prog	*aux;

	aux = *prog;
	aux->stack_b = aux->stack_b->prev;
	ft_putendl_fd("rrb", 1);
}
