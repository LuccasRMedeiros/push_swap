/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_error.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 14:27:46 by lrocigno          #+#    #+#             */
/*   Updated: 2021/11/22 12:04:58 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Verify and deal with errors caused by the user or the program itself.
*/

#ifndef PUSH_SWAP_ERROR_H
# define PUSH_SWAP_ERROR_H

# include "push_swap.h"

void	pse_check_args(char **argv);
int		*pse_try_parse_args(int argc, char **argv);

#endif
