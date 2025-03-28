/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleichtn <lleichtn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:27:20 by lleichtn          #+#    #+#             */
/*   Updated: 2024/11/25 15:42:00 by lleichtn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Function to print a number in hexadecimal format
int	ft_puthex(unsigned long n, char format)
{
	int		len;
	char	*hex;

	len = 0;
	if (format == 'x')
		hex = "0123456789abcdef";
	if (format == 'X')
		hex = "0123456789ABCDEF";
	if (n >= 16)
		len += ft_puthex(n / 16, format);
	len += ft_putchar(hex[n % 16]);
	return (len);
}
