/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readdir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yherrera <yherrera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 22:18:50 by dhuang            #+#    #+#             */
/*   Updated: 2017/05/03 12:02:37 by yherrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_db.h"

void	ft_readall(void)
{
	DIR				*d;
	struct dirent	*dir;

	d = opendir(".");
	if (d)
	{
		while ((dir = readdir(d)))
			printf("%s\n", dir->d_name);
		closedir(d);
	}
}

void	ft_readfiles(void)
{
	DIR				*d;
	struct dirent	*dir;
	struct stat		file;

	d = opendir(".");
	if (d)
	{
		while ((dir = readdir(d)))
		{
			stat(dir->d_name, &file);
			if (S_ISREG(file.st_mode))
				printf("%s\n", dir->d_name);
		}
		closedir(d);
	}
}

void	ft_readdir(void)
{
	DIR				*d;
	struct dirent	*dir;
	struct stat		file;

	d = opendir(".");
	if (d)
	{
		while ((dir = readdir(d)))
		{
			stat(dir->d_name, &file);
			if (S_ISDIR(file.st_mode))
			{
				if (strcmp(dir->d_name, "..") && strcmp(dir->d_name, "."))
					printf("%s\n", dir->d_name);
			}
		}
		closedir(d);
	}
}
