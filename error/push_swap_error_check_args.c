/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_error_check_args.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otakuocidental <otakuocidental@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 14:52:36 by lrocigno          #+#    #+#             */
/*   Updated: 2021/11/17 15:43:00 by otakuociden      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap_error.h>

/*
** Check for wrong arguments (letters, non integer numbers, duplicates etc.).
**
** Case it find any problem it will write "Error\n" on stdout and will exit with
** 0.
*/

void	push_swap_error_check_args(char **argv)
{
	int	n;
	int	i;

	n = 1;
	i = 0;
	while (argv[n])
	{
		while (argv[n][i])
		{
			if (!ft_isdigit(argv[n][i]))
			{
				ft_putstr_fd("Error\n", 1);
				exit(0);
			}
			++i;
		}
		i = 0;
		++n;
	}
}
