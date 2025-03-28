/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleichtn <lleichtn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 11:31:48 by lleichtn          #+#    #+#             */
/*   Updated: 2025/03/28 14:42:55 by lleichtn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*g_message = NULL;
// signal handler fct
// void	ft_handler(int signal)
// {
// 	static int	bit_pos;
// 	static int	c;

// 	if (signal == SIGUSR1)
// 		c |= (1 << bit_pos);
// 	bit_pos++;
// 	if (bit_pos == 8)
// 	{
// 		ft_printf("%c", c);
// 		c = 0;
// 		bit_pos = 0;
// 	}
// }
void	handle_signal(int sig)
{
	static int	bit = 0;
	static char	c = 0;

	if (sig == SIGUSR1)
		c |= (1 << bit);
	bit++;
	if (bit == 8)
	{
		if (c == '\0')
		{
			write(1, g_message, ft_strlen(g_message));
			write(1, "\n", 1);
			free(g_message);
			g_message = NULL;
		}
		else
			g_message = ft_strjoin_char(g_message, c);
		bit = 0;
		c = 0;
	}
}


int	main(int argc, char **argv)
{
	int	pid;

	(void)argv;
	if (argc != 1)
	{
		return (1);
	}
	pid = getpid();
	ft_printf("Server PID: %d\n", pid);
	signal(SIGUSR1, handle_signal);
	signal(SIGUSR2, handle_signal);
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