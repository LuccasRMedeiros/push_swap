/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 22:55:55 by lrocigno          #+#    #+#             */
/*   Updated: 2021/11/17 14:18:43 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

/*
** Delete a stack.
*/

void	del_stack(t_stack *del)
{
	ft_dlstdel_circle(del->list);
	del->list = NULL;
	del->head = NULL;
	del->tail = NULL;
	del = NULL;
}
