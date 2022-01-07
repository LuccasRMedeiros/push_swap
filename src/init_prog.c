/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_prog.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 13:49:03 by lrocigno          #+#    #+#             */
/*   Updated: 2022/01/06 22:47:36 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

/*
** Make a item compete against all its successors, for each item that "loses" 
** its ranking will be increased by one.
*/

static void	tournament(t_stack *stack)
{
	t_stack	*head;
	t_stack	*challenger;
	t_stack	*challenged;

	head = stack;
	challenger = stack;
	challenged = stack->next;
	while (challenger->next != head)
	{
		while (challenged != head)
		{
			if (challenged->item < challenger->item)
				challenger->rank += 1;
			else
				challenged->rank += 1;
			challenged = challenged->next;
		}
		challenger = challenger->next;
		challenged = challenger->next;
	}
}

/*
** Place the items on pre_stack on stack_a, then delete the pre_stack.
*/

static void	init_stack_a(t_stack *stack_a, int *pre_stack, size_t s)
{
	size_t	i;

	i = 0;
	while (i < s)
	{
		stack_a->item = pre_stack[i];
		stack_a->rank = 1;
		stack_a = stack_a->next;
		++i;
	}
	ft_bzero(pre_stack, i);
	free(pre_stack);
	tournament(stack_a);
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
	prog->total_items = argc;
	prog->stack_a = new_stack(argc);
	if (!prog->stack_a)
	{
		free(prog);
		return (NULL);
	}
	prog->a_size = argc;
	init_stack_a(prog->stack_a, pre_stack, prog->a_size);
	prog->stack_b = new_stack(1);
	if (!prog->stack_b)
	{
		del_stack(prog->stack_a);
		free(prog);
		return (NULL);
	}
	prog->b_size = 0;
	find_limits(prog->stack_a, prog->lts_a, prog->a_size);
	find_limits(prog->stack_b, prog->lts_b, prog->b_size);
	return (prog);
}
