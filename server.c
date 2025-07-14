/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avelandr <avelandr@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 17:07:47 by avelandr          #+#    #+#             */
/*   Updated: 2025/07/14 18:17:31 by avelandr         ###   ########.fr       */
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

// The handler function should match the SA_SIGINFO prototype if the SA_SIGINFO
// bit is set in flags. Then should be ponted to by the sa_sigaction member of
// struct sigaction

void	handler(int signo, siginfo_t *info, void *more_info)
{
	(void)more_info;

	// write(STDOUT_FILENO, "hello", 5);
	static char		c = 0;		// we want to save it between statements
	static int		bit = 0;
	static pid_t	client = 0;

	// SIGINFO PID
	if (client == 0 && info->si_pid)
		client = info->si_pid;
	// decoder!!
	if (SIGUSR1 == signo)
		c = c | (0b10000000 >> bit); // operador or !!! 
		//  c |= (0b10000000 >> bit)
	else if (SIGUSR2 == signo)
		c &= ~(0x80 >> bit);		// ?????? how df this owrks
	bit++;
	// once the char is recieved, print it and tell client send another
	if (CHAR_BIT == bit)
	{
		bit = 0;
		if (c == '\0')
		{	// write is async signal safe
			write (STDOUT_FILENO, "\n", 1);
			Kill(client, SIGUSR2);
            c = 0;
			return ; //everythings ok
		}
		write(STDOUT_FILENO, &c, 1);
        c = 0;
	}
    Kill(client, SIGUSR1);
}

int main(int argc, char **argv)
{
	if (argc != 1)
	{
		fputs("Usage: ./server\n", stderr);
		return (EXIT_FAILURE);
	}
    ft_printf("Server PID: %d\n", getpid());
	// Wrapper function (funcion que llama a otra funcion)
	Signal(SIGUSR1, handler, true);
	Signal(SIGUSR2, handler, true);
	(void)argv[0];
	while (1337)
		pause();
	return (EXIT_SUCCESS);
}
