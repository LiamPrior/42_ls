/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprior <lprior@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 18:38:34 by lprior            #+#    #+#             */
/*   Updated: 2018/04/24 21:16:27 by lprior           ###   ########.fr       */
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
# include <unistd.h>
# include <grp.h>
# include <pwd.h>
# include <stdbool.h>

typedef struct  s_options
{
    bool        R;
    bool        a;
    bool        t;
    bool        l;
    bool        r;
}               t_options;

typedef struct  s_info
{
    char        *name;
    char        *path;
    struct      s_info      *next;
    struct      s_info      *prev;
    struct      s_info      *sub;
}               t_info;

typedef struct  s_env
{
    t_info      *info;//may need to make this a 2d well see
    t_options   options;
    char        **paths;
    char        *type;
    int         px;
    int         x;
    int         i;
}               t_env;

void    ft_toggle_options(int argc, char **argv, t_env *all);
void    ft_error(int i, char *str);
void    ft_init(t_env *all, int argc);
void    ft_parse_paths(int argc, char **argv, t_env *all);
t_info  *ft_ls(t_env *all, char *path, t_info *info);
t_info  *ft_create_node(t_info *info, char *path, struct dirent *file);
DIR     *ft_type(t_env *all, DIR *type, char *path);
t_info *ft_merge_sort(t_env *all, t_info *head);
t_info *ft_merge_links(t_env *all, t_info *head, t_info *second);
t_info *ft_split(t_info *head);
void    ft_display(t_env *all, t_info *head);

#endif