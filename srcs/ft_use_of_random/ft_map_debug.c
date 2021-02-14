/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_debug.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <adelille@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 19:12:23 by user42            #+#    #+#             */
/*   Updated: 2021/02/14 23:40:59 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "random.h"

void	ft_map_debug(t_map map, t_arg arg)
{
	unsigned long long	i;
	unsigned long long	seed;

	if (arg.debug.start)
		seed = arg.debug.start;
	else
		seed = SEEDA;
	i = 0;
	printf("Original seed: %llu\n", seed);
	while (i <= (map.period + 3))
	{
		seed = ft_lcg_empty(map, seed);
		if (seed > SEEDA)
			ft_putstr_fd("\nBe aware that this seed is over INT_MAX\n", 1);
		ft_putstr_fd(ft_itoa(seed), 1);
		ft_putstr_fd(",\t\t", 1);
		i++;
		if (i % 5 == 0)
			ft_putstr_fd("\n", 1);
	}
	printf("\n\nEnd, %llu random number generated\n", i);
}
