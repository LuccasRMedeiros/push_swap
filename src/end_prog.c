/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_prog.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 23:12:57 by lrocigno          #+#    #+#             */
/*   Updated: 2021/11/21 21:33:12 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

/*
** Clean the stacks.
*/

void	end_prog(t_prog **prog)
{
	int		*pre_stack;
	t_dlist	*stack_a;
	t_dlist	*stack_b;

	pre_stack = (*prog)->pre_stack;
	stack_a = (*prog)->stack_a;
	stack_b = (*prog)->stack_b;
	if (!pre_stack)
		return ;
	if (stack_a)
		ft_dlstclear_circle(&stack_a, del_item);
	if (stack_b)
		ft_dlstclear_circle(&stack_b, del_item);
	free(pre_stack);
	free(*prog);
	pre_stack = NULL;
	*prog = NULL;
}
