/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pse_check_args.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 14:52:36 by lrocigno          #+#    #+#             */
/*   Updated: 2022/01/16 13:30:21 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap_error.h>

/*
** Verify if it is a valid number.
*/

static int	is_valid_number(char *arg)
{
	size_t	c;
	size_t	len;
	int		isdigit;

	c = 0;
	len = ft_strlen(arg);
	isdigit = 0;
	while (c < len)
	{
		isdigit = ft_isdigit(arg[c]);
		if (!isdigit && (arg[c] == '-' || arg[c] == '+'))
		{
			if (c > 0)
				if (ft_isdigit(arg[c - 1])
					|| (arg[c] == '-' && arg[c - 1] == '+')
					|| (arg[c] == '+' && arg[c - 1] == '-'))
					return (0);
		}
		else if (!isdigit)
			return (0);
		++c;
	}
	return (1);
}

/*
** Check for wrong arguments (letters, non integer numbers, duplicates etc.).
**
** Case it find any problem it will write "Error\n" on stdout and will exit with
** 0.
*/

void	pse_check_args(char **argv)
{
	int	n;
	int	i;

	n = 1;
	i = 0;
	while (argv[n])
	{
		while (argv[n][i])
		{
			if (!is_valid_number(argv[n]))
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
