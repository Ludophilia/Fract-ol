/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_gen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 17:16:10 by jegerman          #+#    #+#             */
/*   Updated: 2025/04/10 16:24:36 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 9/04 - Blue is dominating, there is something
// int r = (int)(127.5 * (1 + sin(6.2831 * t + (4  * PI / 3))));
// int g = (int)(127.5 * (1 + sin(6.2831 * t + (4  * PI / 3))));
// int b = (int)(127.5 * (1 + sin(6.2831 * t + 0)));
// 9/04 - Not bad
// int r = (int)(127.5 * (1 + sin(6.2831 * t + (3  * PI / 2))));
// int g = (int)(127.5 * (1 + sin(6.2831 * t + (1  * PI / 1))));
// int b = (int)(127.5 * (1 + sin(6.2831 * t + (2  * PI / 1))));
// 9/04 - BEautiful
// int r = (int)(127.5 * (1 + sin(2 * PI * t + (1  * PI / 1))));
// int g = (int)(127.5 * (1 + sin(2 * PI * t + (3  * PI / 2))));
// int b = (int)(127.5 * (1 + sin(2 * PI * t + (2  * PI / 1))));
unsigned int get_color(double t)
{
	int r = (int)(127.5 * (1 + sin(6.2831 * t + 0)));       // Red wave
	int g = (int)(127.5 * (1 + sin(6.2831 * t + 2.0944)));   // Green wave (2π/3 phase)
	int b = (int)(127.5 * (1 + sin(6.2831 * t + 4.1888)));   // Blue wave (4π/3 phase)

	return ((r << 16) | ((g << 8) ) | (b));
}
