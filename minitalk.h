/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avelandr <avelandr@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 17:13:06 by avelandr          #+#    #+#             */
/*   Updated: 2025/07/10 15:57:57 by avelandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

#define TRUE 1
#define FALSE 0

#include <signal.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft/Includes/libft.h"
#include <limits.h>

enum
{
	READY,
	BUSY,
}

// volatile basically means 'hey compiler' dont do weid shi because this variable changes once the process is recieved:p
// sig_atomic means that the process (read and write) cant be interrupted
// global variable assumes two states
volatile sig_atomic_t g_server = BUSY;

// Struct for sigaction
	// mask is used for blocking signals

// Functions
void	Signal (int signo, void *handler, bool use_siginfo);
void	send_char(char c, pid_t server);
void	Kill(pid_t pid, int signo);
void	ack_handler(int signo);

#endif
