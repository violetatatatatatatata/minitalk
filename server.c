/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avelandr <avelandr@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 17:07:47 by avelandr          #+#    #+#             */
/*   Updated: 2025/07/08 02:06:01 by avelandr         ###   ########.fr       */
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

void	handler(int sign, siginfo_t *info, void *more_info)
{
	(void)more_info;

	// write(STDOUT_FILENO, "hello", 5);
	static char	c;
	static int	bit;

	// decoder!!
	if (SIGUSR1 == signo)
		c = c | (0b10000000 >> bit); // operador or 
		// c |= (0b10000000 >> bit)
	else if (SIGURS2 == signo)
		c &= ~(0b10000000 >> bit);
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
