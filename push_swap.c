/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 16:26:25 by lrocigno          #+#    #+#             */
/*   Updated: 2021/12/01 00:07:56 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap_error.h>
#include <push_swap_core.h>

static void print_stacks(t_prog *prog)
{
	t_dlist *stack = prog->stack_a;
	t_dlist *tail = stack->prev;

	int item = 0;

	while (stack != tail)
	{
		item = *(int *)stack->content;
		printf("A: \e[1;33m%i\e[0m\n", item);
		stack = stack->next;
	}
	item = *(int *)stack->content;
	printf("A: \e[1;33m%i\e[0m\n", item);
}

/*
** Uses sort algorithm to create a set of push_swap instructions.
*/

int	main(int argc, char **argv)
{
	int		*pre_stack;
	t_prog	*prog;

	if (argc <= 1)
		return (0);
	pse_check_args(argv);
	pre_stack = pse_try_parse_args(argc, argv);
	prog = init_prog(pre_stack, argc - 1);
	print_stacks(prog);
	psc_sort(prog);
	print_stacks(prog);
	end_prog(&prog);
	return (0); 
}
