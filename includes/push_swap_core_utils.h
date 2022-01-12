/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_core_utils.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 11:44:11 by lrocigno          #+#    #+#             */
/*   Updated: 2022/01/09 23:52:33 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Helper for pus_swap_core functions.
*/

#ifndef PUSH_SWAP_CORE_UTILS_H
# define PUSH_SWAP_CORE_UTILS_H

# include "push_swap.h"

int		pscu_inlmt(int dist, int threshold);
t_stack	*pscu_fnxt(t_stack *stk);
t_stack	*pscu_fprv(t_stack *stk);
int		pscu_is_both_mv(t_act *mv);
int		pscu_is_stack_a_mv(t_act *mv);
int		pscu_is_stack_b_mv(t_act *mv);
int		pscu_rkhg(unsigned int this_rank, unsigned int comp_rank);
int		pscu_rklw(unsigned int this_rank, unsigned int comp_rank);

#endif
