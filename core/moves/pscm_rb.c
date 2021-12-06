/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pscm_rb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 23:50:32 by lrocigno          #+#    #+#             */
/*   Updated: 2021/12/05 22:04:43 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap_core_moves.h>

/*
** Shift up all the items on stack B.
*/

void	pscm_rb(t_prog **prog)
{
	t_prog	*aux;

	aux = *prog;
	aux->stack_b = aux->stack_b->next;
	ft_putendl_fd("rb", 1);
}
