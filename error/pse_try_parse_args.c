/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pse_try_parse_args.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 23:39:11 by lrocigno          #+#    #+#             */
/*   Updated: 2022/01/04 15:27:11 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap_error.h>

/*
** Search for duplicates.
*/

static int	check_next(long int next, int i, int *pre_stack)
{
	int		n;

	n = 0;
	while (n < i)
	{
		if (next == pre_stack[n] || (next < INT_MIN || next > INT_MAX))
		{
			free(pre_stack);
			ft_putendl_fd("Error", 1);
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
** When everything works fine, it store all the values into a int array and
** return it.
*/

int	*pse_try_parse_args(int argc, char **argv)
{
	long int	item;
	long int	next;
	int			*pre_stack;
	int			i;

	pre_stack = ft_calloc(argc - 1, sizeof(int));
	if (!pre_stack)
	{
		ft_putendl_fd("Failed to allocate memory for pre_stack", 2);
		exit(0);
	}
	i = 1;
	item = ft_atol(argv[i]);
	if (item >= INT_MIN && item <= INT_MAX)
		pre_stack[0] = item;
	while (i < argc - 1)
	{
		++i;
		next = ft_atol(argv[i]);
		pre_stack[i - 1] = check_next(next, i - 1, pre_stack);
	}
	return (pre_stack);
}
