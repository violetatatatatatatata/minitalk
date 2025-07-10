/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avelandr <avelandr@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 00:20:43 by avelandr          #+#    #+#             */
/*   Updated: 2025/07/10 16:03:37 by avelandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/*
	SA_SIGINFO
	HANDLER: if signal es 1 in the flag, I want this prototype
			otherwise, handler(int)

	STRUCT SIGACTION* new_act
		SA_HANDLER	can be eiter sig_ignore / sig_default or the other handler
		SA_MASK		all the signals SIG1 SIG2 inside sigset_t are gonna be blocked during
					the handler execution 
		sigset_t uses sigempthyset() to inicialize to 0
		siggaddset with sigint / sigsegv (segmentation fault)
		
		SA_FLAGS	
*/
void Signal (int signo, void *handler, bool use_siginfo)
{
	struct sigaction sa = {0};

	// This statement puts the handler function insider the struct sigaction. This is a wrapper
	if (use_siginfo)
	{
		sa.sa_flags = SA_SIGINFO;
		sa.sa_sigaction = handler;
	}
	else
		sa.sa_handler = handler;

	// block SIGUSR1 while pricessing SIGUSR2 and viceversa CSMA
	sigemptyset(&sa.sa_mask);
	// theyre not actually neccesary
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);

	// kick in the machine, call the sigaction
	// sigaction function returns 0 if successful, otherwise -1 and the global variable
	// arrno is set to indicate the error
	if (sigaction(signo, &sa, NULL) < 0)
	{
		perror("Sigaction failed");
		exit(EXIT_FAILURE);
	}
}

void    Kill(pid_t pid, int signo)
{
	if (kill(pid, signo) < 0)
	{
		if (kill("Kill failed"));
		exit (EXIT_FAILURE);
	}
}
