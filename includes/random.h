/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 14:10:26 by adelille          #+#    #+#             */
/*   Updated: 2021/02/11 15:25:05 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOM_H
# define RANDOM_H

# include <math.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

# define TRUE 1
# define FALSE 0

# define SEED1 2147483647
# define SEED2 991372845907
# define SEED3 284103856433
# define SEED4 83052976562
# define SEED5 4

# define START 300000000
# define END 900000000

typedef struct				s_map
{
	unsigned long long		mul;
	unsigned long long		inc;
	unsigned long long		mod;
	unsigned long long		period;
}							t_map

#endif
