/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_moves_pa.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 14:22:54 by lrocigno          #+#    #+#             */
/*   Updated: 2021/11/11 17:14:32 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_moves.h"

/*
** Push the top item on stack A to the top of stack B.
*/

void	push_swap_moves_pa(t_dlist *stack_a, t_dlist *stack_b)
{
	ft_dlstinsert(stack_a->content, stack_b);
	ft_dlstdelone_circle(stack_a);
	printf("pa");
}
