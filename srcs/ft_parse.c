/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yherrera <yherrera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 23:55:15 by dhuang            #+#    #+#             */
/*   Updated: 2017/05/04 20:18:29 by yherrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_db.h"

void	underscoretospace(char *str)
{
	while (*str)
	{
		if (*str == '_')
			*str = ' ';
		str++;
	}
}

void	parsefile(FILE *fp, t_tab *tab, int j)
{
	int	i;

	i = 0;
	while (i < tab->c)
	{
		if (!strcmp(tab->col[i].t, "int"))
			fscanf(fp, " %d", &tab->e[j][i].i);
		else if (!strcmp(tab->col[i].t, "char"))
			fscanf(fp, " %c", &tab->e[j][i].c);
		else if (!strcmp(tab->col[i].t, "char*"))
		{
			fscanf(fp, " %s", tab->e[j][i].str);
			underscoretospace(tab->e[j][i].str);
		}
		i++;
	}
}

void	ft_parse(FILE *fp, t_tab *tab)
{
	int		i;
	int		j;

	fscanf(fp, "%d\n", &tab->c);
	i = 0;
	while (i < tab->c)
	{
		fscanf(fp, "%s %s\n", tab->col[i].n, tab->col[i].t);
		i++;
	}
	fscanf(fp, "%d\n", &tab->r);
	j = 0;
	while (j < tab->r)
	{
		parsefile(fp, tab, j);
		fscanf(fp, "\n");
		j++;
	}
}

void	spacetounderscore(char *str)
{
	while (*str)
	{
		if (*str == ' ')
			*str = '_';
		str++;
	}
}
