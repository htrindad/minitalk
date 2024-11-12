/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htrindad <htrindad@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 15:48:19 by htrindad          #+#    #+#             */
/*   Updated: 2024/11/04 18:19:02 by htrindad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	print_menu(void)
{
	const char	*text = \
		"\033[1;31m\033[0;35m"
		"███╗   ███╗██╗███╗   ██╗██╗████"
		"████╗ █████╗ ██╗     ██╗  ██╗\n"
		"████╗ ████║██║████╗  ██║██║╚══█"
		"█╔══╝██╔══██╗██║     ██║ ██╔╝\n"
		"██╔████╔██║██║██╔██╗ ██║██║   █"
		"█║   ███████║██║     █████╔╝ \n"
		"██║╚██╔╝██║██║██║╚██╗██║██║   █"
		"█║   ██╔══██║██║     ██╔═██╗ \n"
		"██║ ╚═╝ ██║██║██║ ╚████║██║   █"
		"█║   ██║  ██║███████╗██║  ██╗\n"
		"╚═╝     ╚═╝╚═╝╚═╝  ╚═══╝╚═╝   ╚"
		"═╝   ╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝\n"
		"\033[0m";

	write(1, text, 945);
	ft_printf("\033[0m\n\nserver...\n\n");
}

static void	handle_signal(int sig, siginfo_t *s, void *content)
{
	static int	cc = 0;
	static int	bi = 0;

	(void)content;
	if (sig == SIGUSR2)
		cc += (1 << bi);
	if (bi++ == 7)
	{
		if (!cc)
		{
			write(1, "\n", 1);
			kill(s->si_pid, SIGUSR2);
		}
		else
			write(1, &cc, 1);
		cc = 0;
		bi = 0;
	}
	kill(s->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;

	print_menu();
	ft_printf("Current id: %d\n\n", getpid());
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sa.sa_sigaction = handle_signal;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
