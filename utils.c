/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avelandr <avelandr@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 00:20:43 by avelandr          #+#    #+#             */
/*   Updated: 2025/08/19 14:39:07 by avelandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/* SENYAL
 *
 * 1. Recibe el numero de la senal, un puntero al manejador (handler) y un
 * booleano (siginfo) que determina el tipo de manejador a usar.
 *
 * 2. Si siginfo es verdadero, se usa sa_sigaction y se establece la flag
 * SA_SIGINFO para recibir informacion detallada de la senal.
 *	  Si es falso, se usa sa_handler.
 *
 * 3. La mascara de la estructura se inicializa a vacio con sigemptyset
 * y luego se le anade SIGUSR1 y SIGUSR2 con sigaddset. Esto bloquea
 * estas senales mientras el handler se esta ejecutando.
 *
 * 4. Finalmente, la funcion sigaction se llama para asociar la senal
 * con la estructura configurada.
 *
 * 5. Se incluye manejo de errores con perror y exit para asegurar
 * que la llamada a sigaction no falle.
 */

void	senyal(int signo, void *handler, bool siginfo)
{
	struct sigaction	sa;

	ft_bzero(&sa, sizeof(sa));
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
