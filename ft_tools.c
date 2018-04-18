/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprior <lprior@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 13:29:55 by psprawka          #+#    #+#             */
/*   Updated: 2018/04/17 21:02:18 by lprior           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void    ft_error(int i)
{
    if (i == 0)
        ft_printf("ERROR: USAGE ./ft_ls (-R)(-a)(-t)(-l)(-r)!\n");
    else if (i == 1)
        ft_printf("Breh why do you do this?!?!?!\n");
    exit(0);
}

void    ft_init(t_env *all, int argc)
{
    all->options.R = false;
    all->options.a = false;
    all->options.t = false;
    all->options.l = false;
    all->options.r = false;
    all->info = (t_info *)malloc(sizeof(t_info));
    all->info->sub = NULL;
    all->info->next = NULL;
    all->info->prev = NULL;
    all->info->path = NULL;
    all->paths = (char **)malloc(sizeof(char *) * argc);
    all->i = 0;
    all->x = 0;
    all->px = 0;
}

void    ft_create_sub(t_env *all)
{

}

void    ft_create_list(t_env *all, DIR *directory)
{

}