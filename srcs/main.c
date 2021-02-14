/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 15:05:06 by adelille          #+#    #+#             */
/*   Updated: 2021/02/14 23:13:09 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "random.h"

int		main(int ac, char **av)
{
	t_arg	arg;

	if (ft_arg(&arg, ac, av) == FALSE)
		return (0);
	if (arg.perf.bol == TRUE)
		ft_map_perf(arg);
	else if (arg.lcg.bol == TRUE)
		ft_map(arg);
	return (0);
}

// plan to do a very improved version of the LCG finder, and add a visualisation of point found.
