/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_highestval.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htrindad <htrindad@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 14:46:02 by htrindad          #+#    #+#             */
/*   Updated: 2024/10/18 17:44:41 by htrindad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pslib.h"

int	ps_highestval(t_stack *node)
{
	int	val;

	val = node->val;
	while (node)
	{
		if (node->val > val)
			val = node->val;
		node = node->next;
	}
	return (val);
}
