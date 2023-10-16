/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseivane <oseivane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:24:52 by oseivane          #+#    #+#             */
/*   Updated: 2023/10/16 09:59:41 by oseivane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <stdio.h>

typedef struct s_message
{
	int		char_v;
	int		bit_p;
	pid_t	pid;
}	t_message;

void	ft_error(void);
int		ft_atoi(const char *str);
int		ft_strlen(const char *str);
void	var_init(t_message *var);
void	actioner(int signal, siginfo_t *info, void *content);
void	action(int signal);
void	send_signal(pid_t pid, char *str);
void	ft_putchar(char c);
void	ft_putnbr(int n);

#endif
