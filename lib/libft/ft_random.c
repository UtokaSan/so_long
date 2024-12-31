/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_random.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboulbes <fboulbes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 04:04:33 by fboulbes          #+#    #+#             */
/*   Updated: 2024/12/31 04:20:11 by fboulbes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Algorithm LCG (Linear Congruential Generator)
unsigned int	ft_random(unsigned int seed, unsigned int min,
unsigned int max)
{
	unsigned int	sd;

	sd = (1664525 * seed + 1013904223) % 4294967296;
	return (min + (sd % (max - min)));
}
