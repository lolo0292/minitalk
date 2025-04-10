/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleichtn <lleichtn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 16:47:15 by lleichtn          #+#    #+#             */
/*   Updated: 2025/03/28 14:39:54 by lleichtn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*ft_strjoin_char(char *s, char c)
{
	int		len;
	char	*new;
	int		i;

	len = 0;
	while (s && s[len])
		len++;
	new = malloc(len + 2);
	if (!new)
		return (NULL);
	i = -1;
	while (++i < len)
		new[i] = s[i];
	new[i++] = c;
	new[i] = '\0';
	free(s);
	return (new);
}
