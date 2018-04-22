/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprior <lprior@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 18:38:34 by lprior            #+#    #+#             */
/*   Updated: 2018/04/21 21:35:42 by lprior           ###   ########.fr       */
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
    t_info      *info;
    t_options   options;
    char        **paths;
    char        *dir;
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

#endif