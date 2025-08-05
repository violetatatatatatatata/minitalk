/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avelandr <avelandr@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 00:20:43 by avelandr          #+#    #+#             */
/*   Updated: 2025/08/05 18:00:18 by avelandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

// wrapper function (it doesnt allow me to put the uppercase lol)
void	senyal(int signo, void *handler, bool siginfo)
{
	struct sigaction	sa = {0};
	
	if (siginfo)
	{
		sa.sa_flags = SA_SIGINFO;
		sa.sa_sigaction = handler;
	}
	else
		sa.sa_handler = handler;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	if (sigaction(signo, &sa, NULL) < 0)
	{
		perror("Sigaction failed");
		exit(EXIT_FAILURE);
	}
}

void	muelto(pid_t pid, int signo)
{
	if (kill(pid, signo) < 0)
	{
		perror("Kill failed");
		exit (EXIT_FAILURE);
	}
}
