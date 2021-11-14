/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_moves_rb.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 16:04:16 by lrocigno          #+#    #+#             */
/*   Updated: 2021/11/11 23:35:44 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_moves.h"

/*
** Shift up all the items in the stack by one.
*/

void	push_swap_moves_rb(t_dlist **stack_b)
{
	*stack_b = (*stack_b)->next;
	printf("rb");
}
