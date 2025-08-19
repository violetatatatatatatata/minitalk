/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avelandr <avelandr@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 21:43:56 by avelandr          #+#    #+#             */
/*   Updated: 2025/08/19 14:48:32 by avelandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/* Flujo de Comunicación Cliente-Servidor
 *
 * - La comunicación envía un carácter, bit a bit, desde el cliente al servidor.
 * - Cada bit se envía en orden, del más significativo al menos significativo.
 * - El cliente envía el primer bit, espera una confirmación (ACK) del servidor y
 * continúa con el siguiente.
 * - El servidor, una vez que ha decodificado un bit, confirma la recepción
 * enviando una señal (ACK) al cliente.
 *
 * Cliente:
 * - Almacena el PID del servidor y el mensaje del argumento.
 * - Utiliza un manejador de señales para gestionar las respuestas del servidor.
 * - Recorre el mensaje, enviando cada carácter (incluyendo el nulo '\0') al
 * servidor, bit a bit, hasta que el mensaje completo ha sido transmitido.
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
	server = ft_atoi(argv[1]);
	message = argv[2];
	senyal(SIGUSR1, ack_handler, false);
	senyal(SIGUSR2, end_handler, false);
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
