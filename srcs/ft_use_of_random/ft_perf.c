/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <adelille@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 21:14:52 by user42            #+#    #+#             */
/*   Updated: 2021/02/14 23:38:16 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "random.h"

static t_map	ft_best_map_perf(t_map *map)
{
	unsigned long long	mul_end;
	t_map				best;
	int					i;

	mul_end = map->mul + 25;
	map->mul = map->mul - 25;
	best.period = 0;
	best.end = map->end;
	i = 1;
	while (map->mul < mul_end)
	{
		map->inc = 6;
		while (map->inc < 30)
		{
			printf("\rLoop: [%d%%]", (i * 100) / 50);
			map->mod = (map->end - 15);
			while (map->mod < map->end)
			{
				map->period = ((ft_find_period(*map, SEEDA) +
								ft_find_period(*map, SEEDB) +
								ft_find_period(*map, SEEDC) +
								ft_find_period(*map, SEEDD) +
								ft_find_period(*map, SEEDE)) / 5);
				if (map->period > best.period)
				{
					best.period = map->period;
					best.mul = map->mul;
					best.inc = map->inc;
					best.mod = map->mod;
				}
				map->mod++;
			}
			map->inc++;
		}
		map->mul++;
		i++;
	}
	return (best);
}

int				ft_map_perf(t_arg arg)
{
	t_map	map;

	ft_init_map(&map);
	if (arg.perf.bol == TRUE)
		map.end = arg.perf.end + 15;
	map.mul = arg.perf.end * 0.333;
	map.mod = arg.perf.end;
	ft_putstr_fd("\t\tStarting LCG performance\n", 1);
	map = ft_best_map_perf(&map);
	printf("\nThe best LCG found is:\n");
	printf("\n\tMul: %llu\n\tInc: %llu\n\tMod: %llu\n",
				map.mul, map.inc, map.mod);
	printf("For a Score of: %llu%%\n", (map.period + 1) * 100 / map.end);
	if (arg.debug.bol == TRUE)
		ft_map_debug(map, arg);
	return (0);
}
