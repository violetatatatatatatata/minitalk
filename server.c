/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avelandr <avelandr@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 17:07:47 by avelandr          #+#    #+#             */
/*   Updated: 2025/06/12 17:26:06 by avelandr         ###   ########.fr       */
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
void	handler(int sign, siginfo_t *info, void *more_info)
{
	(void)more_info;
}

int main(void)
{
	ft_printf("El PID es: %d\n", getpid());

	// Wrapper function (funcion que llama a otra funcion)
	Signal(SIGUSR1, handler, true);
	Signal(SIGUSR2, handler, true);

	while ()
		pause();

	return EXIT_SUCCESS;
}
