/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avelandr <avelandr@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 17:13:06 by avelandr          #+#    #+#             */
/*   Updated: 2025/07/11 20:16:18 by avelandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

#define BUSY 0
#define READY 1

#include "libft/Includes/libft.h"
# include <stdio.h>
# include <errno.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include <limits.h>
# include <stdbool.h>


// Struct for sigaction
	// mask is used for blocking signals

// Functions
void	Signal (int signo, void *handler, bool use_siginfo);
void	Kill(pid_t pid, int signo);
void	send_char(char c, pid_t server);
void	ack_handler(int signo);
void    end_handler(int signo);

#endif
