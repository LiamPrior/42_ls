/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprior <lprior@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 18:37:47 by lprior            #+#    #+#             */
/*   Updated: 2018/04/28 22:01:00 by lprior           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_info  *ft_ls(t_env *all, char *path, t_info *info)//okay so i need to lstat in my create node function
{
    DIR             *type;
    struct dirent   *file;

    if ((type = opendir(path)) == NULL)
        ft_error(1, path);
    while ((file = readdir(type)))
    {
        all->type = ft_strdup(path);
        all->type = ft_strjoin2(path, file->d_name);
        printf("path = [%s]\n",all->type);
        if ((ft_strncmp(file->d_name, ".", 1) == 0 && all->options.a == true)
            || (ft_strncmp(file->d_name, ".", 1) != 0))
                info = ft_create_node(all, info, all->type, file);
        else
            continue;
        if (S_ISDIR(info->data->st_mode) && all->options.R == true 
            && ft_strncmp(file->d_name, ".", 1) != 0)
                info->sub = ft_ls(all, all->type, info->sub);
        else if (info)
            info->sub = NULL;
    }
    closedir(type);
    while (info && info->prev != NULL)
        info = info->prev;
    return (info);
}

void    ft_parse_paths(int argc, char **argv, t_env *all)
{
    all->i = 0;
    if (argv[all->x] && argv[all->x][all->i] != '-')
    {
        all->paths[all->px] = ft_strnew(ft_strlen(argv[all->x]) + 2);
        while (all->i < ft_strlen(argv[all->x]))
        {
            all->paths[all->px][all->i] = argv[all->x][all->i];
            all->i++;
        }
        all->paths[all->px][all->i] = '/';
        all->paths[all->px][all->i + 1] = '\0';
    }
    else
        return ;
    all->x = all->x + 1;
    all->px = all->px + 1;
    ft_parse_paths(argc, argv, all);
}

void     ft_toggle_options(int argc, char **argv, t_env *all)
{
    all->i = 0;
    all->x = all->x + 1;
    if (argv[all->x] && argv[all->x][all->i] == '-' && argc > all->x)
    {
        all->i++;
        while (argv[all->x][all->i])
        {
            all->options.R = argv[all->x][all->i] == 'R' ? true : all->options.R;
            all->options.a = argv[all->x][all->i] == 'a' ? true : all->options.a;
            all->options.t = argv[all->x][all->i] == 't' ? true : all->options.t;
            all->options.l = argv[all->x][all->i] == 'l' ? true : all->options.l;
            all->options.r = argv[all->x][all->i] == 'r' ? true : all->options.r;
            if (argv[all->x][all->i] != 'R' && argv[all->x][all->i] != 'a' &&
                argv[all->x][all->i] != 't' && argv[all->x][all->i] != 'l' &&
                argv[all->x][all->i] != 'r' && argv[all->x][all->i])
                    ft_error(0, NULL);
            all->i++;
        }
    }
    else
        return ;
    ft_toggle_options(argc, argv, all);
}


t_info    *print_ls(t_env *all, t_info *head)
{
    t_info *ptr;

    ptr = head;
    if (ptr)
        head = ft_merge_sort(all, ptr);
    while (ptr != NULL)
    {
        if (ptr->sub)
            ptr->sub = print_ls(all, ptr->sub);
        ptr = ptr->next;
    }
    return (head);

}

int     main(int argc, char **argv)
{
    t_env all;

    ft_init(&all, argc);
    ft_toggle_options(argc, argv, &all);
    ft_parse_paths(argc, argv, &all);
    all.px = 0;
    if (!(all.paths[all.px]))
    {
        all.paths[all.px] = ft_strnew(3);
        all.paths[all.px][all.px] = '.';
        all.paths[all.px][all.px + 1] = '/';
        all.paths[all.px][all.px + 2] = '\0';//can remove
    }
    all.info = ft_ls(&all, all.paths[all.px], all.info);
    all.info = print_ls(&all, all.info);
    // all.info = ft_merge_sort(&all, all.info);
    printf("?????????????????????STOP????????????????????\n");
    ft_display(&all, all.info);
    // printf("\n\nHERE\n\n");
    // ft_display();
    return (0);
}
// fuck1
// fuck2
// fuck3
// fuck4
// gang1
// gang2
// gang3
// gang4
// gang5

// mergetest//gang1/:
// fuck1.2
// fuck1.3
// gang1.1

// mergetest//gang1/gang1.1/:
// fuck1.1b
// fuck1.1c

// mergetest//gang2/:
// fuck2.2
// fuck2.3
// gang2.1

// mergetest//gang2/gang2.1/:
// fuck2.1c

// mergetest//gang3/:
// fuck3.1
// fuck3.2
// fuck3.3
// gang3.1

// mergetest//gang3/gang3.1/:
// fuck3.1a
// fuck3.1b
// fuck3.1c

// mergetest//gang4/:
// fuck4.3
// gang4.1

// mergetest//gang4/gang4.1/:
// fuck4.1a
// fuck4.1b
// fuck4.1c

// mergetest//gang5/:
// fuck5.1
// fuck5.2
// fuck5.3
// gang5.1

// mergetest//gang5/gang5.1/:
// fuck5.1a
// fuck5.1b
// fuck5.1c

////////////////////////////////myn^^^^^

// fuck1
// fuck2
// fuck3
// fuck4
// gang1
// gang2
// gang3
// gang4
// gang5

// mergetest/gang1:
// fuck1.1
// fuck1.2
// fuck1.3
// gang1.1

// mergetest/gang1/gang1.1:
// fuck1.1a
// fuck1.1b
// fuck1.1c

// mergetest/gang2:
// fuck2.1
// fuck2.2
// fuck2.3
// gang2.1

// mergetest/gang2/gang2.1:
// fuck2.1a
// fuck2.1b
// fuck2.1c

// mergetest/gang3:
// fuck3.1
// fuck3.2
// fuck3.3
// gang3.1

// mergetest/gang3/gang3.1:
// fuck3.1a
// fuck3.1b
// fuck3.1c

// mergetest/gang4:
// fuck4.1
// fuck4.2
// fuck4.3
// gang4.1

// mergetest/gang4/gang4.1:
// fuck4.1a
// fuck4.1b
// fuck4.1c

// mergetest/gang5:
// fuck5.1
// fuck5.2
// fuck5.3
// gang5.1

// mergetest/gang5/gang5.1:
// fuck5.1a
// fuck5.1b
// fuck5.1c