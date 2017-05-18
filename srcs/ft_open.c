/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yherrera <yherrera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 17:33:05 by dhuang            #+#    #+#             */
/*   Updated: 2017/05/04 20:26:18 by yherrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_db.h"

void	ft_tablesetup(FILE *fp, char name[100])
{
	int				col;

	col = 0;
	while (col <= 0 || col > CMAX)
	{
		printf("How many columns should table %s have? (maximum = %d)\n",
				name, CMAX);
		ft_getint(&col);
	}
	fprintf(fp, "%d\n", col);
	tablesetupinput(fp, col);
	fprintf(fp, "0\n");
	fseek(fp, 0, SEEK_SET);
	ft_table(fp, name);
}

void	ft_newfile(void)
{
	char		str[LINEMAX];
	struct stat	st;
	FILE		*fp;

	bzero(str, LINEMAX);
	while (!str[0])
	{
		printf("What would you like to name your new table?\n");
		ft_getstr(str);
	}
	if (stat(str, &st) == -1)
	{
		if ((fp = fopen(str, "w+")))
		{
			printf("Table %s created successfully.\n", str);
			ft_tablesetup(fp, str);
		}
		else
			fprintf(stderr, "Failed to create table %s (%d: %s)\n",
					str, errno, strerror(errno));
	}
	else
		fprintf(stderr, "Create failed: table %s already exists.\n", str);
}

void	ft_openfile(void)
{
	char		str[LINEMAX];
	struct stat	st;
	FILE		*fp;

	bzero(str, LINEMAX);
	while (!str[0])
	{
		printf("Which table would you like to open?\n");
		ft_readfiles();
		ft_getstr(str);
	}
	if (!stat(str, &st))
	{
		if ((fp = fopen(str, "r+")))
		{
			printf("Table %s opened successfully.\n", str);
			ft_table(fp, str);
		}
		else
			fprintf(stderr, "Failed to open table %s (%d: %s)\n",
					str, errno, strerror(errno));
	}
	else
		fprintf(stderr, "Open failed: table %s does not exist.\n", str);
}

void	ft_destroytable(void)
{
	char		str[LINEMAX];
	struct stat	st;

	bzero(str, LINEMAX);
	while (!str[0])
	{
		printf("Which table would you like to destroy?\n");
		ft_readfiles();
		ft_getstr(str);
	}
	if (!stat(str, &st))
	{
		if (!unlink(str))
			printf("Table %s successfully destroyed.\n", str);
		else
			fprintf(stderr, "Failed to remove %s (%d: %s)\n",
					str, errno, strerror(errno));
	}
	else
		fprintf(stderr, "Destroy failed: table %s does not exist.\n", str);
}

void	ft_open(void)
{
	char		str[LINEMAX];
	
	bzero(str, LINEMAX);
	while(!str[0])
	{
		bzero(str, LINEMAX);
		printf("What database would you like to open?");
		printf(" (type in database name or enter exit to exit)\n");
		ft_readdir();
		ft_getstr(str);
		if (!strcmp(str, "exit"))
			ft_exit();
		if (!strcmp(str, "..") || !strcmp(str, "."))
			fprintf(stderr, "System folder .. and . are not databases!\n");
	}
	if (!chdir(str))
	{
		compareopeninput(str);
		chdir("..");
	}
	else
		fprintf(stderr, "Failed to open database %s (%d: %s)\n",
				str, errno, strerror(errno));
}
