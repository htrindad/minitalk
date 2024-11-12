/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_gethighest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htrindad <htrindad@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 18:30:47 by htrindad          #+#    #+#             */
/*   Updated: 2024/10/01 14:08:35 by htrindad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pslib.h"

t_stack	*ps_gethighest(t_stack *node)
{
	t_stack	*highest;

	highest = node;
	while (node)
	{
		if (highest->val < node->val)
			highest = node;
		node = node->next;
	}
	return (highest);
}
