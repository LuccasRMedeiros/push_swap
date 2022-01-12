/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_core.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 12:01:29 by lrocigno          #+#    #+#             */
/*   Updated: 2022/01/12 00:10:21 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Contain the core functions to sort.
*/

#ifndef PUSH_SWAP_CORE_H
# define PUSH_SWAP_CORE_H

# include "push_swap_core_moves.h"
# include "push_swap_core_utils.h"

void	psc_find_next(t_prog *prog, int dsts[2], unsigned int dch);
void	psc_merge(t_prog *prog);
int		psc_observe(t_prog *prog);
void	psc_predict(t_prog *pg, t_act *preds[5], int dsts[2], unsigned int dch);

#endif
