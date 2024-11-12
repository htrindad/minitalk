/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htrindad <htrindad@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 17:58:01 by htrindad          #+#    #+#             */
/*   Updated: 2024/09/05 18:55:01 by htrindad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pslib.h"

char	*ps_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	i;

	if (!s || !len || start > ps_strlen(s))
		return (ps_strdup(""));
	i = 0;
	if (len > ps_strlen(s + start))
		len = ps_strlen(s + start);
	ret = malloc(sizeof(char) * (len + 1));
	if (ret == NULL)
		return (NULL);
	while (len)
	{
		ret[i++] = s[start++];
		len--;
	}
	ret[i] = 0;
	return (ret);
}
