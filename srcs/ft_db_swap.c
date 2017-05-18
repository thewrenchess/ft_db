/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_db_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yherrera <yherrera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 15:58:22 by yherrera          #+#    #+#             */
/*   Updated: 2017/05/04 19:50:25 by yherrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_db.h"

void	ft_intswap(t_tab *tab, int c, int a, int b)
{
	int	temp;

	temp = tab->e[a][c].i;
	tab->e[a][c].i = tab->e[b][c].i;
	tab->e[b][c].i = temp;
}

void	ft_charswap(t_tab *tab, int c, int a, int b)
{
	char	temp;

	temp = tab->e[a][c].c;
	tab->e[a][c].c = tab->e[b][c].c;
	tab->e[b][c].c = temp;
}

void	ft_strswap(t_tab *tab, int c, int a, int b)
{
	char	temp[LINEMAX];

	strcpy(temp, tab->e[a][c].str);
	strcpy(tab->e[a][c].str, tab->e[b][c].str);
	strcpy(tab->e[b][c].str, temp);
}

void	ft_db_swap(t_tab *tab, int a, int b)
{
	int	i;

	i = 0;
	while (i < tab->c)
	{
		if (!strcmp(tab->col[i].t, "int"))
			ft_intswap(tab, i, a, b);
		else if (!strcmp(tab->col[i].t, "char"))
			ft_charswap(tab, i, a, b);
		else
			ft_strswap(tab, i, a, b);
		i++;
	}
}