/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseivane <oseivane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:24:22 by oseivane          #+#    #+#             */
/*   Updated: 2023/10/09 15:28:03 by oseivane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	var_init(t_message *var)
{
	var->char_v = 0;
	var->bit_p = 0;
}

void	actioner(int signal, siginfo_t *info, void *content)
{
	static t_message	message;

	(void)content;
	if (message.pid != info->si_pid)
		var_init(&message);
	if (info->si_pid)
		message.pid = info->si_pid;
	(message.char_v) = (message.char_v) | (signal == SIGUSR1);
	if (++(message.bit_p) == 8)
	{
		if (!(message.char_v))
		{
			kill(message.pid, SIGUSR1);
			return ;
		}
		ft_putchar(message.char_v);
		kill(message.pid, SIGUSR2);
		var_init(&message);
	}
	else
		(message.char_v) = (message.char_v) << 1;
}

/*
En este main:
- Se recoge el pid del proceso y se imprimer por pantalla.
- En SR se guarda info sobre su sig_action (activado 
por actioner con 3 argumentos) y el en el sagflag se guarda
el saginfo, concretamente el si_pid (sending process). 
- La llamada al sistema sigaction() se utiliza para 
cambiar la acción que realiza un proceso al recibir 
una señal específica. El primer argumento puede ser
cualquier senal valida excepto dos. el segundo argumento si 
no es NULL, se instala desde el primer argumento, el tercero
al ser NULL la acc'ion anterior no se guarda en ella.
*/

int	main(void)
{
	struct sigaction	sr;
	pid_t				pid_server;

	pid_server = getpid();
	ft_putnbr(pid_server);
	sr.sa_sigaction = actioner;
	sr.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sr, NULL);
	sigaction(SIGUSR2, &sr, NULL);
	while (1)
		pause();
	return (0);
}
