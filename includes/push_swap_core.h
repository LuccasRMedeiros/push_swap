/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_core.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 12:01:29 by lrocigno          #+#    #+#             */
/*   Updated: 2021/12/12 17:06:34 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Contain the core functions to sort.
*/

#ifndef PUSH_SWAP_CORE_H
# define PUSH_SWAP_CORE_H

# include "push_swap_core_moves.h"

void	psc_act(t_prog *prog, t_act *acts[4]);
int		psc_is_stack_a_move(t_act *pred);
int		psc_is_stack_b_move(t_act *pred);
void	psc_merge(t_prog *prog);
void	psc_observe(t_prog *prog, int obs[2][2]);
void	psc_predict(t_prog *p, int obs[2][2], t_act *preds[2]);

#endif
