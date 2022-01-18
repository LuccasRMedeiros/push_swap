/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pse_try_parse_args.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 23:39:11 by lrocigno          #+#    #+#             */
/*   Updated: 2022/01/17 22:57:34 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap_error.h>

/*
** Search for duplicates.
*/

static int	check_next(long int item, int i, int *pre_stack)
{
	int	n;
	int	cmp;

	n = 0;
	cmp = 0;
	while (n <= i)
	{
		if (i)
			cmp = pre_stack[n];
		if ((item == cmp && i) || (item < INT_MIN || item > INT_MAX))
		{
			free(pre_stack);
			pre_stack = NULL;
			ft_putendl_fd("Error", 1);
			exit(0);
		}
		++n;
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
	int			i;

	pre_stack = malloc(argc - 1 * sizeof(int));
	if (!pre_stack)
		exit(0);
	i = 0;
	while (i < argc - 1)
	{
		item = ft_atol(argv[i + 1]);
		pre_stack[i] = check_next(item, i, pre_stack);
		++i;
	}
	return (pre_stack);
}
