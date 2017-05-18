/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_compareinput.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yherrera <yherrera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 18:38:49 by yherrera          #+#    #+#             */
/*   Updated: 2017/05/04 19:28:32 by yherrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_db.h"

t_types 		g_typetab[] =
{
	{"int"},
	{"char"},
	{"char*"},
};

void	comparecloseinput(FILE *fp, char *name, t_tab *tab)
{
	printf("Table %s created successfully.\n", name);
	ft_update(fp, tab);
	if (!fclose(fp))
		printf("Table %s updated successfully.\n", name);
	else
		fprintf(stderr, "Failed to update %s (%d: %s)\n",
				name, errno, strerror(errno));
}

void	tablesetupinput(FILE *fp, int col)
{
	char	str[LINEMAX];
	int		t;
	int		i;

	i = 0;
	while (++i <= col)
	{
		t = 0;
		bzero(str, LINEMAX);
		printf("What is the name of column #%d?\n", i);
		ft_getstr(str);
		spacetounderscore(str);
		fprintf(fp, "%s ", str);
		while (t < 1 || t > 3)
		{
			printf("What data type is column #%d? (1/2/3)\n", i);
			printf("1. int\n2. char\n3. str\n");
			ft_getint(&t);
			if (t > 0 && t < 4)
				fprintf(fp, "%s\n", g_typetab[t - 1].type);
		}
	}
}

void	compareopeninput(char *str)
{
	int	end;

	end = 0;
	while (!end)
	{
		bzero(str, LINEMAX);
		printf("What would you like to do? (open/create/destroy/back/exit)\n");
		ft_getstr(str);
		if (!strcmp(str, "open"))
			ft_openfile();
		if (!strcmp(str, "create"))
			ft_newfile();
		if (!strcmp(str, "destroy"))
			ft_destroytable();
		if (!strcmp(str, "back"))
			end = 1;
		if (!strcmp(str, "exit"))
			ft_exit();
	}
}

void	comparedestroyinput(char *conf, char *str)
{
	if (!strcmp(conf, "Y"))
	{
		if (!rmdir(str))
			printf("Destruction successful.\n");
		else
			fprintf(stderr, "Failed to remove %s (%d: %s)\n",
					str, errno, strerror(errno));
	}
	else
		printf("Destruction aborted.\n");
}

void	comparemaininput(char *str)
{
	if (!strcmp(str, "exit"))
		ft_exit();
	if (!strcmp(str, "create"))
		ft_create();
	if (!strcmp(str, "destroy"))
		ft_destroy();
	if (!strcmp(str, "open"))
		ft_open();
}
