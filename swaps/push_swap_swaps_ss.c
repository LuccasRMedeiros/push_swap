/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_swaps_ss.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 01:35:17 by lrocigno          #+#    #+#             */
/*   Updated: 2021/11/11 01:38:45 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_swaps.h"

/*
** Execute a ss (swap the two items at the top of stack a and stack b).
*/

void	push_swap_swaps_sb(t_dlist *stack_a, t_dlist *stack_b)
{
	void	*aux_a;
	void	*aux_b

	aux_a = stack_a->content;
	aux_b = stack_b->content;
	stack_a->content = stack_a->next->content;
	stack_b->content = stack_b->next->content;
	stack_a->next->content = aux_a;
	stack_b->next->content = aux_b;
	printf("ss\n");
}
