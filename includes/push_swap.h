/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 16:35:03 by lrocigno          #+#    #+#             */
/*   Updated: 2022/01/06 22:48:16 by lrocigno         ###   ########.fr       */
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
	a,
	b,
};

/*
** Which index represents the each limit.
*/

enum	e_limits
{
	l,
	g,
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
	prv2,
};

/*
** Which index represent the rank in comparison.
*/

enum	e_cmp
{
	t,
	n,
	p,
};

/*
** Which index represent the direction of a imperfection.
*/

enum	e_dir
{
	d,
	u,
};

/*
** Which index represent a action.
*/

enum	e_action
{
	act1,
	act2,
	await,
};

/*
** The s_stack is a double linked list like structure that not only points to it
** next and previous node but also carries it position in the tournament rank.
*/

typedef struct	s_stack
{
	int				item;
	size_t			rank;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

/*
** The s_prog is a "header" to provide all the information the program need to
** sort the stack.
*/

typedef struct	s_prog
{
	int		total_items;
	t_stack	*stack_a;
	t_stack	*stack_b;
	size_t	lts_a[2];
	size_t	lts_b[2];
	int		a_size;
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

t_stack	*copy(t_stack *src, t_stack *dst);
void	del_stack(t_stack *del);
void	end_prog(t_prog **prog);
void	find_limits(t_stack *stack, size_t lts[2], size_t s);
t_prog	*init_prog(int argc, int *pre_stack);
t_stack	*new_stack(size_t n_nodes);
t_stack	*pop(t_stack *src);

#endif
