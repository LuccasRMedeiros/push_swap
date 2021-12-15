/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tests.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 17:39:40 by lrocigno          #+#    #+#             */
/*   Updated: 2021/12/15 12:07:49 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_testsuit.h"

/*
** Create a instance of t_tests and inject the functions it needs in it.
*/

t_test	**init_tests(void)
{
	return (calloc(1, sizeof(t_test **)));
}
