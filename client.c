/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avelandr <avelandr@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 21:43:56 by avelandr          #+#    #+#             */
/*   Updated: 2025/08/05 18:00:57 by avelandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/*
   - When a char is sended, its signal is sended bit by bit
   - Each bit is sended from the most signfical to the least significal one
   - The client sends the fist bit, waits for the server to send an ACK,
   and the client keeps going on
   - Server undestands the character sent, and replies with the number of
   bits sent using SIGUSR1, SIGUSR2
 */
volatile sig_atomic_t	g_server = BUSY;

int	main(int argc, char **argv)
{
	pid_t	server;
	char	*message;
	int		i;

	if (argc != 3)
	{
		fputs("Usage = ./client <PID> \"Message\"\n", stderr);
		return (EXIT_FAILURE);
	}
	
	// Guarda el PID del server que se ha introducido como argumento y el mensaje
	server = ft_atoi(argv[1]);
	message = argv[2];
	
	// Dependiendo de la senyal recibida del hadler, ejecutar una u otra
	senyal(SIGUSR1, ack_handler, false);
	senyal(SIGUSR2, end_handler, false);
	
	// Mientras el caracter apuntado por i no sea nulo, enviarlo
	i = 0;
	while (message[i])
		send_char(message[i++], server);
	send_char('\0', server);
	return (EXIT_SUCCESS);
}

/*  Envía los bits del least significant bit al most significant a través
    de SIGSR1 (1) or SIGUSR2 to 0.
*/
void	send_char(char c, pid_t server)
{
	int	bit;

	bit = 0;
	while (bit < CHAR_BIT)
	{
		if (c & (0x80 >> bit))
			muelto(server, SIGUSR1);
		else
			muelto(server, SIGUSR2);
		bit++;
		while (g_server == BUSY)
			usleep(42);
		g_server = BUSY;
	}
}

void	ack_handler(int signo)
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
