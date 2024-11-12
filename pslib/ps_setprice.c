/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_setprice.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htrindad <htrindad@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 16:58:54 by htrindad          #+#    #+#             */
/*   Updated: 2024/10/29 16:54:54 by htrindad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pslib.h"

void	ps_setprice(t_stack *a, t_stack *b)
{
	int	la;
	int	lb;

	la = ps_countnode(a);
	lb = ps_countnode(b);
	while (b)
	{
		b->push_cost = b->index;
		if (!b->am)
			b->push_cost = lb - b->index;
		if (b->target->am)
			b->push_cost += b->target->index;
		else
			b->push_cost += la - b->target->index;
		b = b->next;
	}
}
