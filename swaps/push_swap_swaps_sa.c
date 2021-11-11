/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_swaps_sa.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 01:05:35 by lrocigno          #+#    #+#             */
/*   Updated: 2021/11/11 01:38:45 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_swaps.h"

/*
** Execute a sa (swap the two items at the top of stack a).
*/

void	push_swap_swaps_sa(t_dlist *stack_a)
{
	void	*aux;

	aux = stack_a->content;
	stack_a->content = stack_a->next->content;
	stack_a->next->content = aux;
	printf("sa\n");
}
