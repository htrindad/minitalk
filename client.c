/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htrindad <htrindad@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 17:51:31 by htrindad          #+#    #+#             */
/*   Updated: 2024/11/04 18:23:58 by htrindad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static t_data	g_data;

static void	send_signal(void)
{
	unsigned char	t_c;
	static int		bit = 0;

	t_c = g_data.s[g_data.cc];
	if (g_data.cc >= g_data.len + 1)
		return ;
	g_data.s[g_data.cc] = t_c >> 1;
	bit++;
	if (bit == 8)
	{
		bit = 0;
		g_data.cc++;
	}
	if (t_c & 1)
		kill(g_data.pid, SIGUSR2);
	else
		kill(g_data.pid, SIGUSR1);
}

static void	bit_ack(int sig)
{
	if (sig == SIGUSR2)
		exit(0);
	send_signal();
}

static void	get_response(void)
{
	struct sigaction	sa;

	sa.sa_handler = &bit_ack;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	send_signal();
	while (1)
		pause();
}

static int	illegal(void)
{
	ft_printf("Illegal pid.\n");
	return (-1);
}

int	main(int ac, char **av)
{
	size_t	i;

	if (ac != 3)
	{
		ft_printf("not enough args...\n");
		return (-1);
	}
	i = 0;
	while (av[1][i])
	{
		if (!ps_isdigit(av[1][i++]))
			return (illegal());
	}
	g_data.pid = ps_atoi(av[1]);
	if (g_data.pid < 1)
		return (illegal());
	g_data.s = av[2];
	g_data.cc = 0;
	g_data.len = ps_strlen(av[2]);
	get_response();
	return (0);
}
