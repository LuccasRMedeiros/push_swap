/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 19:58:38 by lrocigno          #+#    #+#             */
/*   Updated: 2021/12/15 13:10:13 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

/*
** Delete a t_stack instance.
*/

void	del_stack(t_stack *del)
{
	t_stack	*head;
	t_stack *aux;

	head = del;
	aux = del->next;
	while (del->next != head)
	{
		aux = del->next;
		ft_bzero(del, sizeof(*del));
		free(del);
		del = aux;
	}
	head = NULL;
	aux = NULL;
	ft_bzero(del, sizeof(*del));
	free(del);
	del = NULL;
}
