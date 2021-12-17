/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 16:26:25 by lrocigno          #+#    #+#             */
/*   Updated: 2021/12/16 22:28:42 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap_error.h>
#include <push_swap_core.h>

/*
** Uses sort algorithm to create a set of push_swap instructions.
*/

int	main(int argc, char **argv)
{
	t_act	*acts[4];
	int		*pre_stack;
	t_prog	*prog;

	if (argc <= 1)
		return (0);
	acts[act1] = NULL;
	acts[act2] = NULL;
	acts[extr] = NULL;
	acts[wait] = NULL;
	pse_check_args(argv);
	pre_stack = pse_try_parse_args(argc, argv);
	prog = init_prog(argc - 1, pre_stack);
	psc_act(prog, acts);
	end_prog(&prog);
	return (0); 
}
