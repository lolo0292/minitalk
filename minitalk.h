/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleichtn <lleichtn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 11:32:02 by lleichtn          #+#    #+#             */
/*   Updated: 2025/02/06 13:59:22 by lleichtn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

void	ft_handler(int signal);
void	send_char(int pid, char c);
int		ft_putchar(char c);
int		ft_printf(const char *str, ...);
void	ft_handler(int signal);
int		ft_atoi(const char *nptr);
int		ft_putnbr(int n);

#endif