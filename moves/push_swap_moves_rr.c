/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_moves_rr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 16:04:16 by lrocigno          #+#    #+#             */
/*   Updated: 2021/11/11 23:07:53 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_moves.h"

/*
** Shift up all the items in the stack by one.
*/

t_dlist	*push_swap_moves_rb(t_dlist *stack_b)
{
	printf("rb");
	return (stack_b->next);
}
