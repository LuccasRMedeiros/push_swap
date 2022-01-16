/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pscu_flwnx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 11:10:36 by lrocigno          #+#    #+#             */
/*   Updated: 2022/01/16 11:51:41 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap_core_utils.h>

/*
** Lambda function. Return if the next rank is greater than the actual.
*/

int	pscu_flwnx(t_stack *stk)
{
	return (stk->next->rank < stk->rank);
}
