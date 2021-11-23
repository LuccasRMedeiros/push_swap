/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psc_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 11:28:32 by lrocigno          #+#    #+#             */
/*   Updated: 2021/11/23 13:46:35 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap_core.h>

/*
** Look at stack A and B and execute a series of movement till it terminates to 
** sort the stack A.
*/

void	psc_sort(t_prog *prog)
{
	int	note;

	note = psc_look(prog);
	if (!note)
		return ;
	psc_execute(prog, psm_rra);
	psc_execute(prog, psm_rra);
	psc_execute(prog, psm_sa);
	psc_execute(prog, psm_ra);
	psc_execute(prog, psm_ra);
	psc_sort(prog);
}
