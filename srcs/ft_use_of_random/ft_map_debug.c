/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_debug.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <adelille@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 19:12:23 by user42            #+#    #+#             */
/*   Updated: 2021/02/11 19:37:11 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "random.h"

void	ft_map_debug(t_map map, char **av)
{
	unsigned long long	i;
	unsigned long long	seed;

	if (av[4])
		seed = ft_atoi(av[4]);
	else
		seed = SEEDA;
	i = 0;
	ft_putstr_fd("Original seed: ", 1);
	ft_putstr_fd(av[4], 1);
	ft_putstr_fd("\n", 1);
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
