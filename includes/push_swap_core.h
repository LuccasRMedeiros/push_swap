/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_core.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 12:01:29 by lrocigno          #+#    #+#             */
/*   Updated: 2022/01/07 23:58:10 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Contain the core functions to sort.
*/

#ifndef PUSH_SWAP_CORE_H
# define PUSH_SWAP_CORE_H

# include "push_swap_core_moves.h"

int		psc_find_next_a(t_stack *a, size_t lts[2], size_t a_size);
int		psc_find_next_b(t_stack *b, size_t lts[2], size_t b_size);
int		psc_is_stack_a_mv(t_act *mv);
int		psc_is_stack_b_mv(t_act *mv);
int		psc_is_both_mv(t_act *mv);
void	psc_merge(t_prog *prog);
void	psc_observe(t_prog *prog, int obs[2][2]);
void	psc_predict(t_prog *p, t_act *preds[5], int obs[2][2]);

#endif
