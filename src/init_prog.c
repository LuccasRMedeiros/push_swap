/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_prog.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 13:49:03 by lrocigno          #+#    #+#             */
/*   Updated: 2021/12/16 22:28:44 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

/*
** Place the items on pre_stack on stack_a, then delete the pre_stack.
*/

static void	init_stack_a(t_stack *stack, int *pre_stack)
{
	size_t	i;

	i = 0;
	while (i < stack_a->pos)
	{
		stack_a->item = pre_stack[i];
		stack_a = stack_a->next;
		++i;
	}
	ft_bzero(pre_stack, i);
	free(pre_stack);
}

/*
** Initialize a t_prog instance using the pre_stack formed during the check up
** of the arguments.
*/

t_prog	*init_prog(int argc, int *pre_stack)
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
	init_stack_a(prog->stack_a, pre_stack);
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
