/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_prog.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 13:49:03 by lrocigno          #+#    #+#             */
/*   Updated: 2022/01/12 00:17:00 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

/*
** Count how many bits the max_rank number have. It means, how many 1's and 0's
** represent the number in a binary base.
*/

static unsigned int	count_bits_of_max_rank(unsigned int max_rank)
{
	unsigned int	max_bits;

	max_bits = 0;
	while (max_rank >> max_bits != 0)
		++max_bits;
	return (max_bits);
}

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

static void	init_stack_a(t_stack *stack_a, int *pre_stack, int s)
{
	size_t	i;

	i = 0;
	while (i < (size_t)s)
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
	prog->stack_a = new_stack(argc);
	if (!prog->stack_a)
	{
		free(prog);
		return (NULL);
	}
	init_stack_a(prog->stack_a, pre_stack, argc);
	prog->a_size = argc;
	prog->b_size = 0;
	prog->max_rank = argc;
	prog->max_bits = count_bits_of_max_rank(prog->max_rank);
	prog->stack_b = new_stack(1);
	if (!prog->stack_b)
	{
		del_stack(prog->stack_a);
		free(prog);
		return (NULL);
	}
	return (prog);
}
