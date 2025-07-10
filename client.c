/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avelandr <avelandr@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 21:43:56 by avelandr          #+#    #+#             */
/*   Updated: 2025/07/10 15:57:50 by avelandr         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	pid_t	server;
	char	*message;

	// input check
	if (argc != 3)
	{
		fputs("Usage = ./goku <PID> \"Message\"\n", stderr)
	}

	server = ft_atoi(argv[1]);
	message = argv[2];

	Signal(SIGUSR1, ack_handler, false);
    Signal(SIGUSR1, end _handler, false);

	// send the char bit by bit
	while (*message)
		send_char(*message++, server);
	send_char('\0', server);
	return EXIT_SUCCESS;
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
	++bit;

	// stop while hes listening
	while (g_server == BUSY)
		usleep(42);
	g_server = BUSY;
}

void    ack_handler(int signo)
{
	g_server = READY;
}

void	end_handler(int signo)
{
	write(STDOUT_FILENO, "Ok!", 3);
	exit(EXIT_SUCCESS);
}
