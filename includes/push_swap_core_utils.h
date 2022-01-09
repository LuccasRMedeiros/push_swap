/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_core_utils.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 11:44:11 by lrocigno          #+#    #+#             */
/*   Updated: 2022/01/08 12:13:30 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Helper for pus_swap_core functions.
*/

#ifndef PUSH_SWAP_CORE_UTILS_H
# define PUSH_SWAP_CORE_UTILS_H

t_stack	*pscu_flow_next(t_stack *stk);
t_stack	*pscu_flow_prev(t_stack *stk);
int		pscu_higher_rank(size_t this_rank, size_t comp_rank);
int		pscu_is_stack_a_mv(t_act *mv);
int		pscu_is_stack_b_mv(t_act *mv);
int		pscu_is_both_mv(t_act *mv);
int		pscu_lower_rank(size_t this_rank, size_t comp_rank);

#endif
