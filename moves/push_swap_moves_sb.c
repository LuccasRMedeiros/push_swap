/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_moves_sb.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 01:34:09 by lrocigno          #+#    #+#             */
/*   Updated: 2021/11/11 17:14:32 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_moves.h"

/*
** Swap the two items at the top of stack B.
*/

void	push_swap_moves_sb(t_dlist *stack_b)
{
	void	*aux;

	aux = stack_b->content;
	stack_b->content = stack_b->next->content;
	stack_b->next->content = aux;
	printf("sb\n");
}
