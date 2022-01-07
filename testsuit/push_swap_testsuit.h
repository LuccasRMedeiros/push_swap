/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_testsuit.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 01:17:10 by lrocigno          #+#    #+#             */
/*   Updated: 2022/01/04 14:10:25 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Includes all the dependencies, difines the macros, enums, structs and what
** else the tester needs.
*/

#ifndef PUSH_SWAP_TESTSUIT_H
# define PUSH_SWAP_TESTSUIT_H

# include <signal.h>
# include <stdio.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>

# include <push_swap_error.h>

typedef int	(t_test)(void);

size_t	count_tests(t_test **tests);
t_test	**set_test(t_test *test, t_test **tests);
t_test	**init_tests(void);

#endif
