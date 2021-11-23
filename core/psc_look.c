/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psc_look.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 21:25:02 by lrocigno          #+#    #+#             */
/*   Updated: 2021/11/23 00:49:59 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap_core.h>

/*
** Look at each element of the stack B and notate where there are disordened
** numbers, in this case a value less than the next on the list (the tail is
** not considered).
*/

static void	look_at_b(t_prog *prog)
{
	t_dlist	*stack_b;
	int		this;
	t_dlist	*tail;
	t_dlist	*aux;

	stack_b = prog->stack_a;
	if (!stack_b->content)
		return ;
	this = *(int *)stack_b->content;
	tail = stack_b->prev;
	aux = stack_b;
	while (aux != tail)
	{
		printf("stack_b: %i", this);
		if (this < *(int *)aux->next->content)
			ft_putendl_fd("F", 1);
		aux = aux->next;
		this = *(int *)aux->content;
	}
	printf("stack_b: %i", this);
}

/*
** Look at each element of the stack A and notate where there are disordened
** numbers, in this case a value greater than the next on the list (the tail is
** not considered).
*/

static void	look_at_a(t_prog *prog)
{
	t_dlist	*stack_a;
	int		this;
	t_dlist	*tail;
	t_dlist	*aux;

	stack_a = prog->stack_a;
	if (!stack_a->content)
		return ;
	this = *(int *)stack_a->content;
	tail = stack_a->prev;
	aux = stack_a;
	while (aux != tail)
	{
		printf("stack_a: %i\n", this);
		if (this > *(int *)aux->next->content)
			psc_execute(prog, psm_sa);
		else
			psc_execute(prog, psm_ra);
		aux = aux->next;
		this = *(int *)aux->content;
	}
	printf("stack_a: %i\n", this);
}

/*
** Look to each element of the stacks.
*/

void	psc_look(t_prog *prog)
{
	look_at_a(prog);
	look_at_b(prog);
}
