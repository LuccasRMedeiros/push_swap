/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_moves.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 01:03:06 by lrocigno          #+#    #+#             */
/*   Updated: 2021/11/11 23:55:47 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Execute push and swap operations and output them to the terminal.
*/

#ifndef PUSH_SWAP_SWAPS_H
# define PUSH_SWAP_SWAPS_H

# include <push_swap.h>

void	push_swap_moves_sa(t_dlist *stack_a);
void	push_swap_moves_sb(t_dlist *stack_b);
void	push_swap_moves_ss(t_dlist *stack_a, t_dlist *stack_b);
void	push_swap_moves_pa(t_dlist *stack_a, t_dlist *stack_b);
void	push_swap_moves_pb(t_dlist *stack_b, t_dlist *stack_a);
t_dlist	*push_swap_moves_ra(t_dlist *stack_a);
void	push_swap_moves_rb(t_dlist **stack_b);

#endif
