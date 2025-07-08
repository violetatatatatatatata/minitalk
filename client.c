/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avelandr <avelandr@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 21:43:56 by avelandr          #+#    #+#             */
/*   Updated: 2025/07/08 01:28:29 by avelandr         ###   ########.fr       */
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
	if (c & (0b00100000 >> bit))
		Kill(server, SIGUSR1);
	else
		Kill(server, SIGUSR2);
	++bit;
}
