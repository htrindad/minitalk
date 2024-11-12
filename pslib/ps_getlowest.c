/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_getlowest.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htrindad <htrindad@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 16:39:31 by htrindad          #+#    #+#             */
/*   Updated: 2024/10/30 15:59:28 by htrindad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pslib.h"

t_stack	*ps_getlowest(t_stack *node)
{
	long	smallest;
	t_stack	*l_node;

	if (node == NULL)
		return (NULL);
	smallest = LONG_MAX;
	while (node)
	{
		if (node->val < smallest)
		{
			smallest = node->val;
			l_node = node;
		}
		node = node->next;
	}
	return (l_node);
}
