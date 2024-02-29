#include "minitalk.h"

// 関数の順番
// もらう
// 判別する
// 表示させる
// 送り返す
void handler(int signum, siginfo_t *info, void *context)
{
    static char c = 0;
    static int i = 0;
    (void)context;
    if (signum == SIGUSR1)
        c = c | (1 << i);
    i++;
    if (i==8)
    {
        if (c == 0)
        {
            write(1, "\n", 1);
            kill(info->si_pid, SIGUSR1);
        }
        else
            write(1, &c, 1);
        c = 0;
        i = 0;
    }
}

int main (void)
{
    pid_t pid;
    struct sigaction act;

    pid = getpid();
    ft_putstr_fd("server PID:", 1);
    ft_putnbr_fd(pid, 1);
    act.sa_flags = SA_SIGINFO;
    act.sa_sigaction = handler;
    sigaction(SIGUSR1, &act, NULL);
    sigaction(SIGUSR2, &act, NULL);
    while (1)
        pause();
    return (0);
}