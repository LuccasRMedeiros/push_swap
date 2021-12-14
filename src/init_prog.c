/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_prog.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 13:49:03 by lrocigno          #+#    #+#             */
/*   Updated: 2021/12/13 23:32:42 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

/*
*/

t_prog	*init_prog(int argc, char **argv)
{
	t_prog	*prog;

	prog = malloc(sizeof(*prog));
	if (!prog)
		return (NULL);
	prog->stack_a = new_stack(size);
	if (!prog->stack_a)
	{
		free(prog);
		return (NULL);
	}
	prog->a_size = size;
	prog->stack_b = new_stack(1);
	if (!prog->stack_b)
	{
		del_stack(prog->stack_a);
		free(prog);
		return (NULL);
	}
	prog->b_size = 0;
	init_limits(prog);
	return (prog);
}
