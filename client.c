/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleichtn <lleichtn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 11:31:59 by lleichtn          #+#    #+#             */
/*   Updated: 2025/02/06 13:44:03 by lleichtn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

// Convert a character into binary and send as signals
void	send_char(int pid, char c)
{
	int	bit_pos;

	bit_pos = 0;
	while (bit_pos < 8)
	{
		if ((c >> bit_pos) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		bit_pos++;
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	if (argc != 3)
	{
		ft_printf("Usage: %s <server_pid> <message>\n", argv[0]);
		return (1);
	}
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
	{
		ft_printf("Error: Invalid PID\n");
		return (1);
	}
	i = 0;
	while (argv[2][i])
	{
		send_char(pid, argv[2][i]);
		i++;
	}
	send_char(pid, '\0');
	return (0);
}

// int	main(int argc, char **argv)
// {
// 	int	pid;
// 	int	i;

// 	if (argc != 3)
// 	{
// 		ft_printf("Usage: %s <server_pid> <message>\n", argv[0]);
// 		return (1);
// 	}
// 	pid = ft_atoi(argv[1]);
// 	if (pid <= 0)
// 	{
// 		ft_printf("Error: Invalid PID\n");
// 		return (1);
// 	}
// 	i = 0;
// 	while (argv[2][i])
// 	{
// 		send_char(pid, argv[2][i]);
// 		i++;
// 	}
// 	send_char(pid, '\0');
// 	return (0);
// }

/*Convert a character into binary and send as signals
void	send_char(int pid, char c)
{
	int	bit_pos;

	bit_pos = 0;
	while (bit_pos < 8)
	{
		if ((c >> bit_pos) & 1) // Check if the bit is 1
			kill(pid, SIGUSR1); // Send SIGUSR1 for bit 1
		else
			kill(pid, SIGUSR2); // Send SIGUSR2 for bit 0
		usleep(100); // Small delay to ensure proper signal handling 100ms
		bit_pos++;
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	if (argc != 3) // Ensure correct usage
	{
		ft_printf("Usage: %s <server_pid> <message>\n", argv[0]);
		return (1);
	}
	pid = ft_atoi(argv[1]); // Convert server PID to int
	if (pid <= 0) // Validate PID
	{
		ft_printf("Error: Invalid PID\n");
		return (1);
	}
	i = 0;
	while (argv[2][i]) // Send message character by character
	{
		send_char(pid, argv[2][i]);
		i++;
	}
	send_char(pid, '\0'); // Send null terminator to signal end of message
	return (0);
}
*/
