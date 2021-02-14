/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 15:05:06 by adelille          #+#    #+#             */
/*   Updated: 2021/02/14 21:10:22 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "random.h"

static int	ft_arg(t_arg *arg, int ac, char **av)
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (av[i][0] == '-')
		{
			if (!(ft_strcmp(av[i], "-LCG")))
			{
				arg.lcg.bol = TRUE;
				if (av[i + 1] && av[i + 2])
				{
					arg.lcg.start = ft_atoi(av[i + 1];
					arg.lcg.end = ft_atoi(av[i + 2];
				}
				else
				{
					arg.lcg.start = START
					arg.lcg.end = END
				}
			}
			if (!(ft_strcmp(av[i], "-perf")))
			{
				arg.perf.bol = TRUE;
				if (av[i + 1])
					arg.perf.end = ft_atoi(av[i + 1];
				else
					arg.perf.end = PERF;
			}
		}
	}
	if (ft_check(&arg, ac, av)
		return (FALSE);
	return (TRUE);
}

int		main(int ac, char **av)
{
	t_arg	arg;

	if (ft_arg(&arg, ac, av) == FALSE)
		return (0);
	if (arg.lcg.bol == TRUE)
		ft_map(&arg, ac, av);
	return (0);
}

// plan to do a very improved version of the LCG finder, and add a visualisation of point found.
