/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <adelille@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 22:18:42 by user42            #+#    #+#             */
/*   Updated: 2021/02/28 19:14:23 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "random.h"

static void	ft_binary_arg(t_arg *arg, char *str)
{
	int		i;
	char	**split;
	int		count;
	int		wlen;

	i = 0;
	count = 0;
	wlen = 0;
	while (str[i])
	{
		if (str[i] == '.')
		{
			if (wlen < 0)
			{
				ft_ps("Wrong input: You type two \".\" consecutevely after -s-binary\n");
				return ;
			}
			wlen = 0;
			count++;
		}
		wlen++;
		i++;
	}
	if (count != 3)
	{
		ft_ps("Wrong input: You type less than 4 value separeted by \".\" after -s-binary\n");
	}
	split = ft_split(str, '.');
	arg->bin.map.seed = ft_atoi(split[0]);
	arg->bin.map.mul = ft_atoi(split[1]);
	arg->bin.map.inc = ft_atoi(split[2]);
	arg->bin.map.mod = ft_atoi(split[3]);
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

int			ft_arg(t_arg *arg, int ac, char **av)
{
	int	i;

	arg->lcg.bol = FALSE;
	arg->perf.bol = FALSE;
	arg->debug.bol = FALSE;
	arg->mem.bol = FALSE;
	arg->bin.bol = FALSE;
	i = 1;
	while (av[i])
	{
		// -- '-' type --
		if (av[i][0] == '-')
		{
			// -- LCG --
			if (!(ft_strcmp(av[i], "-LCG") || !(ft_strcmp(av[i], "-lcg"))))
			{
				arg->lcg.bol = TRUE;
				if (av[i + 1] && av[i + 2]
						&& av[i + 1][0] != '-'
						&& av[i + 2][0] != '-')
				{
					arg->lcg.start = ft_atoi(av[i + 1]);
					arg->lcg.end = ft_atoi(av[i + 2]);
				}
				else
				{
					arg->lcg.start = START;
					arg->lcg.end = END;
				}
			}
			// -- perf --
			if (!(ft_strcmp(av[i], "-perf")))
			{
				arg->perf.bol = TRUE;
				if (av[i + 1] && av[i + 1][0] != '-')
					arg->perf.end = ft_atoi(av[i + 1]);
				else
					arg->perf.end = PERF;
			}
			// -- debug --
			if (!(ft_strcmp(av[i], "-debug")))
				arg->debug.bol = TRUE;
			// -- mem --
			if (!(ft_strcmp(av[i], "-rusage")) || !(ft_strcmp(av[i], "-mem")))
				arg->mem.bol = TRUE;
			// -- show --
			if (av[i][1] == 's')
			{
				// -- binary --
				if (!(ft_strcmp(av[i], "-s-binary")))
				{
					arg->bin.bol = TRUE;
					if (av[i + 1] && av[i + 1][0] != '-')
						ft_binary_arg(*&arg, av[i + 1]);
				}
			}
		}
		i++;
	}
	if (ft_check(*arg, ac, av) == FALSE)
		return (FALSE);
	return (TRUE);
}
