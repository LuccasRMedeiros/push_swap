/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pscu_flwpv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 11:10:36 by lrocigno          #+#    #+#             */
/*   Updated: 2022/01/16 11:51:50 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap_core_utils.h>

/*
** Lambda function. Return if the next rank is lower than the actual.
*/

	int	pscu_flwpv(t_stack *stk)
{
	return (stk->next->rank > stk->rank);
}
