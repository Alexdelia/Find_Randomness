/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <adelille@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 22:18:42 by user42            #+#    #+#             */
/*   Updated: 2021/02/23 12:50:27 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "random.h"

int			ft_arg(t_arg *arg, int ac, char **av)
{
	int	i;

	arg->lcg.bol = FALSE;
	arg->perf.bol = FALSE;
	arg->debug.bol = FALSE;
	arg->mem.bol = FALSE;
	i = 1;
	while (av[i])
	{
		if (av[i][0] == '-')
		{
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
			if (!(ft_strcmp(av[i], "-perf")))
			{
				arg->perf.bol = TRUE;
				if (av[i + 1] && av[i + 1][0] != '-')
					arg->perf.end = ft_atoi(av[i + 1]);
				else
					arg->perf.end = PERF;
			}
			if (!(ft_strcmp(av[i], "-debug")))
				arg->debug.bol = TRUE;
			if (!(ft_strcmp(av[i], "-rusage")) || !(ft_strcmp(av[i], "-mem")))
				arg->mem.bol = TRUE;
		}
		i++;
	}
	if (ft_check(*arg, ac, av) == FALSE)
		return (FALSE);
	return (TRUE);
}
