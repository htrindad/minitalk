/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htrindad <htrindad@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 15:48:53 by htrindad          #+#    #+#             */
/*   Updated: 2024/11/04 17:44:08 by htrindad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include "./ft_printf/ft_printf.h"
# include "./pslib/pslib.h"
# include <string.h>

typedef struct s_data
{
	char	*s;
	int		pid;
	size_t	cc;
	size_t	len;
}	t_data;

void	handle_data(t_data *data, int pid);

#endif
