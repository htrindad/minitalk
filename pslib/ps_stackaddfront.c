/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stackaddfront.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htrindad <htrindad@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 15:46:12 by htrindad          #+#    #+#             */
/*   Updated: 2024/10/01 15:52:42 by htrindad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pslib.h"

void	ps_stackaddfront(t_stack **stack, t_stack *new)
{
	if (stack)
	{
		if (*stack)
		{
			(*stack)->prev = malloc(sizeof(t_stack));
			if (!(*stack)->prev)
				return ;
			new->next = *stack;
			(*stack)->prev = new;
			(*stack)->prev->next = *stack;
		}
	}
}
