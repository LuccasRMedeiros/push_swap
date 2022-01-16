/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psc_merge.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 11:33:27 by lrocigno          #+#    #+#             */
/*   Updated: 2022/01/16 11:56:28 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap_core.h>

/*
** Place all the items on stack B on top of stack A and them organize stack A.
*/

void	psc_merge(t_prog *prog)
{
	t_stack *dummy;

	dummy = NULL;
	while (prog->b_size)
		pscm_pa(&prog, &dummy);
	while (prog->stack_a->rank != 0)
		pscm_ra(&prog, &dummy);
}
