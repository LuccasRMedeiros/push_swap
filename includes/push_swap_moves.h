/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_moves.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 01:03:06 by lrocigno          #+#    #+#             */
/*   Updated: 2021/11/22 12:16:50 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Execute push and swap operations and output them to the terminal.
*/

#ifndef PUSH_SWAP_MOVES_H
# define PUSH_SWAP_MOVES_H

# include "push_swap.h"

void	psm_pa(t_prog **prog);
void	psm_pb(t_prog **prog);
void	psm_ra(t_prog **prog);
void	psm_rb(t_prog **prog);
void	psm_rr(t_prog **prog);
void	psm_rra(t_prog **prog);
void	psm_rrb(t_prog **prog);
void	psm_rrr(t_prog **prog);
void	psm_sa(t_prog **prog);
void	psm_sb(t_prog **prog);
void	psm_ss(t_prog **prog);

#endif
