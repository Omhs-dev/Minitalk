/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohamadou <ohamadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 04:54:14 by ohamadou          #+#    #+#             */
/*   Updated: 2023/06/02 00:25:13 by ohamadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/minitalk.h"

/*this function handle the signals received by the server porcess
it checks if the received signal is SIGUSR1. 
If so, it sets the corresponding bit in i by performing a 
bitwise OR operation (|=) with the bit value calculated based on bit.*/
static void	handle_ba(int signal, siginfo_t *info, void *context)
{
	static int	bit;
	static int	i;

	(void)context;
	if (signal == SIGUSR1)
		i |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		if (i == 0)
			kill(info -> si_pid, SIGUSR2);
		ft_printf("%c", (char)i);
		bit = 0;
		i = 0;
	}
}

/*set up the server that waits 
for signals SIGUSR1 and SIGUSR2*/
int	main(int argc, char **argv)
{
	int					pid;
	struct sigaction	act;

	(void)argv;
	if (argc != 1)
	{
		ft_printf("Wrong format\n");
		ft_printf("Try: ./server\n");
		return (1);
	}
	pid = getpid();
	ft_printf("PID Server: %i \n", pid);
	act.sa_sigaction = handle_ba;
	sigemptyset(&act.sa_mask);
	act.sa_flags = 0;
	while (argc == 1)
	{
		sigaction(SIGUSR1, &act, NULL);
		sigaction(SIGUSR2, &act, NULL);
		pause();
	}
	return (0);
}
