/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <adelille@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 21:14:52 by user42            #+#    #+#             */
/*   Updated: 2021/02/17 23:39:58 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "random.h"

static t_map	ft_best_map_perf(t_map *map)
{
	unsigned long long	mul_end;
	t_map				best;
	int					i;
	int					bol;

	mul_end = map->mul + 25;
	map->mul = map->mul - 25;
	best.period = 0;
	best.end = map->end;
	map->mod = map->end;
	i = 1;
	bol = FALSE;
	while (map->mod > best.period && map->mod > map->end - 100)
	{
		map->inc = 30;
		while (map->inc >= 6)
		{
			map->mul = mul_end - 50;
			while (map->mul < mul_end)
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
				if (i <= 5000)
					printf("\rLoop: [%d%%]", (i * 100) / 5000);
				else if (bol == FALSE)
				{
					printf("\r\t\tFinishing, please wait a few minute.");
					bol = TRUE;
				}
				// Help to erase about 3000 loops in average
				// with:	-perf 500 ~3s73	loops: 14861
				// without:	-perf 500 ~4s31 loops: 20417
				if (map->period == map->mod)
				{
					map->mul = mul_end;
					map->inc = 5;
				}
				map->mul++;
				i++;
			}
			map->inc--;
			i++;
		}
		map->mod--;
		i++;
	}
	printf("\rloop: [Done]");
	printf("\nnumber of loop: %d, for a maximum of 20417 loops", i);
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
	printf("\n\tMul: %llu\n\tInc: %llu\n\tMod: %llu\n\tPeriod: %llu\n\n",
				map.mul, map.inc, map.mod, map.period);
	printf("For a Score of: %llu%%\n", (map.period + 1) * 100 / map.mod);
	if (arg.debug.bol == TRUE)
		ft_map_debug(map, arg);
	return (0);
}
