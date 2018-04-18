/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liamprior <liamprior@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 00:01:04 by lprior            #+#    #+#             */
/*   Updated: 2018/03/11 20:07:02 by liamprior        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include <stdint.h>
# include <stdbool.h>
# include <wchar.h>
# include "../libft.h"
# include <stdio.h>

# define NORMAL        "\x1B[0m"
# define RED        "\x1B[31m"
# define GREEN        "\x1B[32m"
# define YELLOW        "\x1B[33m"
# define BLUE        "\x1B[34m"
# define MAGNETA    "\x1B[35m"
# define CYAN        "\x1B[36m"

# define ULL	unsigned long long int
# define LL		long long int
# define IFWP	tools->width == -101 && tools->prec == -2
# define IFPW	tools->width == -101 && tools->prec == -100

typedef struct	s_flags
{
	int			positive;
	int			negative;
	int			zeros;
	int			space;
	int			hashtag;
	char		brand;
	int			retrn;
	int			width;
	int			prec;
	int			arg;
	int			len;
}				t_flags;

int				ft_printf(const char *format, ...);
int				ft_parse_format_print(char *format, va_list ap, t_flags *tools);
void			ft_build_tools(t_flags *tools);
void			ft_print(int start, int end, char *format, int *res);
void			ft_parse_flags(char *form, int *i, t_flags *tools, va_list ap);
void			ft_check_fwap(char *format, int *i, t_flags *tools);
void			ft_check_args(char *format, int *i, t_flags *tools);
void			ft_check_width(char *format, int *i, t_flags *tools);
void			ft_check_prec(char *format, int *i, t_flags *tools);
void			ft_check_flags(char *format, int *i, t_flags *tools);
void			ft_parse_flags2(char *format, int *i, t_flags *tools);
void			ft_check_type(char form, t_flags *tools, va_list ap);
void			ft_print_string(t_flags *tools, va_list ap);
void			ft_print_wchar(t_flags *tools, va_list ap);
void			ft_print_wchar_str(t_flags *tools, va_list ap);
void			ft_print_pointer(t_flags *tools, va_list ap);
void			ft_print_int(t_flags *tools, va_list ap);
void			ft_print_unsigned_int(t_flags *tools, va_list ap);
void			ft_print_char(t_flags *tools, va_list ap);
void			ft_print_percent(t_flags *tools);
void			ft_check_type2(char format, t_flags *tools, va_list ap);
void			ft_parse_char_tool(t_flags *tools);
void			ft_parse_int_tools(t_flags *tools, long int number);
int				ft_check_signed_int(t_flags *tools, va_list ap);
LL				ft_sort_signed_args(t_flags *tools, va_list ap);
ULL				ft_sort_unsigned_args(t_flags *tools, va_list ap);
ULL				ft_check_unsigned_int(t_flags *tools, va_list ap);
void			ft_print_zeros(t_flags *tools);
void			ft_print_int2(t_flags *tools, long long int number, int dis);
void			ft_print_prec(t_flags *tools);
void			ft_parse_unsigned_int_tools(t_flags *tools, ULL num);
char			*ft_otoa(unsigned long int number);
char			*ft_htoa(unsigned long int number, t_flags *tools);
char			*ft_ullitoa(unsigned long long int number);
char			*ft_ptoa(unsigned long int number, t_flags *tools);
void			ft_pui2(t_flags *tools, ULL num, int dis, char *dt);
void			ft_print_address(t_flags *tools, unsigned long long int number);
char			*ft_uitoa(unsigned int nbr);
char			*ft_unitoa(wint_t letter);
int				ft_print_color(char *str);
void			ft_print_binary(va_list ap);

#endif
