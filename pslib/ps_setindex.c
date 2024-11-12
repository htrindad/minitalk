/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_setindex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htrindad <htrindad@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 17:55:36 by htrindad          #+#    #+#             */
/*   Updated: 2024/10/29 16:50:11 by htrindad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pslib.h"

void	ps_setindex(t_stack *stack)
{
	int		i;
	int		center;

	i = 0;
	if (stack == NULL)
		return ;
	center = ps_countnode(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= center)
			stack->am = true;
		else
			stack->am = false;
		stack = stack->next;
		i++;
	}
}
