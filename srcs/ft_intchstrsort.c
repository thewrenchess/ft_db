/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intchstrsort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yherrera <yherrera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 15:54:57 by yherrera          #+#    #+#             */
/*   Updated: 2017/05/04 19:48:56 by yherrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_db.h"

void	ft_intsort(t_tab *tab, int c, char order)
{
	int	i;
	int	j;

	i = 0;
	while (i < tab->r)
	{
		j = i + 1;
		while (j < tab->r)
		{
			if (order == '+' && tab->e[i][c].i > tab->e[j][c].i)
				ft_db_swap(tab, i, j);
			else if (order == '-' && tab->e[i][c].i < tab->e[j][c].i)
				ft_db_swap(tab, i, j);
			j++;
		}
		i++;
	}
}

void	ft_charsort(t_tab *tab, int c, char order)
{
	int	i;
	int	j;

	i = 0;
	while (i < tab->r)
	{
		j = i + 1;
		while (j < tab->r)
		{
			if (order == '+' && tab->e[i][c].c > tab->e[j][c].c)
				ft_db_swap(tab, i, j);
			else if (order == '-' && tab->e[i][c].c < tab->e[j][c].c)
				ft_db_swap(tab, i, j);
			j++;
		}
		i++;
	}
}

void	ft_strsort(t_tab *tab, int c, char order)
{
	int	i;
	int	j;

	i = 0;
	while (i < tab->r)
	{
		j = i + 1;
		while (j < tab->r)
		{
			if (order == '+' && strcmp(tab->e[i][c].str, tab->e[j][c].str) > 0)
				ft_db_swap(tab, i, j);
			if (order == '-' && strcmp(tab->e[i][c].str, tab->e[j][c].str) < 0)
				ft_db_swap(tab, i, j);
			j++;
		}
		i++;
	}
}
