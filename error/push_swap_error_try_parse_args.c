/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_error_try_parse_args.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otakuocidental <otakuocidental@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 23:39:11 by lrocigno          #+#    #+#             */
/*   Updated: 2021/11/18 00:43:37 by otakuociden      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap_error.h>

/*
** Search for duplicates.
*/

static int	check_next(int next, int i, int *pre_stack)
{
	int		n;

	n = 0;
	while (n < i)
	{
		if (next == pre_stack[n])
		{
			ft_putstr_fd("Error\n", 1);
			exit(0);
		}
		++n;
	}
	return (next);
}

/*
** Covert all the strings into the argv array to integers and add them to a 
** array.
**
** During this process, it check if there are duplicates, if it is confirmed
** write "Error\n" to stdout.
**
** When everything works fine, it store all the values into stack a and return
** it.
*/

int	*push_swap_error_try_parse_args(int argc, char **argv)
{
	int		*pre_stack;
	int		next;
	int		i;

	pre_stack = ft_calloc(argc - 1, sizeof(int));
	if (!pre_stack)
	{
		ft_putstr_fd("Failed to allocate memory for pre_stack\n", 2);
		exit(0);
	}
	i = 1;
	pre_stack[0] = ft_atoi(argv[i]);
	while (i < argc - 1)
	{
		++i;
		next = ft_atoi(argv[i]);
		pre_stack[i - 1] = check_next(next, i - 1, pre_stack);
	}
	return (pre_stack);
}
