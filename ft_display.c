/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprior <lprior@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 21:58:57 by lprior            #+#    #+#             */
/*   Updated: 2018/04/28 20:59:09 by lprior           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
//okay so i can print all the things 


void    ft_displaytwo(t_env *all, t_info *head)
{
    t_info *ptr;

    ptr = head;
    // printf("HERE\n");
    // if (all->options.r == false && all->options.R == false)
        while (ptr)
        {
            ft_printf("%s%s%s\n", ptr->color, ptr->name, NORMAL);
            if (ptr && all->options.R == true && ptr->sub != NULL)
                ft_displaytwo(all, ptr->sub);
            ptr = ptr->next;
        } 
}

void printer(t_info *head)
{
    t_info *ptr;

    ptr = head;
    while (ptr)
    {
        ft_printf("%s%s%s\n", ptr->color, ptr->name, NORMAL);
        ptr = ptr->next;
    }
}

void ft_myprinter(t_env *all, t_info *head)
{
    t_info *ptr;

    ptr = head;
    printer(ptr);
    while (ptr && all->options.R == true)
    {
        if (ptr->sub != NULL)
        {
            printf("\n%s:\n", ptr->path);
            ft_myprinter(all, ptr->sub);
        }
        ptr = ptr->next;
    }
}

void    ft_display(t_env *all, t_info *head)
{
    t_info *ptr;

    ptr = head;
    // if (all->options.r == false && all->options.R == false)
        while (ptr && all->options.R == false)//okay lets just get it to print normal
        {
            ft_printf("fitst if shouldnt be here%s%s%s\n", ptr->color, ptr->name, NORMAL);
            ptr = ptr->next;
        }
        ptr = head;
        ft_myprinter(all, ptr);//may need to add if statement for -R
}

            // if (ptr && all->options.R == true && ptr->sub != NULL)
            //     ft_display(all, ptr->sub);