/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_item.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 15:52:50 by lrocigno          #+#    #+#             */
/*   Updated: 2021/11/20 12:51:24 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

/*
** Delete a int inside a stack.
*/

void	del_item(void *int_n)
{
	*(int *)int_n = 0;
}