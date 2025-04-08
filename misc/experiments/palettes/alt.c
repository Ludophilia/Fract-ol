/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alt.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 17:16:10 by jegerman          #+#    #+#             */
/*   Updated: 2025/04/08 17:24:06 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 04/04 - Is that a new interpolation necessary? 
//		1 / Yeah, it helps add things more, but maybe I can remove it to test...
//		2 / Or maybe I should remove the first interpolation used to create the
//		enriched palette in the first place

// 05/04 - Let's improve that coloring logic

// - iter goes from 0 to MAX_ITER (0 to 100)
// - 6 colors in my gradient; index from 0 to 5
// - The gradient should match the whole iteration range
//		- 0 iter means a color between colors[0] and colors[1]. 
//			- 0 = 5 * (0/100) ; (int)(colors_nb * (iter/iter_max))
//			- 1 = 5 * (0/100) + 1 ; (int)(colors_nb * (iter/iter_max)) + 1
//			- coeff = iter - (int)iter; so 0 in that case

//		- 99 iter means a color between colors[4] and colors[5]. 
//			- 4 = 5 * (99/100) ; (int)(colors_nb * (iter/iter_max))
//			- 5 = 5 * (99/100) + 1 ; (int)(colors_nb * (iter/iter_max)) + 1
//			- coeff = iter - (int)iter; so 0 in that case

//		- 100 iter means color[5] or color[color_len]

unsigned int get_color(double t)
{
	// int r = (int)(127.5 * (1 + sin(6.2831 * t + 0)));       // Red wave
	// int g = (int)(127.5 * (1 + sin(6.2831 * t + 2.0944)));   // Green wave (2π/3 phase)
	// int b = (int)(127.5 * (1 + sin(6.2831 * t + 4.1888)));   // Blue wave (4π/3 phase)

	// int r = (int)(127.5 * (1 + sin(6.2831 * t + 4.1888)));       // Red wave
	// int g = (int)(127.5 * (1 + sin(6.2831 * t + 0)));   // Green wave (2π/3 phase)
	// int b = (int)(127.5 * (1 + sin(6.2831 * t + 2.0944)));   // Blue wave (4π/3 phase)

	int r = (int)(127.5 * (1 + sin(6.2831 * t + 2.0944)));       // Red wave
	int g = (int)(127.5 * (1 + sin(6.2831 * t + 4.1888)));   // Green wave (2π/3 phase)
	int b = (int)(127.5 * (1 + sin(6.2831 * t + 0)));   // Blue wave (4π/3 phase)

	return ((r << 16) | ((g << 8) ) | (b));
}
