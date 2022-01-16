/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_core_moves.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 01:03:06 by lrocigno          #+#    #+#             */
/*   Updated: 2022/01/15 10:47:57 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Execute push and swap operations and output them to the terminal.
*/

#ifndef PUSH_SWAP_CORE_MOVES_H
# define PUSH_SWAP_CORE_MOVES_H

# include "push_swap.h"

void	pscm_pa(t_prog **prog, t_stack **stk);
void	pscm_pb(t_prog **prog, t_stack **stk);
void	pscm_ra(t_prog **prog, t_stack **stk);
void	pscm_rb(t_prog **prog, t_stack **stk);
void	pscm_rr(t_prog **prog, t_stack **stk);
void	pscm_rra(t_prog **prog, t_stack **stk);
void	pscm_rrb(t_prog **prog, t_stack **stk);
void	pscm_rrr(t_prog **prog, t_stack **stk);
void	pscm_sa(t_prog **prog, t_stack **stk);
void	pscm_sb(t_prog **prog, t_stack **stk);
void	pscm_ss(t_prog **prog, t_stack **stk);

#endif
