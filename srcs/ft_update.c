/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yherrera <yherrera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 20:14:07 by yherrera          #+#    #+#             */
/*   Updated: 2017/05/04 20:15:05 by yherrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_db.h"

void	updatetofile(FILE *fp, t_tab *tab, int j)
{
	int	i;

	i = 0;
	while (i < tab->c)
	{
		if (!strcmp(tab->col[i].t, "int"))
			fprintf(fp, "%d", tab->e[j][i].i);
		else if (!strcmp(tab->col[i].t, "char"))
			fprintf(fp, "%c", tab->e[j][i].c);
		else if (!strcmp(tab->col[i].t, "char*"))
		{
			spacetounderscore(tab->e[j][i].str);
			fprintf(fp, "%s", tab->e[j][i].str);
		}
		if (i == tab->c - 1)
			fprintf(fp, "\n");
		else
			fprintf(fp, " ");
		i++;
	}
}

void	ft_update(FILE *fp, t_tab *tab)
{
	int	i;
	int	j;

	fprintf(fp, "%d\n", tab->c);
	i = 0;
	while (i < tab->c)
	{
		fprintf(fp, "%s %s\n", tab->col[i].n, tab->col[i].t);
		i++;
	}
	fprintf(fp, "%d\n", tab->r);
	j = 0;
	while (j < tab->r)
	{
		updatetofile(fp, tab, j);
		j++;
	}
}
