/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yherrera <yherrera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 13:50:46 by yherrera          #+#    #+#             */
/*   Updated: 2017/05/04 19:43:58 by yherrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_db.h"

void	ft_printcolnames(t_tab tab)
{
	int	i;

	printf("(%s", tab.col[0].n);
	i = 1;
	while (i < tab.c)
	{
		printf(" / %s", tab.col[i].n);
		i++;
	}
	printf(")\n");
}

int		ft_matchcolumn(t_tab tab, char *str)
{
	int	i;

	i = 0;
	while (i < tab.c)
	{
		if (!strcmp(tab.col[i].n, str))
			return (i);
		i++;
	}
	return (-1);
}

int		findcolumn(t_tab tab)
{
	char	str[LINEMAX];
	int		column;

	column = -1;
	while (column == -1)
	{
		bzero(str, 100);
		printf("Enter name of the column you'd like to sort the table by.\n");
		ft_printcolnames(tab);
		ft_getstr(str);
		column = ft_matchcolumn(tab, str);
		if (column == -1)
			printf("The column you are looking for does not exist.\n\n");
	}
	return column;
}

void	ft_sort(t_tab *tab)
{
	char	order;
	int		column;

	column = findcolumn(*tab);
	order = 'k';
	while (order != '+' && order != '-')
	{
		printf("How would you like to sort %s?", tab->col[column].n);
		printf(" (enter + for ascending or - for decending)\n");
		ft_getchar(&order);
	}
	if (!strcmp(tab->col[column].t, "int"))
		ft_intsort(tab, column, order);
	else if (!strcmp(tab->col[column].t, "char"))
		ft_charsort(tab, column, order);
	else
		ft_strsort(tab, column, order);
	printf("table is sorted.\n");
}
