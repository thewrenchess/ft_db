/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_table.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yherrera <yherrera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 21:24:01 by dhuang            #+#    #+#             */
/*   Updated: 2017/05/04 19:34:44 by yherrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_db.h"

int		ft_close(FILE *fp, char *name, t_tab *tab)
{
	if (!fclose(fp))
	{
		printf("Table %s successfully closed.\n", name);
		if (!unlink(name))
			printf("Table %s successfully destroyed.\n", name);
		else
		{
			fprintf(stderr, "Failed to remove %s (%d: %s)\n",
					name, errno, strerror(errno));
			return (0);
		}
		if ((fp = fopen(name, "w+")))
			comparecloseinput(fp, name, tab);
		else
			fprintf(stderr, "Failed to create %s (%d: %s)\n",
					name, errno, strerror(errno));
		return (1);
	}
	else
		fprintf(stderr, "Failed to close %s (%d: %s)\n",
				name, errno, strerror(errno));
	return (0);
}

void	ft_add(t_tab *tab)
{
	int		i;

	if (tab->r < RMAX)
	{
		tab->r++;
		i = 0;
		printf("Now adding entry #%d\n", tab->r);
		while (i < tab->c)
		{
			printf("For column #%d named %s of type %s:\n",
					i + 1, tab->col[i].n, tab->col[i].t);
			if (!strcmp(tab->col[i].t, "int"))
				ft_getint(&tab->e[tab->r - 1][i].i);
			else if (!strcmp(tab->col[i].t, "char"))
				ft_getchar(&tab->e[tab->r - 1][i].c);
			else if (!strcmp(tab->col[i].t, "char*"))
				ft_getstr(tab->e[tab->r - 1][i].str);
			i++;
		}
	}
	else
		fprintf(stderr, "Cannot add more row entries (maximum = %d)\n", RMAX);
}

void	deletechecktype(t_tab *tab, int n)
{
	int	i;

	i = 0;
	printf("Now deleting entry #%d\n", n);
	while (i < tab->c)
	{
		if (!strcmp(tab->col[i].t, "int"))
			tab->e[n - 1][i].i = 0;
		else if (!strcmp(tab->col[i].t, "char"))
			tab->e[n - 1][i].c = 0;
		else if (!strcmp(tab->col[i].t, "char*"))
			bzero(tab->e[n - 1][i].str, LINEMAX);
		i++;
	}
}

void	ft_delete(t_tab *tab)
{
	int		n;

	if (tab->r > 0)
	{
		n = 0;
		while (n < 1 || n > tab->r)
		{
			printf("Which row would you like to remove?\n");
			ft_display(*tab);
			ft_getint(&n);
		}
		tab->r--;
		while (n < tab->r + 1)
		{
			ft_db_swap(tab, n - 1, n);
			n++;
		}
	}
	else
		fprintf(stderr, "There are no more row entries to remove!\n");
}

void	ft_table(FILE *fp, char *name)
{
	char	str[LINEMAX];
	int		end;
	t_tab	tab;

	tab.name = name;
	ft_parse(fp, &tab);
	end = 0;
	while (!end)
	{
		bzero(str, LINEMAX);
		printf("What would you like to do with table %s?\n", name);
		printf("(display/sort/add/remove/close)\n");
		ft_getstr(str);
		if (!strcmp(str, "close"))
			end = ft_close(fp, name, &tab);
		if (!strcmp(str, "display"))
			ft_display(tab);
		if (!strcmp(str, "sort"))
			ft_sort(&tab);
		if (!strcmp(str, "add"))
			ft_add(&tab);
		if (!strcmp(str, "remove"))
			ft_delete(&tab);
	}
}
