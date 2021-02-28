/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <adelille@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 22:18:42 by user42            #+#    #+#             */
/*   Updated: 2021/02/28 17:59:54 by adelille         ###   ########.fr       */
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
					if (av[i + 4]
							&& av[i + 1][0] != '-'
							&& av[i + 2][0] != '-'
							&& av[i + 3][0] != '-'
							&& av[i + 4][0] != '-')
					{
						arg->bin.map.seed = ft_atoi(av[i + 1]);
						arg->bin.map.mul = ft_atoi(av[i + 1]);
						arg->bin.map.inc = ft_atoi(av[i + 1]);
						arg->bin.map.mod = ft_atoi(av[i + 1]);
					}
				}
			}
		}
		i++;
	}
	if (ft_check(*arg, ac, av) == FALSE)
		return (FALSE);
	return (TRUE);
}
