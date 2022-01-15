/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_core_utils.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 11:44:11 by lrocigno          #+#    #+#             */
/*   Updated: 2022/01/15 02:18:11 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Helper for pus_swap_core functions.
*/

#ifndef PUSH_SWAP_CORE_UTILS_H
# define PUSH_SWAP_CORE_UTILS_H

# include "push_swap.h"

int		pscu_find_next(t_stack *stk, unsigned int s, unsigned int dch);
int		pscu_is_stack_a_mv(t_act *mv);
int		pscu_is_stack_b_mv(t_act *mv);
t_stack	*pscu_selstack(t_prog *prog, int is_b);

#endif
