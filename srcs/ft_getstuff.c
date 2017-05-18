/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getstuff.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhuang <dhuang@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 21:26:04 by dhuang            #+#    #+#             */
/*   Updated: 2017/05/02 21:26:04 by dhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_db.h"

void	ft_getstr(char *str)
{
	char	tmp[LINEMAX];

	bzero(tmp, LINEMAX);
	fgets(tmp, LINEMAX - 1, stdin);
	sscanf(tmp, " %[^\n]s", str);
}

void	ft_getint(int *n)
{
	char	tmp[LINEMAX];

	bzero(tmp, LINEMAX);
	fgets(tmp, LINEMAX - 1, stdin);
	sscanf(tmp, " %d\n", n);
}

void	ft_getchar(char *c)
{
	char	tmp[LINEMAX];

	bzero(tmp, LINEMAX);
	fgets(tmp, LINEMAX - 1, stdin);
	sscanf(tmp, " %c\n", c);
}
