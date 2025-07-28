/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avelandr <avelandr@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 17:07:47 by avelandr          #+#    #+#             */
/*   Updated: 2025/07/28 19:24:27 by avelandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/*
   typedef struct {
   int si_signo;
   int si_code;
   union sigval si_value;
   int si_errno;
   pid_t si_pid;	PID SERVER	
   uid_t si_uid;	
   void *si_addr;
   int si_status;
   int si_band;
   } siginfo_t;
 */

#include "minitalk.h"

// Una única variable global para almacenar el estado y el carácter.
// 0: No hay carácter listo.
// 1: Carácter nulo ('\0') listo (fin de mensaje).
// 2 a 257: Carácter ASCII (valor_ascii + 2) listo.

volatile sig_atomic_t	g_char_status = 0;

int	main(void)
{
	struct sigaction	sa;
	pid_t				pid;
	char	char_to_print;
	char	pid_str[MAX_PID];
	int	len;

	pid = getpid();
	len = snprintf(pid_str, sizeof(pid_str), "PID -> %d\n", pid);
	write(STDOUT_FILENO, pid_str, len);
	ft_bzero(&sa, sizeof(sa));
	sa.sa_flags = SA_SIGINFO | SA_RESTART;
	sa.sa_sigaction = handler;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{
		pause();
		if (g_char_status != 0)
		{
			if (g_char_status == 1)
			{
				write(STDOUT_FILENO, "\n", 1);
			}
			else
			{
				char_to_print = (char)(g_char_status - 2);
				write(STDOUT_FILENO, &char_to_print, 1);
			}
			g_char_status = 0;
		}
	}
	return (0);
}

void    handler(int signo, siginfo_t *info, void *more_info)
{
	static char	c = 0;
	static int	bit = 0;
	static pid_t	client = 0;

	(void)more_info;
	if (client == 0 && info->si_pid)
		client = info->si_pid;
	if (SIGUSR1 == signo)
		c = c | (0b10000000 >> bit);
	else if (SIGUSR2 == signo)
		c &= ~(0x80 >> bit);
	bit++;
	if (client != 0)
		kill(client, SIGUSR1);
	if (CHAR_BIT == bit)
	{
		bit = 0;
		if (c == '\0')
		{
			g_char_status = 1;
			kill(client, SIGUSR2);
			client = 0;
		}
		else
			g_char_status = (int)c + 2;
		c = 0;
	}
}
