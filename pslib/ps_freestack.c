/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_freestack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htrindad <htrindad@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 17:11:27 by htrindad          #+#    #+#             */
/*   Updated: 2024/09/21 16:23:02 by htrindad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pslib.h"

void	ps_freestack(t_stack **node)
{
	t_stack	*tmp;
	t_stack	*current;

	if (node == NULL)
		return ;
	current = *node;
	while (current)
	{
		tmp = current;
		current = current->next;
		free(tmp);
	}
	*node = NULL;
}
