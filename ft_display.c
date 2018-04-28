/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprior <lprior@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 21:58:57 by lprior            #+#    #+#             */
/*   Updated: 2018/04/27 18:35:44 by lprior           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
//okay so i can print all the things 


void    ft_display2(t_env *all, t_info *head)
{
    t_info *ptr;

    ptr = head;
    // if (all->options.r == false && all->options.R == false)
        while (ptr)
        {
            ft_printf("%s%s%s\n", ptr->color, ptr->name, NORMAL);
            if (ptr && all->options.R == true && ptr->sub != NULL)
                ft_display(all, ptr->sub);
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
        // printf("asdl;fjkads;lfkjasd;lfkj %p\n", ptr);
        // while (ptr && all->options.R == true)//what i should do i smake a fucntion that will print all my info in that struct
        // {
        //     if (S_ISDIR(ptr->data->st_mode))
        //     {
        //         printf("\n%s:\n", ptr->path);
        //         ft_myprinter(ptr->sub);
        //     }
        //     printf("name = %s\n", ptr->name);
        //     // printf("in here going to next node %s\n", ptr->next->name);
        //     ptr = ptr->next;
        // }

}

            // if (ptr && all->options.R == true && ptr->sub != NULL)
            //     ft_display(all, ptr->sub);