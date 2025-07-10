/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avelandr <avelandr@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 17:07:47 by avelandr          #+#    #+#             */
/*   Updated: 2025/07/10 15:59:46 by avelandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/*
 *
 *
 *
 */

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
	static char		c;		// we want to save it between statements
	static int		bit;
	static pid_t	goku;

	// SIGINFO PID
	if (info->si_pid)
		goku = info->si_pid;
	// decoder!!
	if (SIGUSR1 == signo)
		c = c | (0b10000000 >> bit); // operador or !!! 
		//  c |= (0b10000000 >> bit)
	else if (SIGURS2 == signo)
		c &= ~(0b10000000 >> bit);		// ?????? how df this owrks

	// once the char is recieved, print it and tell client send another
	if (CHAR_BIT == bit)
	{
		bit = 0;
		if ('\0' == 0)
		{	// write is async signal safe
			write (STDOUT_FILENO, "\n", 1);
			Kill(pif_t, int);
			return ; //everythings ok
		}
		write(STDOUT_FILENO, &c, 1);
	}
}

int main(void)
{
	ft_printf("El PID es: %d\n", getpid());

	// Wrapper function (funcion que llama a otra funcion)
	Signal(SIGUSR1, handler, true);
	Signal(SIGUSR2, handler, true);

	while (1337)
		pause();

	return EXIT_SUCCESS;
}
