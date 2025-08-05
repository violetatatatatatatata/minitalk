/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avelandr <avelandr@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 17:13:06 by avelandr          #+#    #+#             */
/*   Updated: 2025/08/05 17:55:08 by avelandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

// Protocolo de Stop and Wait
# define BUSY 0
# define READY 1

# define MAX_PID 10

# include "libft/Includes/libft.h"
# include <stdio.h>
# include <errno.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include <limits.h>
# include <stdbool.h>

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

// Struct for sigaction
	// mask is used for blocking signals

// Functions
void	senyal(int signo, void *handler, bool siginfo);
void	muelto(pid_t pid, int signo);
void	send_char(char c, pid_t server);
void	ack_handler(int signo);
void	end_handler(int signo);
void	handler(int signo, siginfo_t *info, void *more_info);

#endif
