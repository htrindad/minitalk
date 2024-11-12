/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stacklast.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htrindad <htrindad@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 14:19:05 by htrindad          #+#    #+#             */
/*   Updated: 2024/09/17 14:19:50 by htrindad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pslib.h"

t_stack	*ps_stacklast(t_stack *stack)
{
	while (stack->next)
		stack = stack->next;
	return (stack);
}
