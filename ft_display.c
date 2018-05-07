/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprior <lprior@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 21:58:57 by lprior            #+#    #+#             */
/*   Updated: 2018/05/06 20:44:35 by lprior           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_print_path(t_env *all, t_info *head)
{
	t_info	*ptr;
	char	*temp;

	ptr = head;
	temp = ft_strdup(ptr->path);
	if (all->dargs && (all->dargs->next || all->dargs->prev || all->args)
		 && all->run == true )
		while(ptr->path[all->i])
		{
			if (ptr->path[all->i] == '/')
				if (ptr->path[all->i + 1] && ptr->path[all->i + 1] != '/')
				{
					temp[all->i] = '\0';
					ft_printf("%s:\n", temp);
					all->run = false;
				}
			all->i++;
		}
	free(temp);
}

void	ft_get_total(t_env *all, t_info *head)
{
	t_info	*ptr;

	ptr = head;
	while (ptr)
	{
		all->total += ptr->data->st_blocks;
		ptr =  all->options.r ? ptr->prev : ptr->next;
	}
}

void    ft_print_long(t_env *all, t_info *head)
{
	char			*perms;
	struct	group	*grp;
	struct	passwd	*usr;
	char			*link;

	ft_print_path(all, head);
	ft_get_total(all, head);
	if (all->tot == true)
		ft_printf("total %d\n", all->total);
	all->total = 0;
	while (head)
	{
		perms = NULL;
		usr = NULL;
		grp = NULL;
		ft_print_info(perms, head, usr, grp);
		if (S_ISLNK(head->data->st_mode) && (link = STRNEW))
		{
			readlink(head->path, link, 1024);
			ft_printf("%s%s%s -> %s\n", head->color, head->name, NORMAL, link);
		}
		else
			ft_printf("%s%s%s\n", head->color, head->name, NORMAL);
		head = all->options.r == true ? head->prev : head->next;
	}
}

void	ft_recursive_print(t_env *all, t_info *head)
{
	t_info			*ptr;

	ptr = head;
	all->options.l == true ? ft_print_long(all, ptr) : ft_printer(all, ptr);
	while (ptr && all->options.R == true)
	{
		if (S_ISDIR(ptr->data->st_mode) && ft_strcmp(".", ptr->name)
		&& ft_strcmp("..", ptr->name))
		{
			ft_printf("\n%s:\n", ptr->path);
			if (!(S_IRUSR & ptr->data->st_mode))
				printf("ft_ls %s: Permission denied\n", ptr->name);
			if (ptr->sub != NULL)
				ft_recursive_print(all, ptr->sub);
		}
		free(ptr->name);
		ptr = all->options.r == true ? ptr->prev : ptr->next;
	}
}

void	ft_display(t_env *all, t_info *head)
{
	t_info *ptr;

	ptr = head;
	if (all->options.r == true)
		ptr = ft_goto_end(all, ptr);
	if (all->options.R == false && all->options.l == false)
		ft_printer(all, ptr);
	else if (all->options.R == true)
		ft_recursive_print(all, ptr);
	else if (all->options.l == true)
		ft_print_long(all, ptr);
}
