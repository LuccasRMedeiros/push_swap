/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_prog.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 23:12:57 by lrocigno          #+#    #+#             */
/*   Updated: 2022/01/16 13:38:10 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

/*
** Clean the stacks.
*/

void	end_prog(t_prog **prog)
{
	t_prog	*aux;

	aux = *prog;
	if (!aux)
		return ;
	if (aux->stack_a)
		del_stack(aux->stack_a);
	if (aux->stack_b)
		del_stack(aux->stack_b);
	ft_bzero(aux, sizeof(*aux));
	free(aux);
	*prog = NULL;
}
