/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 15:54:12 by kmahdi            #+#    #+#             */
/*   Updated: 2023/01/15 10:24:46 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	ft_putchar(char c)
{
	return (write (1, &c, 1));
}

int	ft_putnbr(int n)
{
	int				len;
	long long int	nb;

	nb = n;
	len = 0;
	if (nb < 0)
	{
		len += ft_putchar('-');
		nb = -nb;
	}
	if (nb >= 10)
	{
		len += ft_putnbr (nb / 10);
		len += ft_putnbr (nb % 10);
	}
	else
		len += ft_putchar((nb + '0'));
	return (len);
}

int	ft_putstr(char *s)
{
	if (s)
	{
		write (1, s, ft_strlen(s));
		return (ft_strlen(s));
	}
	return (ft_putstr("(null)"));
}

int	ft_unsg(unsigned int n)
{
	int	len;

	len = 0;
	if (n >= 0 && n < 10)
	{
		ft_putchar ((n + 48));
		len++;
	}
	else
	{
		len += ft_unsg (n / 10);
		len += ft_unsg (n % 10);
	}
	return (len);
}

char	*m_strjoin(char *s1, char *s2)
{
	size_t	i;
	char	*j;

	if (!s1)
		s1 = ft_calloc(1, 1);
	if (!s2 || s2[0] == 0)
		return (s1);
	i = 0;
	j = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!j)
		return (NULL);
	while (s1[i])
	{
		j[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		j[ft_strlen(s1) + i] = s2[i];
		i++;
	}
	j[ft_strlen(s1) + i] = '\0';
	return (j);
}
