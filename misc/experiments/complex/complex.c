/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 18:08:14 by jgermany          #+#    #+#             */
/*   Updated: 2023/07/05 20:22:03 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <complex.h>
#include <stdbool.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	double complex	z1;
	int			c11;
	// complex 	z1;
	// float complex 	z1; // if float, use the float specific functions 
	// which are built for double by default. Example: crealf for creal.
	// imaginary	z2;

	if (argc <= 1)
	{
		dprintf(2, "usage: ./complex (0 | 1)\n");
		return (1);
	}
	c11 = atoi(argv[1]);
	printf("[%s] Simple example:\n", c11? "C11" : "C99");
	z1 = c11 ? (CMPLX(0, 1) * CMPLX(0, 1)) : (I * I);
	printf("\tI² = %.lf + %.lfi\n", creal(z1), cimag(z1));
	printf("[%s] Power:\n", c11? "C11" : "C99");
	z1 = c11 ? cpow(CMPLX(0, 1), 4) : cpow((0 + I), 4);
	printf("\tI**4 = %.lf + %.lfi\n", creal(z1), cimag(z1)); // 1
	printf("[%s] Conjugate :\n", c11? "C11" : "C99");
	z1 = c11 ? conj(CMPLX(1, 1)) : conj(1 + I);
	printf("\tconj(1 + i) = %.lf + %.lfi\n", creal(z1), cimag(z1));
	printf("[%s] Square root :\n", c11? "C11" : "C99");
	z1 = c11 ? csqrt(CMPLX(-1, 0)) : csqrt(-1);
	printf("\tsqrt(-1) = %.lf + %.lfi\n", creal(z1), cimag(z1));
	printf("[%s] Addition:\n", c11? "C11" : "C99");
	z1 = c11 ? (CMPLX(2, 1) + CMPLX(-3, -3)) : (2 + I) + (-3 - 3 * I);
	printf("\t(2 + I) + (-3 - 3i) = %.lf + %.lfI\n", creal(z1), cimag(z1)); // -1 -2I
	printf("[%s] Substraction:\n", c11? "C11" : "C99");
	z1 = c11 ? (CMPLX(2, 1) - CMPLX(-3, -3)) : (2 + I) - (-3 - 3 * I);
	printf("\t(2 + I) - (-3 - 3i) = %.lf + %.lfI\n", creal(z1), cimag(z1)); // 5 + 4I
	printf("[%s] Multiplication:\n", c11? "C11" : "C99");
	z1 = c11 ? (CMPLX(2, 1) * CMPLX(-3, -3)) : (2 + I) * (-3 - 3 * I);
	printf("\t(2 + I) * (-3 - 3i) = %.lf + %.lfI\n", creal(z1), cimag(z1)); // -3 -9i
	printf("[%s] Division:\n", c11? "C11" : "C99");
	z1 = c11 ? (CMPLX(2, 1) / CMPLX(-3, -3)) : (2 + I) / (-3 - 3 * I);
	printf("\t(2 + I) / (-3 - 3i) = %.2lf + %.2lfI\n", creal(z1), cimag(z1)); // -0.5 + (1/6)i
	return (0);
}
