/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: jdutille <jdutille@student.42luxembourg    +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2025/06/04 15:42:56 by jdutille          #+#    #+#             */
/*   Updated: 2025/06/04 15:42:56 by jdutille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../printf/ft_printf.h"
#include <signal.h>

void	handle_signal(int sig, siginfo_t *info, void *context)
{
	static size_t	count = 0;
	static char		bytes = 0;

	(void)context;
	if (sig == SIGUSR1)
		bytes &= ~(1 << count);
	else if (sig == SIGUSR2)
		bytes |= (1 << count);
	count++;
	if (count == 8)
	{
		ft_printf("%c", bytes);
		if (bytes == '\0')
			kill(info->si_pid, SIGUSR1);
		bytes = 0;
		count = 0;
	}
}

int	main(int ac, char **av)
{
	struct sigaction	sa;
	int					pid;

	(void)av;
	pid = getpid();
	if (ac == 1)
	{
		ft_printf("Server is up.\nPid: %d\nWaiting for messages\n", pid);
		sa.sa_sigaction = handle_signal;
		sa.sa_flags = SA_SIGINFO;
		sigemptyset(&sa.sa_mask);
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
		while (1)
			pause();
		return (0);
	}
	else
	{
		ft_printf("Error: Wrong arguments\nTry: ./server\n");
		return (1);
	}
}
