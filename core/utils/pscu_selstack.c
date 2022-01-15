/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pscu_selstack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 02:12:45 by lrocigno          #+#    #+#             */
/*   Updated: 2022/01/15 02:18:07 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap_core_utils.h>

/*
** Return the other stack depending on value of is_b.
*/

t_stack	*pscu_selstack(t_prog *prog, int is_b)
{
	if (is_b)
		return (prog->stack_a);
	return (prog->stack_b);
}
