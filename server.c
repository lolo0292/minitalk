/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleichtn <lleichtn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 11:31:48 by lleichtn          #+#    #+#             */
/*   Updated: 2025/02/06 13:42:02 by lleichtn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

//signal handler fct
void	ft_handler(int signal)
{
	static int	bit_pos;
	static int	c;

	if (signal == SIGUSR1)
		c |= (1 << bit_pos);
	bit_pos++;
	if (bit_pos == 8)
	{
		ft_printf("%c", c);
		c = 0;
		bit_pos = 0;
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	(void)argv;
	if (argc != 1)
	{
		ft_printf("Error: wrong format.\n");
		return (1);
	}
	pid = getpid();
	ft_printf("Server PID: %d\n", pid);
	signal(SIGUSR1, ft_handler);
	signal(SIGUSR2, ft_handler);
	while (1)
		pause();
	return (0);
}

/*//signal handler fct
void	ft_handler(int signal)
{
	static int 	bit_pos;
	static int 	c;

	if (signal == SIGUSR1)
		c |= (1 << bit_pos); //set bit
	bit_pos++;
	if (bit_pos == 8) //charactr in ascii is 8bits
	{
		ft_printf("%c", c);
		c = 0;
		bit_pos = 0;
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	(void)argv;
	if (argc != 1)
	{
		ft_printf("Error: wrong format.\n");
		return (1);
	}
	pid = getpid(); //system call that returns the PID
	ft_printf("Server PID: %d\n", pid);
	// ft_printf("Waiting for messages...\n");
	signal(SIGUSR1, ft_handler); //if received it calls ft_handler =1
	signal(SIGUSR2, ft_handler); //if received it calls ft_handler =0
	while (1)
		pause();
	return (0);
}*/