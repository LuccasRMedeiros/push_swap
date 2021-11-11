/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_swaps_sb.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 01:34:09 by lrocigno          #+#    #+#             */
/*   Updated: 2021/11/11 01:38:45 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_swaps.h"

/*
** Execute a sb (swap the two items at the top of stack b).
*/

void	push_swap_swaps_sb(t_dlist *stack_b)
{
	void	*aux;

	aux = stack_b->content;
	stack_b->content = stack_b->next->content;
	stack_b->next->content = aux;
	printf("sb\n");
}
