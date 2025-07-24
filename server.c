/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avelandr <avelandr@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 17:07:47 by avelandr          #+#    #+#             */
/*   Updated: 2025/07/24 22:52:27 by avelandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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

 #include "minitalk.h"

// Una única variable global para almacenar el estado y el carácter.
// 0: No hay carácter listo.
// 1: Carácter nulo ('\0') listo (fin de mensaje).
// 2 a 257: Carácter ASCII (valor_ascii + 2) listo.

volatile sig_atomic_t g_char_status = 0;

int	main(void)
{
	struct sigaction	sa;
	pid_t				pid;
    char                char_to_print;

	pid = getpid();
    char pid_str[MAX_PID]; // Suficiente espacio para "PID -> ", el número y '\n'
    int len = snprintf(pid_str, sizeof(pid_str), "PID -> %d\n", pid);
    write(STDOUT_FILENO, pid_str, len);

	ft_bzero(&sa, sizeof(sa));
	sa.sa_flags = SA_SIGINFO | SA_RESTART; // SA_RESTART: reanuda llamadas al sistema interrumpidas
	sa.sa_sigaction = handler; // Asigna nuestro manejador de señales

	// Bloquea SIGUSR1 y SIGUSR2 mientras el manejador se ejecuta para evitar interrupciones
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);

	// Registra los manejadores para SIGUSR1 y SIGUSR2
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);

	while (1)
	{
		pause(); // El servidor espera pasivamente por cualquier señal.
                 // Cuando una señal llega y el handler termina, pause() retorna.

        // Comprueba el valor de la variable global después de que pause() retorne.
        if (g_char_status != 0) // Si la variable global no es 0, hay algo que procesar
        {
            if (g_char_status == 1) // Es el valor especial para '\0' (fin de mensaje)
            {
                write(STDOUT_FILENO, "\n", 1); // Imprime un salto de línea
            }
            else // Es un carácter ASCII codificado
            {
                char_to_print = (char)(g_char_status - 2); // Recupera el valor original del carácter
                write(STDOUT_FILENO, &char_to_print, 1); // Imprime el carácter
            }
            g_char_status = 0; // Resetea la variable global después de procesarla
        }
	}
	return (0);
}

// server.c
void    handler(int signo, siginfo_t *info, void *more_info)
{
    (void)more_info;

    static char        c = 0;
    static int        bit = 0;
    static pid_t    client = 0;

    if (client == 0 && info->si_pid)
        client = info->si_pid;

    if (SIGUSR1 == signo)
        c = c | (0b10000000 >> bit);
    else if (SIGUSR2 == signo)
        c &= ~(0x80 >> bit);
    bit++;

    // ***** AÑADE ESTO: Envía un ACK al cliente DESPUÉS de procesar CADA BIT *****
    // Esto es para que el cliente salga de su bucle 'while (g_server == BUSY)'
    if (client != 0) // Asegúrate de que client_pid ya está establecido
        Kill(client, SIGUSR1); // Envía una señal ACK al cliente (puede ser SIGUSR1 o SIGUSR2, lo importante es que el cliente la maneje para resetear g_server)

    if (CHAR_BIT == bit)
    {
        bit = 0;

        if (c == '\0')
        {
            g_char_status = 1;
            Kill(client, SIGUSR2); // Este ACK es para el fin de mensaje
            client = 0;
        }
        else
        {
            g_char_status = (int)c + 2;
            // No necesitas Kill(client, SIGUSR1) aquí, ya lo hiciste arriba para cada bit.
            // Si el cliente necesita un ACK especial para caracter completo, entonces sí.
        }
        c = 0;
    }
}
