/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_moves_pb.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 14:22:54 by lrocigno          #+#    #+#             */
/*   Updated: 2021/11/11 17:14:32 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_moves.h"

/*
** Push the top item on stack B to the top of stack A.
*/

void	push_swap_moves_pb(t_dlist *stack_b, t_dlist *stack_a)
{
	ft_dlstinsert(stack_b->content, stack_a);
	ft_dlstdelone_circle(stack_b);
	printf("pb");
}
