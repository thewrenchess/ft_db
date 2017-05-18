/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_db.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yherrera <yherrera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 16:45:23 by dhuang            #+#    #+#             */
/*   Updated: 2017/05/04 20:15:01 by yherrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DB_H
# define FT_DB_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <strings.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <dirent.h>
# include <fcntl.h>
# include <errno.h>
# include "../libft/includes/libft.h"

# define CMAX 40
# define RMAX 100
# define LINEMAX 200
# define DCOLMAX 80
# define DLINEMAX CMAX * DCOLMAX + 10

typedef struct	s_entry
{
	int			i;
	char		c;
	char		str[LINEMAX];
}				t_entry;

typedef struct	s_types
{
	char		*type;
}				t_types;

typedef struct	s_cinfo
{
	char		n[LINEMAX];
	char		t[20];
}				t_cinfo;

typedef struct	s_tab
{
	char		*name;
	int			c;
	t_cinfo		col[CMAX];
	int			r;
	t_entry		e[RMAX][CMAX];

}				t_tab;

typedef struct	s_int
{
	int		w;
	int		n;
	int		i;
	int		j;
}				t_int;

void			ft_getstr(char *str);
void			ft_getint(int *n);
void			ft_getchar(char *c);
void			ft_exit(void);
void			ft_create(void);
void			ft_destroy(void);
void			comparedestroyinput(char *conf, char *str);
void			comparemaininput(char *str);
void			ft_readdir(void);
void			ft_readfiles(void);
void			ft_readall(void);
void			ft_exit(void);
void			ft_destroytable(void);
void			tablesetupinput(FILE *fp, int col);
void			ft_newfile(void);
void			ft_openfile(void);
void			compareopeninput(char *str);
void			ft_open(void);
void			comparecloseinput(FILE *fp, char *name, t_tab *tab);
void			ft_table(FILE *fp, char *name);
void			ft_parse(FILE *fp, t_tab *tab);
void			ft_update(FILE *fp, t_tab *tab);
void			spacetounderscore(char *str);
void			ft_display(t_tab tab);
void			ft_sort(t_tab *tab);
void			ft_intsort(t_tab *tab, int c, char order);
void			ft_charsort(t_tab *tab, int c, char order);
void			ft_strsort(t_tab *tab, int c, char order);
void			ft_db_swap(t_tab *tab, int a, int b);

#endif
