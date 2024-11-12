/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htrindad <htrindad@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 19:39:53 by htrindad          #+#    #+#             */
/*   Updated: 2024/09/05 19:49:41 by htrindad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pslib.h"

static int	ps_tcount(char const *s, char c)
{
	int	token;

	token = 0;
	while (*s)
	{
		if (*s != c)
		{
			token++;
			while (*s && *s != c)
				s++;
		}
		else
			s++;
	}
	return (token);
}

static int	ps_ca(char **ptr, int j)
{
	if (ptr[j] == NULL)
	{
		while (j >= 0)
		{
			free(ptr[j]);
			j--;
		}
		free(ptr);
		return (0);
	}
	return (1);
}

static int	ps_la(char const *s, char c, char **ptr, int i)
{
	int	sta;
	int	j;

	j = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i])
		{
			sta = i;
			while (s[i] && s[i] != c)
				i++;
			ptr[j] = ps_substr(s, sta, i - sta);
			if (!ps_ca(ptr, j))
				return (0);
			j++;
		}
	}
	return (1);
}

char	**ps_split(char const *s, char c)
{
	int		token;
	char	**ptr;

	if (s == NULL)
		return (NULL);
	token = ps_tcount(s, c);
	ptr = malloc((token + 1) * sizeof(char *));
	if (ptr == NULL)
		return (NULL);
	if (!ps_la(s, c, ptr, 0))
		return (NULL);
	ptr[token] = NULL;
	return (ptr);
}
