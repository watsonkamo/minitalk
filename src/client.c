/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshintan <eshintan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 15:42:48 by eshintan          #+#    #+#             */
/*   Updated: 2024/03/31 01:07:29 by eshintan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_bit(pid_t pid, char c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (c & 1)//ビットAND演算を行い,結果が1の場合
			kill(pid, SIGUSR1);//結果が1の場合
		else
			kill(pid, SIGUSR2);//結果が0の場合
		c >>= 1;//cを1ビット右シフト. 1ビット右にずらすと2で割った値になる.右シフトとは2で割ることと同じ
		i++;
		usleep(100);//usleepは引数のマイクロ秒だけプログラムを停止する
	}
}

void	handler(int signum, siginfo_t *info, void *context)//siginfo_tはシグナルの情報を格納する構造体.
{
	//void *contextはシグナルの情報を格納する構造体.
	//handler関数はシグナルを受け取った時に呼び出される関数
	(void)context;
	(void)info;
	if (signum == SIGUSR1)
		return ;
}

int	main(int argc, char **argv)
{
	struct sigaction	act;//sigaction構造体はシグナルの挙動を変更するための構造体
	pid_t				pid;//pid_tはプロセスIDを表す型

	if (argc != 3)
	{
		ft_putstr_fd("Usage: ./client [server PID] [message]\n", 2);
		return (1);
	}
	pid = ft_atoi(argv[1]);
	if (pid < 100 || pid > 99998)
	{
		ft_putstr_fd("Invalid PID\n", 2);
		return (1);
	}
	act.sa_flags = SA_SIGINFO;//sa_flagsはシグナルの挙動を変更するためのフラグ. SA_SIGINFOはシグナルの情報を受け取るためのフラグ
	act.sa_sigaction = handler;//sa_sigactionはシグナルを受け取った時に呼び出される関数.sigactionはシグナルの挙動を変更する関数
	sigaction(SIGUSR1, &act, NULL);//SIGUSR1のシグナルを受け取った時にhandler関数を呼び出す//NULLはsigactionの第3引数で,シグナルの挙動を変更するための構造体のアドレスを指定する
	sigaction(SIGUSR2, &act, NULL);//SIGUSR2のシグナルを受け取った時にhandler関数を呼び出す
	while (*argv[2])//argv[2]が終端文字でない間
		send_bit(pid, *argv[2]++);//send_bit関数を呼び出す
	send_bit(pid, '\0');//send_bit関数を呼び出す. 終端文字を送信、終端文字を送信することでサーバーにメッセージの終了を通知し、改行を出力する
	return (0);
}
