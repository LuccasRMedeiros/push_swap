/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_core.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 12:01:29 by lrocigno          #+#    #+#             */
/*   Updated: 2022/01/08 10:27:58 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Contain the core functions to sort.
*/

#ifndef PUSH_SWAP_CORE_H
# define PUSH_SWAP_CORE_H

# include "push_swap_core_moves.h"

int		psc_find_next(
			t_stack *stk,
			t_stack (*flow)(t_stack *),
			int (*seq)(size_t, size_t));
int		psc_is_stack_a_mv(t_act *mv);
int		psc_is_stack_b_mv(t_act *mv);
int		psc_is_both_mv(t_act *mv);
void	psc_merge(t_prog *prog);
void	psc_observe(t_prog *prog, int obs[2][2]);
void	psc_predict(t_prog *p, t_act *preds[5], int obs[2][2]);

#endif
