/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_linear_congruential_generator.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <adelille@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 19:22:30 by user42            #+#    #+#             */
/*   Updated: 2021/02/28 16:01:53 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "random.h"

unsigned long long	ft_lcg_empty(t_map map, unsigned long long seed)
{
	return ((map.mul * seed + map.inc) % map.mod);
}
