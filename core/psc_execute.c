/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psc_execute.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 00:09:34 by lrocigno          #+#    #+#             */
/*   Updated: 2021/11/23 00:42:29 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap_core.h>

/*
** Execute a action.
*/

void	psc_execute(t_prog *prog, void (action)(t_prog **))
{
	action(&prog);
	psc_look(prog);
}
