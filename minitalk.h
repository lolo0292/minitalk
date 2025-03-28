/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleichtn <lleichtn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 11:32:02 by lleichtn          #+#    #+#             */
/*   Updated: 2025/03/28 14:44:20 by lleichtn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "./ft_printf/ft_printf.h"
# include "./libft/libft.h"

// void	ft_handler(int signal);
void	send_char(int pid, char c);
// int		ft_putchar(char c);
// int		ft_printf(const char *str, ...);
// void	ft_handler(int signal);
// int		ft_atoi(const char *nptr);
// int		ft_putnbr(int n);
void	process_character(char c, char *buffer, int *index);

char	*add_str(char c, char *str);

size_t	ft_strlen(const char *str);

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);

void	setup_action(void);

char	*ft_strjoin_char(char *s, char c);
void	handle_signal(int sig);



#endif