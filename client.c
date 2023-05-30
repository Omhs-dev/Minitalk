/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohamadou <ohamadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 04:08:07 by ohamadou          #+#    #+#             */
/*   Updated: 2023/05/30 10:10:18 by ohamadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/minitalk.h"

//This function handle the signals received by the server
static void	message_receive(int signal)
{
	static int	msg;

	if (signal == SIGUSR2)
	{
		ft_printf("Message received in the server\n", msg);
		exit(0);
	}
}

//send inividual bits of a char to the client Process
static void	args_bits(int pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((c & (0x01 << bit)))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(500);
		bit++;
	}
}

int	main(int argc, char **argv)
{
	int			pid;
	int			len;
	static int	i;

	len = ft_strlen(argv[2]);
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		ft_printf("Message sent with %i characters\n", ft_strlen(argv[2]));
		while (i < len)
		{
			signal(SIGUSR1, message_receive);
			signal(SIGUSR2, message_receive);
			args_bits(pid, argv[2][i]);
			i++;
		}
		args_bits(pid, '\0');
	}
	else
	{
		ft_printf("Wrong format\n");
		ft_printf("Try: ./client <PID> <MESSAGE>\n");
		return (1);
	}
	return (0);
}
