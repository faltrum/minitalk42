/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseivane <oseivane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:26:17 by oseivane          #+#    #+#             */
/*   Updated: 2023/10/16 09:59:22 by oseivane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	action(int signal)
{
	static int	bytes_received;

	bytes_received = 0;
	if (signal == SIGUSR2)
		bytes_received++;
	else
		exit(EXIT_SUCCESS);
}

void	send_signal(pid_t pid, char *str)
{
	int		i;
	int		j;

	j = -1;
	while (str[++j])
	{
		i = 8;
		while (i--)
		{
			if (str[j] >> i & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(100);
		}
	}
	i = 8;
	while (i--)
	{
		kill(pid, SIGUSR2);
		usleep(100);
	}
}

int	main(int argc, char **argv)
{
	int	string_len;

	string_len = ft_strlen(argv[2]);
	if (argc != 3)
		ft_error();
	if (!string_len || !ft_atoi(argv[1]))
		ft_error();
	signal(SIGUSR1, action);
	signal(SIGUSR2, action);
	send_signal(ft_atoi(argv[1]), argv[2]);
	while (1)
		pause();
	return (0);
}
