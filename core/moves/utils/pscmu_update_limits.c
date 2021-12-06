/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pscmu_update_limits.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 16:09:21 by lrocigno          #+#    #+#             */
/*   Updated: 2021/12/06 00:59:53 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap_core_moves_utils.h>

/*
** Same as "tournament_a".
*/

static void	tournament_b(t_dlist *stack_b, int limits_b[2])
{
	t_dlist	*tail;
	int		l_champion;
	int		g_champion;
	int		challenger;

	tail = stack_b->prev;
	l_champion = *(int *)stack_b->content;
	g_champion = l_champion;
	challenger = 0;
	while (stack_b != tail)
	{
		challenger = *(int *)stack_b->next->content;
		if (challenger < l_champion)
			l_champion = challenger;
		else if (challenger > g_champion)
			g_champion = challenger;
		stack_b = stack_b->next;
	}
	limits_b[lower] = l_champion;
	limits_b[greater] = g_champion;
}

/*
** Make a tournament like the one that happens in "init_prog".
*/

static void	tournament_a(t_dlist *stack_a, int limits_a[2])
{
	t_dlist	*tail;
	int		l_champion;
	int		g_champion;
	int		challenger;

	tail = stack_a->prev;
	l_champion = *(int *)stack_a->content;
	g_champion = l_champion;
	challenger = 0;
	while (stack_a != tail)
	{
		challenger = *(int *)stack_a->next->content;
		if (challenger < l_champion)
			l_champion = challenger;
		else if (challenger > g_champion)
			g_champion = challenger;
		stack_a = stack_a->next;
	}
	limits_a[lower] = l_champion;
	limits_a[greater] = g_champion;
}

/*
** Update the limits of both stacks after a push movement.
*/

void	pscmu_update_limits(t_prog *prog)
{
	if (prog->a_size)
		tournament_a(prog->stack_a, prog->limits_a);
	if (prog->b_size)
		tournament_b(prog->stack_b, prog->limits_b);
}
