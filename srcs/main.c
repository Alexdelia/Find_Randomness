/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 15:05:06 by adelille          #+#    #+#             */
/*   Updated: 2021/02/23 13:00:18 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "random.h"

int		main(int ac, char **av)
{
	t_arg			arg;
	struct rusage	mem_use;

	if (ft_arg(&arg, ac, av) == FALSE)
		return (0);
	if (arg.mem.bol == TRUE)
	{
		if ((getrusage(RUSAGE_CHILDREN, &mem_use)) == -1)
			return (-1);
		printf("Memory used: %ld\n", mem_use.ru_maxrss);
	}
	if (arg.perf.bol == TRUE)
		ft_map_perf(arg);
	else if (arg.lcg.bol == TRUE)
		ft_map(arg);
	if (arg.mem.bol == TRUE)
	{
		if ((getrusage(-1, &mem_use)) == -1)
			return (-1);
		printf("Memory used: %ld\n", mem_use.ru_maxrss);
	}
	return (0);
}

// plan to do a very improved version of the LCG finder, and add a visualisation of point found.
