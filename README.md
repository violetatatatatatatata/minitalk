# Minitalk
Este es un proyecto cuyo propósito es crear un pequeño programa de intercambio de datos utilizando señales UNIX.

## Funcionalidad

El proyecto se compone de dos programas: un cliente y un servidor.

* `server`: El servidor debe lanzarse primero y, tras lanzarse, debe mostrar su PID.
* `client`: El cliente tomará como parámetros el PID del servidor y la string que debería mandarse. Una vez que el cliente haya comunicado la string, el servidor debe mostrarla.

La comunicación entre el cliente y el servidor debe hacerse SOLO utilizando señales UNIX: `SIGUSR1` y `SIGUSR2`

### Uso

Para usar el proyecto, primero compila ambos ejecutables con `make`:

```bash
$ make
````

Luego, inicia el servidor en una terminal. Te mostrará su PID:

```bash
$ ./server
PID: [número_del_pid]
```

Finalmente, en otra terminal, ejecuta el cliente, pasando el PID del servidor y el mensaje que deseas enviar:

```bash
$ ./client [número_del_pid] "Hola, mundo!"
```

El servidor recibirá el mensaje y lo imprimirá en su terminal.

Fuentes:
  - Señales en UNIX: http://www.inf.udec.cl/~chernand/sc/labs/senales.htm
  - En "server.c" volatile sig_atomic_t   g_char_status;
      Clasificador volatil: https://www.ibm.com/docs/es/i/7.5.0?topic=qualifiers-volatile-type-qualifier
      Estructuras atomicas: https://en.cppreference.com/w/c/program/sig_atomic_t
  - SIGACTION
      Struct: https://man7.org/linux/man-pages/man2/sigaction.2.html
  - Libreria <signals.h>
      https://pubs.opengroup.org/onlinepubs/7908799/xsh/signal.h.html
  - Operaciones bit a bit (para la decodificacion del mensaje en server.c)
      https://learn.microsoft.com/es-es/cpp/c-language/c-bitwise-operators?view=msvc-170
