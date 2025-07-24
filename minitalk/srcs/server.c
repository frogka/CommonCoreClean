/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdutille <jdutille@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 15:42:38 by jdutille          #+#    #+#             */
/*   Updated: 2025/06/25 19:29:14 by jdutille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../printf/ft_printf.h"
#include <signal.h>

void	handle_signal(int sig)
{
	static size_t	count = 0;
	static char		bytes = 0;

	if (sig == SIGUSR1)
		bytes &= ~(1 << count);
	else if (sig == SIGUSR2)
		bytes |= (1 << count);
	count++;
	if (count == 8)
	{
		ft_printf("%c", bytes);
		bytes = 0;
		count = 0;
	}
}

int	main(int ac, char **av)
{
	int	pid;

	(void)av;
	pid = getpid();
	if (ac == 1)
	{
		ft_printf("Server is up.\nPid: %d"
			"\nWaiting for messages\n", pid);
		signal(SIGUSR1, handle_signal);
		signal(SIGUSR2, handle_signal);
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
