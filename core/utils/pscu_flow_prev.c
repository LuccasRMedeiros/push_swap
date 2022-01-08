/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pscu_flow_next.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 10:54:24 by lrocigno          #+#    #+#             */
/*   Updated: 2022/01/08 11:03:21 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap_core_utils.h>

/*
** Go to the previous node.
*/

t_stack	*pscu_flow_prev(t_stack *stk)
{
	stk = stk->prev;
	return (stk);
}
