/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htrindad <htrindad@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 16:11:21 by htrindad          #+#    #+#             */
/*   Updated: 2024/11/01 16:16:49 by htrindad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pslib.h"

int	ps_atoi(char *nptr)
{
	int		num;
	int		neg;
	size_t	i;

	i = 0;
	neg = 1;
	num = 0;
	while (nptr[i] == 32 || (nptr[i] > 8 && nptr[i] < 14))
		i++;
	if (nptr[i] == 45 || nptr[i] == 43)
	{
		if (nptr[i] == 45)
			neg = -1;
		i++;
	}
	while (ps_isdigit((int)nptr[i]))
	{
		num = num * 10 + (nptr[i] - 48);
		i++;
	}
	return (num * neg);
}
