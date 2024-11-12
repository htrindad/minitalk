/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htrindad <htrindad@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 17:09:28 by htrindad          #+#    #+#             */
/*   Updated: 2024/09/21 14:02:22 by htrindad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pslib.h"

static bool	ps_isnum(char c)
{
	return (c >= '0' && c <= '9');
}

long	ps_atol(char *num)
{
	long			neg;
	long			n;
	size_t			i;

	neg = 1;
	i = 0;
	n = 0;
	if (!ps_strncmp(num, "-9223372036854775808", 20))
		return (LONG_MIN);
	while (num[i] == ' ' || num[i] == '	')
		i++;
	if (num[i] == '+' || num[i] == '-')
	{
		if (num[i] == '-')
			neg = -1;
		i++;
	}
	if (ps_isnum(num[i]))
	{
		n = num[i++] - '0';
		while (ps_isnum(num[i]))
			n = n * 10 + num[i++] - '0';
	}
	return (n * neg);
}
