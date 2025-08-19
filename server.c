/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avelandr <avelandr@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 17:07:47 by avelandr          #+#    #+#             */
/*   Updated: 2025/08/19 14:30:55 by avelandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

#include "minitalk.h"

// Una única variable global para almacenar el estado y el carácter.
// 0: No hay carácter listo.
// 1: Carácter nulo ('\0') listo (fin de mensaje).
// 2 a 257: Carácter ASCII (valor_ascii + 2) listo.

/*	OPERADORES BINARIOS
	OR	(0 | 0 = 0, 0 | 1 = 1, 1 | 0 = 1, 1 | 1 = 1)
	AND	(0 | 0 = 0, 0 | 1 = 0, 1 | 0 = 0, 1 | 1 = 1)
*/

/*
	CLASIFICADOR VOLATIL
	indica que el valor de esta estructura puede cambiar fuera del
	programa, por lo tanto exige al compilador que acceda al valor
	desde la memoria y no desde el registro (cosa que se haria para
	optimizar el codigo)

	SIG_ATOMIC_T definido en <signal.h>
	es un tipo de dato integer al que se puede acceder como "entidad atomica"
	(es decir, que es un acceso indivisible e ininterrumpible, por lo cual
	garantiza que la operacion se ejecute completamente a nivel de procesador)
	incluso ante interrupciones asincronas realizadas por signals (una
	interrupcion asincrona es una signal que fuerza la detencion de la
	ejecucion y es asincrona porque no corresponde al flujo del programa)

	Esta linea declara g_char_status como un tipo de dato integer atomico
	que es tambien volatil, por lo tanto, es un proceso indivisible cuyo
	valor cambia con cada ejecucion
*/

volatile sig_atomic_t	g_char_status = BUSY;

/* SERVER
 *
 * 1. La funcion utiliza la estructura sigaction para especificar el
 * comportamiento del manejador de senales.
 *
 * 2. Se configuran las siguientes banderas:
 * - SA_SIGINFO: Permite que el manejador reciba mas informacion de la senal,
 * como el PID del emisor, a traves del campo sa_sigaction.
 * - SA_RESTART: Intenta reiniciar automaticamente las llamadas al sistema
 * interrumpidas por una senal.
 *
 * 3. Se asigna la direccion del manejador a sa_sigaction.
 *
 * 4. La mascara de senales sa_mask se inicializa vacia con sigemptyset y
 * luego se anaden SIGUSR1 y SIGUSR2 para bloquear temporalmente otras
 * senales mientras el manejador se esta ejecutando, evitando interrupciones.
 *
 * 5. La funcion sigaction se llama para asociar la senal deseada con la
 * estructura configurada. El tercer argumento es nulo porque no se necesita
 * la configuracion anterior.
 *
 * 6. El proceso principal entra en pause, deteniendose y no consumiendo
 * recursos de CPU hasta que una de las senales SIGUSR1 o SIGUSR2 sea
 * recibida y el manejador se ejecute.
 */

int	main(void)
{
	struct sigaction	sa;
	char				char_to_print;

	ft_printf("PID: %d\n", getpid());
	ft_bzero(&sa, sizeof(sa));
	sa.sa_flags = SA_SIGINFO | SA_RESTART;
	sa.sa_sigaction = handler;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		esperando_sentado(&char_to_print);
	ft_printf("\n");
	return (0);
}

void	esperando_sentado(char *char_to_print)
{
	pause();
	if (g_char_status != 0)
	{
		if (g_char_status == 1)
			ft_printf("\n");
		else
		{
			*char_to_print = g_char_status - 2;
			ft_printf("%c", *char_to_print);
		}
		g_char_status = 0;
	}
}

/* ALGORITMO DE DECODIFICACION
 *
 * 1. La función decodifica los bits del cliente a partir de la señal
 * recibida (signo): SIGUSR1 o SIGUSR2.
 *
 * 2. siginfo_t info da acceso a información detallada, como el PID
 * del cliente emisor. El parámetro moreinfo es requerido por
 * sigaction, aunque no se use en esta función (o la funcion se queja :p)
 *
 * 3. Si es la primera señal, se guarda el PID del cliente de la estructura
 * info para que el servidor sepa a quién responder.
 *
 * 4. Lógica de bits:
 * - SIGUSR1: El bit correspondiente se establece a 1 sin modificar
 * los bits ya decodificados. Se logra con un desplazamiento de bits
 * (>>) y una operación OR.
 * - SIGUSR2: Niega el bit correspondiente. Se logra con una operación
 * de negación lógica o NAND.
 *
 * 5. Una vez procesado el bit, el servidor envía SIGUSR1 al cliente como
 * ACK (confirmación) usando la función kill().
 *
 * 6. El contador de bits se incrementa y se reinicia al llegar a 8,
 * completando la decodificación de un byte (char).
 */

void	handler(int signo, siginfo_t *info, void *more_info)
{
	static char		c = 0;
	static int		bits_recibidos = 0;
	static pid_t	client = 0;

	(void)more_info;
	if (client == 0 && info->si_pid)
		client = info->si_pid;
	if (signo == SIGUSR1)
		c = c | (0b10000000 >> bits_recibidos);
	else if (SIGUSR2 == signo)
		c &= ~(0b10000000 >> bits_recibidos);
	bits_recibidos++;
	if (client != 0)
		muelto(client, SIGUSR1);
	if (bits_recibidos == CHAR_BIT)
		recieved(&bits_recibidos, &client, &c);
}

void	recieved(int *bits_recibidos, int *client, char *c)
{
	*bits_recibidos = 0;
	if (*c == '\0')
	{
		g_char_status = 1;
		muelto(*client, SIGUSR2);
		*client = 0;
	}
	else
		g_char_status = (int)*c + 2;
	*c = 0;
}
