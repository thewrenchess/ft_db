/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yherrera <yherrera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 12:16:15 by yherrera          #+#    #+#             */
/*   Updated: 2017/05/04 20:05:28 by yherrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_db.h"

int		ft_displaywidth(t_tab tab)
{
	char	tmp[DCOLMAX + 10];
	int		n;
	int		w;
	int		j;

	w = 0;
	j = 0;
	while (j < tab.c)
	{
		n = snprintf(tmp, DCOLMAX, "%s(%s)", tab.col[j].n, tab.col[j].t);
		bzero(tmp, DCOLMAX + 10);
		if (n > w)
			w = n;
		j++;
	}
	return (w);
}

int		ft_displaycol(t_tab tab)
{
	char	str[DLINEMAX];
	char	tmp[DLINEMAX];
	int		w;
	int		n;
	int		j;

	w = ft_displaywidth(tab);
	bzero(str, DLINEMAX);
	sprintf(str, "    ");
	j = 0;
	while (j < tab.c)
	{
		bzero(tmp, DLINEMAX);
		n = snprintf(tmp, DCOLMAX, "%s(%s)", tab.col[j].n, tab.col[j].t);
		strcat(str, tmp);
		while (n++ <= w)
			strcat(str, " ");
		j++;
	}
	printf("%s\n", str);
	return (w);
}

int		setn(t_tab tab, t_int t, char *tmp)
{
	if (!strcmp(tab.col[t.j].t, "int"))
		return (snprintf(tmp, DCOLMAX, "%d", tab.e[t.i][t.j].i));
	else if (!strcmp(tab.col[t.j].t, "char"))
		return (snprintf(tmp, DCOLMAX, "%c", tab.e[t.i][t.j].c));
	else
		return (snprintf(tmp, DCOLMAX, "%s", tab.e[t.i][t.j].str));
}

void	ft_display(t_tab tab)
{
	char	str[DLINEMAX];
	char	tmp[DLINEMAX];
	t_int	t;

	t.w = ft_displaycol(tab);
	t.i = 0;
	while (t.i < tab.r)
	{
		bzero(str, DLINEMAX);
		sprintf(str, "(%d) ", t.i + 1);
		t.j = 0;
		while (t.j < tab.c)
		{
			bzero(tmp, DLINEMAX);
			t.n = setn(tab, t, tmp);
			strcat(str, tmp);
			while (t.n++ <= t.w)
				strcat(str, " ");
			t.j++;
		}
		printf("%s\n", str);
		t.i++;
	}
}
