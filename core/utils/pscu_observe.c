/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pscu_observe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 16:04:59 by lrocigno          #+#    #+#             */
/*   Updated: 2022/01/16 12:12:32 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap_core_utils.h>

/*
** Return if there are misplaced items. The "flow" argument can be flwnx or
** flwpv depending on what the program expect to observe, for example as in
** stack B the items must be placed in decresent order we test it with flwpv
** because the next must be lower than the actual rank.
*/

int	pscu_observe(t_stack *stk, t_flow *flow)
{
	t_stack	*head;

	head = stk;
	while (stk->next != head)
	{
		if (flow(stk))
			return (1);
		stk = stk->next;
	}
	return (0);
}
