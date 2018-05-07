/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprior <lprior@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 18:37:47 by lprior            #+#    #+#             */
/*   Updated: 2018/05/06 19:09:58 by lprior           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_info		*ft_ls(t_env *all, char *path, t_info *info)
{
	DIR				*type;
	struct	dirent	*file;
	char			*alltype;

	if ((type = opendir(path)) == NULL)
		return (ft_error(2, path));
	while ((file = readdir(type)) && (alltype = STRJOIN2))
	{
		if ((ft_strncmp(file->d_name, ".", 1) == 0 && IFa == true) || NOTDOT)
			info = ft_create_node(info, alltype, file->d_name);
		else
		{
			free(alltype);
			continue;
		}
		if (DRPERMS && ((!IFa && NOTDOT) || (IFa && DOTCMP && ISDOT)))
			info->sub = ft_ls(all, alltype, info->sub);
		else if (info)
			info->sub = NULL;
		free(alltype);
	}
	closedir(type);
	while (info && info->prev != NULL)
		info = info->prev;
	return (info);
}

void		ft_parse_paths(int argc, char **argv, t_env *all)
{
	all->i = 0;
	if (argv[all->x] && argv[all->x][all->i] != '-')
	{
		all->paths[all->px] = ft_strnew(ft_strlen(argv[all->x]) + 1);
		while ((size_t)all->i < ft_strlen(argv[all->x]))
		{
			all->paths[all->px][all->i] = argv[all->x][all->i];
			all->i++;
		}
		all->paths[all->px][all->i] = '\0';
	}
	else
		return ;
	all->x = all->x + 1;
	all->px = all->px + 1;
	ft_parse_paths(argc, argv, all);
}

void		ft_toggle_options(int argc, char **argv, t_env *all)
{
	all->i = 0;
	all->x = all->x + 1;
	if (argv[all->x] && argv[all->x][all->i] == '-' && argc > all->x)
	{
		all->i++;
		if ((argv[all->x][all->i - 1]) && !argv[all->x][all->i])
			ft_error(0, &argv[all->x][0]);
		while (argv[all->x][all->i])
		{
			IFR = ARGLETTER == 'R' ? true : IFR;
			IFa = ARGLETTER == 'a' ? true : IFa;
			IFt = ARGLETTER == 't' ? true : IFt;
			IFl = ARGLETTER == 'l' ? true : IFl;
			IFr = ARGLETTER == 'r' ? true : IFr;
			if (ARGLETTER != 'R' && ARGLETTER != 'a' &&
				ARGLETTER != 't' && ARGLETTER != 'l' &&
				ARGLETTER != 'r' && ARGLETTER)
					ft_error(0, &argv[all->x][1]);
			all->i++;
		}
	}
	else
		return ;
	ft_toggle_options(argc, argv, all);
}

void		ft_check_paths(t_env *all)
{
	struct stat     *info;

	all->px = 0;
	if (!(all->paths[all->px]))
	{
		all->paths[all->px] = ft_strnew(2);
		all->paths[all->px][all->px] = '.';
		all->paths[all->px + 1] = NULL;
	}
	while (all->paths[all->px])
	{
		info = (struct stat *)malloc(sizeof(struct stat));
		ft_check_file(all, info);
		free(info);
		all->px++;
	}
	while (all->args && all->args->prev != NULL)
		all->args = all->args->prev;
	while (all->dargs && all->dargs->prev != NULL)
		all->dargs = all->dargs->prev;
	all->dargs = all->dargs ? ft_init_merge(all, all->dargs) : all->dargs;
	ft_make_files(all);
	all->x = 0;
	all->i = 0;
}

int			main(int argc, char **argv)
{
	t_env all;
	t_info *temp;

	ft_init(&all, argc);
	ft_toggle_options(argc, argv, &all);
	ft_parse_paths(argc, argv, &all);
	ft_check_paths(&all);
	if (all.options.r)
		all.dargs = ft_goto_end(&all, all.dargs);
	temp = all.dargs;
	while (temp)
	{
		if (!(all.info = ft_ls(&all, temp->name, all.info)))
		{
			temp = all.options.r ? temp->prev : temp->next;
			continue ;
		}
		ft_operate(&all, temp);
		temp = all.options.r ? temp->prev : temp->next;
	}
	// ft_free_lists(&all);
	return (0);
}
