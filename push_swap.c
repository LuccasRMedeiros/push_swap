/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 16:26:25 by lrocigno          #+#    #+#             */
/*   Updated: 2021/12/04 01:28:27 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap_error.h>
#include <push_swap_core.h>

static void	print_stack(t_prog *prog)
{
	t_dlist	*stack_a = prog->stack_a;
	t_dlist *tail = prog->stack_a->prev;
	while (stack_a != tail)
	{
		printf("\e[1;31m%i\e[0m\n", *(int *)stack_a->content);
		stack_a = stack_a->next;
	}
	printf("\e[1;31m%i\e[0m\n", *(int *)stack_a->content);
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
	psc_act(prog);
	print_stack(prog);
	end_prog(&prog);
	return (0); 
}
