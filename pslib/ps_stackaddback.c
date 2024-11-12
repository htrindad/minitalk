/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stackaddback.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htrindad <htrindad@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 14:20:23 by htrindad          #+#    #+#             */
/*   Updated: 2024/09/17 14:59:55 by htrindad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pslib.h"

void	ps_stackaddback(t_stack **stack, t_stack *new)
{
	t_stack	*last;

	if (stack)
	{
		if (*stack)
		{
			last = ps_stacklast(*stack);
			new->prev = last;
			last->next = new;
		}
		else
			*stack = new;
	}
}
