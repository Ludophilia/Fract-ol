/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 18:08:14 by jgermany          #+#    #+#             */
/*   Updated: 2025/03/21 17:24:56 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include <complex.h>

void	z_squared(void)
{
	double complex	z1;

	printf("[%s] Simple example:\n", "C99");
	z1 = I * I;
	printf("\tI² = %.lf + %.lfi\n", creal(z1), cimag(z1));
}

void	z_pow(void)
{
	double complex	z1;

	printf("[%s] Power:\n", "C99");
	z1 = cpow((0 + I), 4);
	printf("\tI**4 = %.lf + %.lfi\n", creal(z1), cimag(z1)); // 1
}

void	z_conj(void)
{
	double complex	z1;

	printf("[%s] Conjugate :\n", "C99");
	z1 = conj(1 + I);
	printf("\tconj(1 + i) = %.lf + %.lfi\n", creal(z1), cimag(z1));
	z1 = conj(1 - I);
	printf("\tconj(1 + i) = %.lf + %.lfi\n", creal(z1), cimag(z1));
}

void	z_sqrt(void)
{
	double complex	z1;

	printf("[%s] Square root :\n", "C99");
	z1 = csqrt(-1);
	printf("\tsqrt(-1) = %.lf + %.lfi\n", creal(z1), cimag(z1));
}

void	z_add(void)
{
	double complex	z1;

	printf("[%s] Addition:\n", "C99");
	z1 = (2 + I) + (-3 - 3 * I);
	printf("\t(2 + I) + (-3 - 3i) = %.lf + %.lfI\n", creal(z1), cimag(z1));
}

void	z_subs(void)
{
	double complex	z1;

	printf("[%s] Substraction:\n", "C99");
	z1 = (2 + I) - (-3 - 3.0I);
	printf("\t(2 + I) - (-3 - 3i) = %.lf + %.lfI\n", creal(z1), cimag(z1));
}

void	z_mult(void)
{
	double complex	z1;

	printf("[%s] Multiplication:\n", "C99");
	z1 = (2 + I) * (-3 - 3.0I);
	printf("\t(2 + I) * (-3 - 3i) = %.lf + %.lfI\n", creal(z1), cimag(z1));
}

void	z_div(void)
{
	double complex	z1;

	printf("[%s] Division:\n", "C99");
	z1 = (2 + I) / (-3 - 3.0I);
	printf("\t(2 + I) / (-3 - 3i) = %.2lf + %.2lfI\n", creal(z1), cimag(z1));
}

int	main(void)
{
	z_squared();
	z_pow();
	z_conj();
	z_sqrt();
	z_add();
	z_subs();
	z_mult();
	z_div();
	return (0);
}
