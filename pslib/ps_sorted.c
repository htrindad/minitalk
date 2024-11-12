/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htrindad <htrindad@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 16:44:54 by htrindad          #+#    #+#             */
/*   Updated: 2024/10/01 16:32:38 by htrindad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pslib.h"

bool	ps_sorted(t_stack *node)
{
	t_stack	*prev;

	prev = node;
	node = node->next;
	while (node)
	{
		if (prev->val > node->val)
			return (false);
		node = node->next;
		prev = prev->next;
	}
	return (true);
}
