/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprior <lprior@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 18:38:34 by lprior            #+#    #+#             */
/*   Updated: 2018/05/06 21:26:36 by lprior           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <dirent.h>
# include <stdint.h>
# include <stdlib.h>
# include <stdio.h>
# include "./libft/libft.h"
# include <errno.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/xattr.h>
# include <unistd.h>
# include <grp.h>
# include <pwd.h>
# include <stdbool.h>
# include <time.h>

# define IFa all->options.a
# define IFR all->options.R
# define IFr all->options.r
# define IFl all->options.l
# define IFt all->options.t
# define USR struct passwd *usr
# define DATA info->data->st_mode
# define PATH all->paths[all->px]
# define HEDDATA head->data->st_mode
# define ARGLETTER argv[all->x][all->i]
# define ISDOT strcmp(file->d_name, ".")
# define DOTCMP ft_strncmp(file->d_name, "..", 3)
# define STRJOIN2 ft_strjoin2(path, file->d_name)
# define STRNEW ft_strnew(ft_strlen(head->path) + 1)
# define NOTDOT (ft_strncmp(file->d_name, ".", 1) != 0)
# define DRPERMS S_ISDIR(DATA) && IFR && (S_IRUSR & DATA) && PERMS
# define PERMS (S_IRGRP & DATA) && (S_IROTH & DATA) && (S_IWUSR & DATA)

typedef	struct			s_options
{
	bool				R;
	bool				a;
	bool				t;
	bool				l;
	bool				r;
}						t_options;

typedef	struct			s_info
{
	char				*name;
	char				*path;
	char				*color;
	struct	stat		*data;
	struct	s_info		*next;
	struct	s_info		*prev;
	struct	s_info		*sub;
	struct	timespec	time;
}						t_info;

typedef	struct			s_env
{
	t_info				*info;
	t_info				*args;
	t_info				*dargs;
	t_options			options;
	char				**paths;
	char				*type;
	char				*temp;
	bool				run;
	bool				tot;
	bool				run2;
	int					total;
	int					px;
	int					x;
	int					i;
}						t_env;

t_info	*ft_split(t_info *head);
void	ft_free_lists(t_env *all);
void	ft_make_files(t_env *all);
void	ft_check_paths(t_env *all);
t_info	*ft_error(int i, char *str);
void	ft_print_time(t_info *head);
void	ft_init(t_env *all, int argc);
void	ft_init_2d(t_env *all, int argc);
void	ft_printer(t_env *all, t_info *head);
void	ft_operate(t_env *all, t_info *temp);
void	ft_display(t_env *all, t_info *head);
t_info	*ft_goto_end(t_env *all, t_info *ptr);
void	ft_get_total(t_env *all, t_info *head);
void	ft_displaytwo(t_env *all, t_info *head);
void	ft_get_perms(t_info *haed, char *perms);
t_info	*ft_free_info(t_env *all, t_info *head);
void	ft_print_path(t_env *all, t_info *head);
void	ft_print_long(t_env *all, t_info *head);
t_info	*ft_merge_sort(t_env *all, t_info *head);
t_info	*ft_init_merge(t_env *all, t_info *head);
int		ft_get_time(t_info *first, t_info *second);
DIR		*ft_type(t_env *all, DIR *type, char *path);
t_info	*ft_ls(t_env *all, char *path, t_info *info);
void	ft_recursive_print(t_env *all, t_info *head);
void	ft_check_file(t_env *all, struct stat *info);
void	ft_stat_color(struct stat *data, t_info *head);
void	ft_parse_paths(int argc, char **argv, t_env *all);
void	ft_toggle_options(int argc, char **argv, t_env *all);
t_info	*ft_create_node(t_info *info, char *path, char *name);
t_info	*ft_time_sort(t_env *all, t_info *first, t_info *second);
t_info	*ft_merge_links(t_env *all, t_info *head, t_info *second);
void	ft_print_info(char *perms, t_info *head, USR, struct group *grp);

#endif