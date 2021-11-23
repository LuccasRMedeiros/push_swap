/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psc_look.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 21:25:02 by lrocigno          #+#    #+#             */
/*   Updated: 2021/11/23 12:01:42 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap_core.h>

/*
** Look at each element of the stack B and notate where there are disordened
** numbers, in this case a value less than the next on the list (the tail is
** not considered).
*/

static void	look_at_b(void)
{
	//TODO
	return ;
}

/*
** Look at each element of the stack A and notate where there are disordened
** numbers, in this case a value greater than the next on the list (the tail is
** not considered).
*/

static int	look_at_a(t_prog *prog)
{
	int		pos;
	int		notation;
	int		this;
	t_dlist	*tail;
	t_dlist	*stack_a;

	if (!prog->stack_a->content)
		return 0;
	pos = 0;
	notation = 0;
	this = *(int *)prog->stack_a->content;
	tail = prog->stack_a->prev;
	stack_a = prog->stack_a;
	while (stack_a != tail)
	{
		++pos;
		if (this > *(int *)stack_a->next->content)
			notation = pos;
		stack_a = stack_a->next;
		this = *(int *)stack_a->content;
	}
	return (notation);
}

/*
** Look to each element of the stacks.
*/

int	psc_look(t_prog *prog)
{
	int	note_a;

	note_a = look_at_a(prog);
	look_at_b(); //TODO
	return (note_a);
}
