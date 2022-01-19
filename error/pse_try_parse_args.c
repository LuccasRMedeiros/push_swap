/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pse_try_parse_args.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 23:39:11 by lrocigno          #+#    #+#             */
/*   Updated: 2022/01/18 23:23:58 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap_error.h>

/*
** Test if a number is valid in the context of pse_try_parse_args.
*/

static int	is_valid_number(long int item, size_t i, int *pre_stack)
{
	size_t	n;

	n = 0;
	if (item < INT_MIN || item > INT_MAX)
		return (0);
	while (n < i)
	{
		if (item == pre_stack[n])
			return (0);
		++n;
	}
	return (1);
}

/*
** See if there are duplicates ore values above or below the maximum and 
** minimum value for integers.
*/

static int	check_next(long int item, size_t i, int *pre_stack)
{
	if (!is_valid_number(item, i, pre_stack))
	{
		free(pre_stack);
		pre_stack = NULL;
		ft_putendl_fd("Error", 1);
		exit(0);
	}
	return (item);
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
	int			*pre_stack;
	size_t		i;

	pre_stack = malloc(sizeof(int) * (argc - 1));
	if (!pre_stack)
		exit(0);
	i = 0;
	while (i < (size_t)argc - 1)
	{
		item = ft_atol(argv[i + 1]);
		pre_stack[i] = check_next(item, i, pre_stack);
		++i;
	}
	return (pre_stack);
}
