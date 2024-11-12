/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_setcheapest.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htrindad <htrindad@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 17:32:31 by htrindad          #+#    #+#             */
/*   Updated: 2024/10/30 17:40:19 by htrindad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pslib.h"

void	ps_setcheapest(t_stack *node)
{
	long	bmi;
	t_stack	*bmn;

	if (node == NULL)
		return ;
	bmi = LONG_MAX;
	while (node)
	{
		if (node->push_cost < bmi)
		{
			bmi = node->push_cost;
			bmn = node;
		}
		node = node->next;
	}
	bmn->cheapest = true;
}
