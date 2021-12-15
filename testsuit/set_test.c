/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 15:50:42 by lrocigno          #+#    #+#             */
/*   Updated: 2021/12/14 23:47:23 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_testsuit.h"

/*
** Add a new test to the list of tests.
*/

void	set_test(t_test *test, t_test ***tests)
{
	size_t	n_tests = count_tests(*tests);
	size_t	plus_one = n_tests > 0 ? n_tests + 1 : 2;
	t_test	*new_tests[plus_one];

	if (!*tests)
	{
		new_tests[0] = test;
		new_tests[1] = NULL;
		*tests = new_tests;
		return ;
	}

	size_t	cp_byte = 0;
	while (cp_byte < plus_one && *tests[cp_byte])
	{
		new_tests[cp_byte] = *tests[cp_byte];
		++cp_byte;
	}
	new_tests[cp_byte] = test;
	new_tests[cp_byte + 1] = NULL;
	*tests = new_tests;
}
