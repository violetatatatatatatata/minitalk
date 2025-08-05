/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avelandr <avelandr@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 17:07:47 by avelandr          #+#    #+#             */
/*   Updated: 2025/08/05 17:57:05 by avelandr         ###   ########.fr       */
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

/* STRUCT SIGACTION
           struct sigaction {
               void     (*sa_handler)(int);	// especifica la accion a ser asociada a signum (SIG_DFL - SIG_IGN - a pointer to a signal)
               void     (*sa_sigaction)(int, siginfo_t *, void *);
               sigset_t   sa_mask;
               int        sa_flags;
               void     (*sa_restorer)(void);
           };
	- PID: identificador unico de proceso, permite que el SO dirija la signal del client al proceso que lleva el server
*/

int	main(void)
{
	struct sigaction	sa;
	char				char_to_print;
	
	// Imprimir el PID
	ft_printf("PID: %d\n", getpid());
	ft_bzero(&sa, sizeof(sa));
	
	// La flag SIGINFO indica que se usara el campo sa_sigaction en lugar de sa_handler de modo que el handler tenga mas informacion de la signal tal como el PID del receptor
	// SA_RESTART indica que de interrumpirse una llamada al sistema (como read o write) el SO debe intentar reiniciar la llamada automaticamente
	// El operador OR indica al handler que adquiera dos comportamientos: SA_SIGINFO (recibir informacion detallada de la signal y SA_RESTART (reiniciar llamadas al sistema interrumpidas)
	sa.sa_flags = SA_SIGINFO | SA_RESTART;

	// Se asigna la direccion de handler al campo sa_sigaction para indicar que esa sera la funcion que procese la signal recibida
	sa.sa_sigaction = handler;

	// Esta linea inicializa un conjunto de signals vacia para el campo sa_mask. Este campo define que signals han de ser bloqueadas mientras el handler se esta ejecutando. Esta ejecucion permite que por defecto ninguna signal este bloqueada
	sigemptyset(&sa.sa_mask);

	// La funcion sigaddset agrega la signal al conjunto apuntado por set recien inicializado
	// Esta ejecucion permite que cualquier otra signal SIGUSR1 o SIGUSR2 queden bloqueadas temporalmente mientras se ejecuta el handler
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);

	// int sigaction(int signum, const struct sigaction *act, struct sigaction *oldact);
	// Indica que una vez reciba la senyal definida en el campo signum, debe usar la estructura sa para manejarla. El tercer argumento es nulo pues no hay oldact
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{
		// El proceso se detiene y no consume recursos de CPU hasta recibir SIGUSR1/R2, y es entonces donde el handler se ejecuta 
		pause();

		// Comprueba si la variable global ha cambiado su valor inicial (es modificada en handler)
		if (g_char_status != 0)
		{
			// De haber cambiado, significa que ha recibido la senyal
			if (g_char_status == 1)
				ft_printf("\n");
			
			// En caso de no ser 0 ni 1, significa que es un caracter codificado
			else
			{
				char_to_print = (char)(g_char_status - 2);
				ft_printf("%c", char_to_print);
			}
			g_char_status = 0;
		}
	}
	ft_printf("\n");
	return (0);
}

/*	DECODIFICA LOS BITS  
	signo: tipo de senyal recibida (SIGUSR1 / SIGUSR2)
	siginfo_t info: esta estructura permite acceder al informacion detallada de la senyal (para esto se ha admitido SIGINFO)
	moreinfo no se usa pero tampoco se puede prescindir pq sigaction se queja :p
*/
void	handler(int signo, siginfo_t *info, void *more_info)
{
	static char		c = 0;
	static int		bits_recibidos = 0;
	static pid_t	client = 0;		// Almacena el PID del cliente que envia senyales

	(void)more_info;
	// Si es la primera senyal que recibe del cliente y existe la estructura, guarda el PID de cliente de modo que el servidor sepa a quien responder
	if (client == 0 && info->si_pid)
		client = info->si_pid;

	// (el operador >> desplaza bits_recibidos veces el bit a la derecha y el operador OR ejecuta dicha operacion sobre el bit desplazado)
	/* SIRGUSR1
		El objetivo es establecer el bit corespondiente a c a 1 sin modificar los bits ya decodificados
		Esta operacion establece a 1 el bit apuntado por bits_recibidos
	*/
	if (signo == SIGUSR1)
		c = c | (0b10000000 >> bits_recibidos);
	else if (SIGUSR2 == signo)
	/* SIGUSR2
		NAND niega todos los bit y mantiene el mas significativo
	*/
		c &= ~(0b10000000 >> bits_recibidos);
	bits_recibidos++;

	// Una vez procesado el bit, el servidor envia SIGUSR1 al cliente a modo de ACK (la funcion kill() envia dicha senyal al proceso senyalado por el pid de client)
	if (client != 0)
		muelto(client, SIGUSR1);
	
	// Si ya se han recibido los 8 bits (el tamanyo de un byte de char) se reinicia el contador
	if (bits_recibidos == CHAR_BIT)
	{
		bits_recibidos = 0;
		if (c == '\0')
		{
			g_char_status = 1;
			muelto(client, SIGUSR2);
			client = 0;
		}
		else
			// Si el caracter no es nulo se suma dos porque las posiciones 0 y 1 estan reservadas
			g_char_status = (int)c + 2;
		c = 0;
	}
}
