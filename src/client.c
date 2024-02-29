/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshintan <eshintan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 15:42:48 by eshintan          #+#    #+#             */
/*   Updated: 2024/02/27 15:48:13 by eshintan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_bit(pid_t pid, char c)
{
	int	i;

    i = 0;
	while (i<8)
	{
		if (c & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		c = c >> 1;
		i++;
		usleep(100);
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
	if (argc != 3)
	{
		printf("Usage: %s <pid> <string>\n", argv[0]);
		return (1);
	}
	pid_t pid = ft_atoi(argv[1]);
	char *str = argv[2];
	struct sigaction act;

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
