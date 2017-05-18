/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yherrera <yherrera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 16:48:46 by dhuang            #+#    #+#             */
/*   Updated: 2017/05/04 18:41:45 by yherrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_db.h"

void	ft_exit(void)
{
	printf("Now exiting ft_db...\n");
	exit(0);
}

void	ft_create(void)
{
	char	str[LINEMAX];

	bzero(str, LINEMAX);
	while (!str[0])
	{
		bzero(str, LINEMAX);
		printf("What would you like to name your database?\n");
		ft_getstr(str);
	}
	if (!mkdir(str, 0777))
		printf("Database: %s created.\n", str);
	else
		fprintf(stderr, "Failed to create %s (%d: %s)\n",
				str, errno, strerror(errno));
}

void	ft_destroy(void)
{
	char	str[LINEMAX];
	char	conf[LINEMAX];

	bzero(str, LINEMAX);
	while (!str[0])
	{
		bzero(str, LINEMAX);
		printf("Which database would you like to destroy?\n");
		ft_readdir();
		ft_getstr(str);
		if (!strcmp(str, "..") || !strcmp(str, "."))
		{
			fprintf(stderr,
					"You do not have permission to delete system folders!\n");
			bzero(str, LINEMAX);
		}
	}
	bzero(conf, LINEMAX);
	printf("Are you sure you want to delete database %s? (Y/N)\n", str);
	ft_getstr(conf);
	comparedestroyinput(conf, str);
}

int		main(void)
{
	char		str[LINEMAX];
	struct stat	st;
	
	if (stat("db", &st) == -1)
		mkdir("db", 0777);
	if (!chdir("db"))
	{
		while (1)
		{
			bzero(str, LINEMAX);
			printf("What would you like to do? (create/destroy/open/exit)\n");
			ft_getstr(str);
			comparemaininput(str);
		}
	}
	else
		fprintf(stderr, "Failed to open db directory (%d: %s)\n",
				errno, strerror(errno));
	return (0);
}
