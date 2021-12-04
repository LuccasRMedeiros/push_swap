/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_prog.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 23:12:57 by lrocigno          #+#    #+#             */
/*   Updated: 2021/12/02 13:38:46 by lrocigno         ###   ########.fr       */
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
	if (!aux->pre_stack)
		return ;
	if (aux->stack_a)
		ft_dlstclear_circle(&aux->stack_a, del_item);
	if (aux->stack_b)
		ft_dlstclear_circle(&aux->stack_b, del_item);
	free(aux->pre_stack);
	aux->pre_stack = NULL;
	aux->a_size = 0;
	aux->b_size = 0;
	free(aux);
	aux = NULL;
	*prog = NULL;
}
