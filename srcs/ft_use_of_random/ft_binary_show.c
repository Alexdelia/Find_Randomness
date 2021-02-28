/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_binary_show.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 16:43:33 by adelille          #+#    #+#             */
/*   Updated: 2021/02/28 19:43:35 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "random.h"

void	ft_binary_show(t_map map)
{
	int		right;
	int		left;
	int		i;

	ft_ps("\n\t\tStarting binary visualization\n\n");
	ft_ps("\t\t0\t\t\t1\n\n");
	right = 0;
	left = 0;
	i = 101;
	while (--i)
	{
		ft_ps("\r\t\t");
		if (map.seed % 2 == 1)
		{
			right++;
			ft_ps("\t");
			ft_ps("  ---->>\t");
			ft_ps(ft_itoa(right));
		}
		else
		{
			left++;
			ft_ps(ft_itoa(left));
			ft_ps("\t");
			ft_ps("<<----  \t");
		}
		map.seed = dlcg(map.seed, map.mul, map.inc, map.mod);
		usleep(100000);
		ft_ps("\r\t\t\t  ----  ");
		usleep(100000);
	}
	printf("\nDone\n");
}
