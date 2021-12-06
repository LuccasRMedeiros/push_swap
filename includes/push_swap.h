/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 16:35:03 by lrocigno          #+#    #+#             */
/*   Updated: 2021/12/05 23:56:01 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Contain the base for all the program. Its dependencies, structures, enums, 
** unions and macros are declared here.
*/

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <libft.h>

/*
** Which index represent a stack observation.
*/

enum	e_stacks
{
	stk_a,
	stk_b,
};

/*
** Which index represents the each limit.
*/

enum	e_limits
{
	lower,
	greater,
};

/*
** Which index represent the item in comparison.
*/

enum	e_item
{
	item,
	next,
	nxt2,
	prev,
};

/*
** Which index represent the direction of a imperfection.
*/

enum	e_imperfection
{
	down,
	up,
};

/*
** The s_prog is a "header" to provide all the information the program need to
** sort the stack.
*/

typedef struct	s_prog
{
	int		*pre_stack;
	int		limits_a[2];
	int		limits_b[2];
	t_dlist	*stack_a;
	int		a_size;
	t_dlist	*stack_b;
	int		b_size;
}	t_prog;

/*
** The typedef t_act hold a pointer to function. As it is meant to be used to
** transport the push_swap_moves functions this typedef is a pointer to void
** type that receives a pointer to pointer to t_prog.
*/

typedef	void	(t_act)(t_prog **prog);

/*
** Functions for mainly initialization and destruction of structures objects.
*/

void	del_item(void *int_n);
void	end_prog(t_prog **prog);
t_prog	*init_prog(int *pre_stack, int size);

#endif
