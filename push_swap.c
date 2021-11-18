/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otakuocidental <otakuocidental@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 16:26:25 by lrocigno          #+#    #+#             */
/*   Updated: 2021/11/18 00:36:44 by otakuociden      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap_error.h>

/*
** Uses sort algorithm to create a set of push_swap instructions.
*/

int	main(int argc, char **argv)
{
	int	*pre_stack;

	if (argc <= 1)
		return (0);
	push_swap_error_check_args(argv);
	pre_stack = push_swap_error_try_parse_args(argc, argv);
	for (int i = 0; i < argc - 1; ++i)
	{
		ft_putnbr_fd(pre_stack[i], 1);
		write(1, "\n", 1);
	}
	ft_putstr_fd("=========================DONE=========================\n", 1);
	free(pre_stack);
	return (0); 
}