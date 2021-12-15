/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_testsuit.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 01:17:10 by lrocigno          #+#    #+#             */
/*   Updated: 2021/12/15 00:19:16 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Includes all the dependencies, difines the macros, enums, structs and what
** else the tester needs.
*/

#ifndef PUSH_SWAP_TESTSUIT_H
# define PUSH_SWAP_TESTSUIT_H

# include <stdio.h>
# include <push_swap.h>

typedef int	(t_test)(void);

void	set_test(t_test *test, t_test ***tests);
size_t	count_tests(t_test **tests);

#endif
