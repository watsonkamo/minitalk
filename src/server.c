/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshintan <eshintan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 01:13:41 by eshintan          #+#    #+#             */
/*   Updated: 2024/03/31 01:05:17 by eshintan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int signum, siginfo_t *info, void *context)
{
	static char	c = 0;//このcはなんのため？　→　受け取った文字を格納するため　どこの文字？　→　送られてきた文字
	static int	i = 0;//このiはなんのため？　→　受け取った文字のビット数を数えるため なぜ数える？　→　文字を受け取るため

	(void)context;//contextは使わないのでvoid型のポインタであることを示す
	if (signum == SIGUSR1)//受け取ったシグナルがSIGUSR1の場合
		c |= (1 << i);//cに1をiビット左シフトした値をOR演算で代入
	i++;
	if (i == 8)//iが8の場合
	{
		if (c == 0)
		{
			write(1, "\n", 1);//標準出力に改行を出力
			kill(info->si_pid, SIGUSR1);//info->si_pidには送信元のプロセスIDが格納されている
		}
		else
			write(1, &c, 1);//cを標準出力に出力
		i = 0;//iを0に戻す 何故？　→　次の文字を受け取るため
		c = 0;//cを0に戻
	}
}

int	main(void)
{
	struct sigaction	act;
	pid_t				pid;

	pid = getpid();
	ft_putstr_fd("Server PID: ", 1);
	ft_putnbr_fd(pid, 1);//サーバーのPIDを表示
	act.sa_flags = SA_SIGINFO;//sa_flagsはシグナルの挙動を変更するためのフラグ. SA_SIGINFOはシグナルの情報を受け取るためのフラグ
	act.sa_sigaction = handler;//sidactionはシグナルの挙動を変更する関数
	sigaction(SIGUSR1, &act, 0);
	sigaction(SIGUSR2, &act, 0);
	while (1)
		pause();
	return (0);
}
