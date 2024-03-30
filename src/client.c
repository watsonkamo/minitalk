/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshintan <eshintan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 15:42:48 by eshintan          #+#    #+#             */
/*   Updated: 2024/03/30 23:26:34 by eshintan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_bit(pid_t pid, char c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (c & 1)
		{
			if (kill(pid, SIGUSR1) == -1)
				exit(1);
			//kill(pid, SIGUSR1);
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				exit(1);
			//kill(pid, SIGUSR2);
		}
		c = c >> 1;
		i++;
		usleep(500);
	}
}

void	handler(int signum, siginfo_t *info, void *context)
{
	(void)context;
	(void)info;
	if (signum == SIGUSR1)
		return ;
}

int	main(int argc, char **argv)
{
	pid_t				pid;
	char				*str;
	struct sigaction	act;

	if (argc != 3)
	{
		ft_putstr_fd("Usage: ./client <pid> <string>\n", 1);
		return (1);
	}
	pid = ft_atoi(argv[1]);
	str = argv[2];
	act.sa_sigaction;
	act.sa_sigaction = handler;
	act.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	while (*str)
	{
		send_bit(pid, *str);
		str++;
	}
	send_bit(pid, 0);
	return (0);
}
