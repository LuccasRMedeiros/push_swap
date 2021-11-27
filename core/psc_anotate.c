/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psc_anotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 16:04:59 by lrocigno          #+#    #+#             */
/*   Updated: 2021/11/27 01:17:08 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap_core.h>

/*
** Check the stack B from tail to head.
*/

static int	imp_up_b(int sz, t_dlist *stack_b)
{
	t_dlist	*head;
	int		note;

	if (!stack_b->content)
		return (0);
	head = stack_b->next;
	note = sz;
	while (stack_b != head)
	{
		if (*(int *)stack_b->content > *(int *)stack_b->prev->content)
			--note;
		else
			note = sz;
		stack_b = stack_b->prev;
	}
	return (note);
}

/*
** Check the stack B from head to tail.
*/

static int	imp_down_b(int sz, t_dlist *stack_b)
{
	t_dlist	*tail;
	int		note;

	if (!stack_b->content)
		return (0);
	tail = stack_b->prev;
	note = sz;
	while (stack_b != tail)
	{
		if (*(int *)stack_b->content > *(int *)stack_b->next->content)
			--note;
		else
			note = sz;
		stack_b = stack_b->next;
	}
	return (note);
}

/*
** Check the stack A from tail to head.
*/

static int	imp_up_a(int sz, t_dlist *stack_a)
{
	t_dlist	*head;
	int		note;

	if (!stack_a->content)
		return (0);
	head = stack_a->next;
	note = sz;
	while (stack_a != head)
	{
		if (*(int *)stack_a->content > *(int *)stack_a->prev->content)
			--note;
		else
			note = sz;
		stack_a = stack_a->prev;
	}
	return (note);
}

/*
** Check the stack A from head to tail.
*/

static int	imp_down_a(int sz, t_dlist *stack_a)
{
	t_dlist	*tail;
	int		note;

	if (!stack_a->content)
		return (0);
	tail = stack_a->prev;
	note = sz;
	while (stack_a != tail)
	{
		if (*(int *)stack_a->content < *(int *)stack_a->next->content)
			--note;
		else
			note = sz;
		stack_a = stack_a->next;
	}
	return (note);
}

/*
** Look to a stack from up to down and the reverse way, in the end it returns a
** notation telling how much imperfections there are in the stacks.
**
** The imperfection is a pair of disordend values and the objective of a
** notation is to tell in which direction there are more imperfections. To do
** this the function read all the items of the stack, for each item that is in a
** expected order (for stack A is low value above a greater one, and in stack B
** is a great value above a lower one), a counter that start with the size of
** the stack it is reading decrease by one, when it find a imperfection its
** value resets.
**
** In the end, it return a notation.
*/

void psc_anotate(t_prog *prog, int notation[4])
{
	notation[0] = imp_down_a(prog->stack_size, prog->stack_a);
	notation[1] = imp_up_a(prog->stack_size, prog->stack_a->prev);
	notation[2] = imp_down_b(prog->stack_size, prog->stack_b);
	notation[3] = imp_up_b(prog->stack_size, prog->stack_b->prev);
}
