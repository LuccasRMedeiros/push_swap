/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_core_utils.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 11:44:11 by lrocigno          #+#    #+#             */
/*   Updated: 2022/01/17 18:47:12 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Helper for pus_swap_core functions.
*/

#ifndef PUSH_SWAP_CORE_UTILS_H
# define PUSH_SWAP_CORE_UTILS_H

# include "push_swap.h"

int		pscu_calccred(t_prog *prog, t_act *mvs[3], int rots, int is_b);
int		pscu_find_next(t_prog *prog, int dch, int is_b);
int		pscu_flwnx(t_stack *stk);
int		pscu_flwpv(t_stack *stk);
void	pscu_invertmv(t_act *mvs[3]);
int		pscu_is_stack_a_mv(t_act *mv);
int		pscu_is_stack_b_mv(t_act *mv);
int		pscu_observe(t_stack *stk, t_flow *flow);
t_stack	*pscu_selstack(t_prog *prog, int is_b);

#endif
