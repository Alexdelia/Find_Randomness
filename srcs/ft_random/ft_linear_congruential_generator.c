/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_linear_congruential_generator.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <adelille@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 19:22:30 by user42            #+#    #+#             */
/*   Updated: 2021/02/11 19:31:00 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "random.h"

unsigned long long	ft_lcg_empty(t_map map, unsigned long long seed)
{
	seed = (map.mul * seed + map.inc) % map.mod;
	return (seed);
}
