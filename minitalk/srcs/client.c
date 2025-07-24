/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdutille <jdutille@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 15:42:25 by jdutille          #+#    #+#             */
/*   Updated: 2025/06/25 19:29:04 by jdutille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../printf/ft_printf.h"
#include <signal.h>

void	send_bytes(const char *msg, size_t len, int pid)
{
	size_t	i;
	size_t	bit;

	i = 0;
	while (i < len)
	{
		bit = 0;
		while (bit < 8)
		{
			if ((msg[i] >> bit) & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			bit++;
			usleep(200);
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	int	pid;

	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		if (pid <= 0 || kill(pid, 0) == -1)
		{
			ft_printf("Error: Invalid PID.\n");
			return (1);
		}
		send_bytes(av[2], ft_strlen(av[2]), pid);
		send_bytes("\n", 1, pid);
	}
	else
	{
		ft_printf("Error: Wrong arguments.\nTry: ./client [PID] [MSG]\n");
		return (1);
	}
	return (0);
}
