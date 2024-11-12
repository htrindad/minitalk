/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_duplicate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htrindad <htrindad@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 17:53:14 by htrindad          #+#    #+#             */
/*   Updated: 2024/10/30 15:12:00 by htrindad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pslib.h"

bool	ps_duplicate(t_stack *node)
{
	t_stack	*first;
	t_stack	*tmp;

	first = node;
	while (node)
	{
		tmp = first;
		while (tmp)
		{
			if (tmp->index == node->index && tmp->next)
				tmp = tmp->next;
			if (!tmp->next)
				break ;
			if (tmp && tmp->val == node->val)
				return (true);
			tmp = tmp->next;
		}
		node = node->next;
	}
	return (false);
}
