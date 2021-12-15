/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_tests.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 15:55:40 by lrocigno          #+#    #+#             */
/*   Updated: 2021/12/15 00:24:59 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_testsuit.h"

/*
** Count the amount of tests on the test list.
*/

size_t	count_tests(t_test **tests)
{
	size_t	count = 0;
	t_test	**aux = tests;

	if (!tests)
		return (0);
	
	while (aux[count])
		++count;

	return (count);
}
