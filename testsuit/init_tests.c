/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tests.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 17:39:40 by lrocigno          #+#    #+#             */
/*   Updated: 2021/12/14 20:11:01 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_testsuit.h"

/*
** Create a instance of t_tests and inject the functions it needs in it.
*/

t_tests	init_tests(void)
{
	t_tests ret;
	t_test	*put[1];

	put[0] = NULL;
	ret.tests = put;
	ret.set_test = set_test;
	ret.count_tests = count_tests;

	return (ret);
}
