/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avelandr <avelandr@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 21:43:56 by avelandr          #+#    #+#             */
/*   Updated: 2025/07/14 17:44:15 by avelandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/*
	- When a char is sended, its signal is sended bit by bit
	- Each bit is sended from the most signfical to the least significal one
	- The client sends the fist bit, waits for the server to send an ACK, and the
	client keeps going on
	- Server undestands the character sent, and replies with the number of
	bits sent using SIGUSR1, SIGUSR2

	Protocolo asincrono
*/

// volatile basically means 'hey compiler' dont do weid shi because this variable changes once the process is recieved:p
// sig_atomic means that the process (read and write) cant be interrupted
// global variable assumes two states
volatile sig_atomic_t g_server = BUSY;

int	main(int argc, char **argv)
{
	pid_t	server;
	char	*message;
    int     i;

	// input check
	if (argc != 3)
	{
		fputs("Usage = ./goku <PID> \"Message\"\n", stderr);
        return(EXIT_FAILURE);
	}

	server = ft_atoi(argv[1]);
	message = argv[2];

	Signal(SIGUSR1, ack_handler, false);
    Signal(SIGUSR1, end_handler, false);

    i = 0;
	// send the char bit by bit
	while (message[i])
		send_char(message[i++], server);
	send_char('\0', server);
	return (EXIT_SUCCESS);
}

void    send_char(char c, pid_t server)
{
	int	bit;

	bit = 0;
	while (bit < CHAR_BIT)	// Number of bits in a byte (8)
	// BITWISE OPERATIONS	(search it lol)
	if (c & (0x80 >> bit))
		Kill(server, SIGUSR1);
	else
		Kill(server, SIGUSR2);
	bit++;
	// stop while hes listening
	while (g_server == BUSY)
		usleep(42);
	g_server = BUSY;
}

void    ack_handler(int signo)
{
	(void)signo;
	g_server = READY;
}

void	end_handler(int signo)
{
	(void)signo;
	write(1, "ACK\n", 4);
	exit(EXIT_SUCCESS);
}
