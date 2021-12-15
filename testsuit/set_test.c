/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 15:50:42 by lrocigno          #+#    #+#             */
/*   Updated: 2021/12/15 12:50:37 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_testsuit.h"

/*
** Add a new test to the list of tests.
*/

t_test	**set_test(t_test *test, t_test **tests)
{
	size_t	n_tests = count_tests(tests);
	size_t	plus_one = n_tests + 1;
	t_test	**new_tests = calloc(plus_one + 1, sizeof(t_test **));

	size_t	cp_byte = 0;
	while (cp_byte < plus_one - 1 && tests[cp_byte])
	{
		new_tests[cp_byte] = tests[cp_byte];
		++cp_byte;
	}
	new_tests[cp_byte] = test;
	free(tests);

	return (new_tests);
}
