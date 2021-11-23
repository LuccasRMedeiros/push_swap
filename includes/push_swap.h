/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 16:35:03 by lrocigno          #+#    #+#             */
/*   Updated: 2021/11/23 13:28:54 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Contain the base for all the program. Its dependencies, structures, enums, 
** unions and macros are declared here.
*/

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <libft.h>

typedef struct	s_prog
{
	int		stack_size;
	int		*pre_stack;
	t_dlist	*stack_a;
	t_dlist	*stack_b;
}	t_prog;

void	del_item(void *int_n);
void	end_prog(t_prog **prog);
t_prog	*init_prog(int *pre_stack, int size);

#endif
