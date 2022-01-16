/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 16:26:25 by lrocigno          #+#    #+#             */
/*   Updated: 2022/01/15 22:36:53 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap_error.h>
#include <push_swap_core.h>

/*
** Create a set of push_swap instructions.
*/

int	main(int argc, char **argv)
{
	int		*pre_stack;
	t_prog	*prog;

	if (argc <= 1)
		return (0);
	pse_check_args(argv);
	pre_stack = pse_try_parse_args(argc, argv);
	prog = init_prog(argc - 1, pre_stack);
	if (argc > 6)
		psc_de_radixsort(prog);
	else 
		psc_tournamentsort(prog);
	end_prog(&prog);
	return (0);
}
