/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amugnier <amugnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:40:24 by amugnier          #+#    #+#             */
/*   Updated: 2022/12/03 15:17:16 by amugnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <limits.h>
#include <math.h>

// main function to test the ft_printf function

static void test_1(int fd1, int fd2)
{
	const char *test_name = "test1 : ";
	const char *str = "%c";
	const char character = 'a';

	ft_printf(test_name);
	ft_printf(str, character);
	ft_printf("\n");

	dprintf(fd1, test_name);
	dprintf(fd1, str, character);
	dprintf(fd1, "\n");
}

static void test_2(int fd1, int fd2)
{
	const char *test_name = "test2 : ";
	const char *str = "%c";
	const unsigned char character = 32;

	ft_printf(test_name);
	ft_printf(str, character);
	ft_printf("\n");

	dprintf(fd1, test_name);
	dprintf(fd1, str, character);
	dprintf(fd1, "\n");
}

static void test_3(int fd1, int fd2)
{
	const char	*test_name = "test3 : ";
	const char	*str = "%c";
	const unsigned char character = '1';

	ft_printf(test_name);
	ft_printf(str, character);
	ft_printf("\n");

	dprintf(fd1, test_name);
	dprintf(fd1, str, character);
	dprintf(fd1, "\n");
}

static void test_4(int fd1, int fd2)
{
	const char	*test_name = "test4 : ";
	const char	*str = "%ck";
	const char	character = '\0';

	ft_printf(test_name);
	ft_printf(str, character);
	ft_printf("\n");

	dprintf(fd1, test_name);
	dprintf(fd1, str, character);
	dprintf(fd1, "\n");
}

static void test_5(int fd1, int fd2)
{
	const char	*test_name = "test5 : ";
	const char	*str = "%cl%";
	const char	character = 'p';

	ft_printf(test_name);
	ft_printf(str, character);
	ft_printf("\n");

	dprintf(fd1, test_name);
	dprintf(fd1, str, character);
	dprintf(fd1, "\n");
}


static void test_6(int fd1, int fd2)
{
	const char	*test_name = "test6 : ";
	const char	*str = "%cl%k";
	const char	character = 'p';

	ft_printf(test_name);
	ft_printf(str, character);
	ft_printf("\n");

	dprintf(fd1, test_name);
	dprintf(fd1, str, character);
	dprintf(fd1, "\n");
}

static void test_7(int fd1, int fd2)
{
	const char	*test_name = "test7 : ";
	const char	*str = "%c%%%%%%%";
	const char	character = 'i';

	ft_printf(test_name);
	ft_printf(str, character);
	ft_printf("\n");

	dprintf(fd1, test_name);
	dprintf(fd1, str, character);
	dprintf(fd1, "\n");
}

static void test_8(int fd1, int fd2)
{
	const char	*test_name = "test8 : ";
	const char	*str = "c%c%c%c%";
	const char	character = 'i';
	const char	character2 = '\0';
	const char	character3 = '\0';

	ft_printf(test_name);
	ft_printf(str, character, character2, character3);
	ft_printf("\n");

	dprintf(fd1, test_name);
	dprintf(fd1, str, character, character2, character3);
	dprintf(fd1, "\n");

	// printf("%d\n", ft_printf(str, character));
}

static void	test_9(int fd1, int fd2)
{
	const char	*test_name = "test9 : ";
	const char	*str = "wouah%c%chello";
	const char	character = '\0';
	const char	character2 = '\0';

	ft_printf(test_name);
	ft_printf(str, character, character2);
	ft_printf("\n");

	dprintf(fd1, test_name);
	dprintf(fd1, str, character, character2);
	dprintf(fd1, "\n");
}

static void random_test_c(int fd1, int fd2)
{
	srand(time(NULL));
	const char	*test_name = "rand_test 1: ";
	//Random char without 0 - 37
	const char	*str = "%c";
	const char character = rand() % (127 - 32) + 32;


	ft_printf(test_name);
	ft_printf(str, character);
	ft_printf("\n");

	dprintf(fd1, test_name);
	dprintf(fd1, str, character);
	dprintf(fd1, "\n");
}

void character_test(int fd1, int fd2)
{
	char	*w_test = "CHAR TEST\n";
	char	*sep = "-----------\n";
	dprintf(fd1, w_test);
	ft_printf(w_test);
	dprintf(fd1, sep);
	ft_printf(sep);
	test_1(fd1, fd2);
	test_2(fd1, fd2);
	test_3(fd1, fd2);
	test_4(fd1, fd2);
	test_5(fd1, fd2);
	test_6(fd1, fd2);
	test_7(fd1, fd2);
	test_8(fd1, fd2);
	test_9(fd1, fd2);
	random_test_c(fd1, fd2);
}

//INTEGER
static void test_1_i(int fd1, int fd2)
{
	const char	*test_name = "test1 : ";
	const char	*str = "%d";
	const int	nb = 1;

	ft_printf(test_name);
	ft_printf(str, nb);
	ft_printf("\n");

	dprintf(fd1, test_name);
	dprintf(fd1, str, nb);
	dprintf(fd1, "\n");
}


static void test_2_i(int fd1, int fd2)
{
	const char	*test_name = "test2 : ";
	const char	*str = "%d";
	const int	nb = -1;

	ft_printf(test_name);
	ft_printf(str, nb);
	ft_printf("\n");

	dprintf(fd1, test_name);
	dprintf(fd1, str, nb);
	dprintf(fd1, "\n");
}


static void test_3_i(int fd1, int fd2)
{
	const char	*test_name = "test3 : ";
	const char	*str = "%d";
	const int	nb = INT_MAX;

	ft_printf(test_name);
	ft_printf(str, nb);
	ft_printf("\n");

	dprintf(fd1, test_name);
	dprintf(fd1, str, nb);
	dprintf(fd1, "\n");
}


static void test_4_i(int fd1, int fd2)
{
	const char	*test_name = "test4 : ";
	const char	*str = "%d";
	const int	nb = INT_MIN;


	ft_printf(test_name);
	ft_printf(str, nb);
	ft_printf("\n");

	dprintf(fd1, test_name);
	dprintf(fd1, str, nb);
	dprintf(fd1, "\n");
}

static void test_5_i(int fd1, int fd2)
{
	const char	*test_name = "test5 : ";
	const char	*str = "%d";
	const int	nb = -230;

	ft_printf(test_name);
	ft_printf(str, nb);
	ft_printf("\n");

	dprintf(fd1, test_name);
	dprintf(fd1, str, nb);
	dprintf(fd1, "\n");
}

static void test_6_i(int fd1, int fd2)
{
	const char	*test_name = "test6 : ";
	const char	*str = "%d";
	const int	nb = 0;

	ft_printf(test_name);
	ft_printf(str, nb);
	ft_printf("\n");

	dprintf(fd1, test_name);
	dprintf(fd1, str, nb);
	dprintf(fd1, "\n");
}

static void random_test_i(int fd1, int fd2)
{
	srand(time(NULL));
	const char	*test_name = "rand_test 1: ";
	const char	*str = "%d";
	const int nb = rand() % (INT_MAX - INT_MIN) + INT_MIN;

	ft_printf(test_name);
	ft_printf(str, nb);
	ft_printf("\n");

	dprintf(fd1, test_name);
	dprintf(fd1, str, nb);
	dprintf(fd1, "\n");
}


void integer_test(int fd1, int fd2)
{
	char	*w_test = "\nINT TEST\n";
	char	*sep = "-----------\n";
	dprintf(fd1, w_test);
	ft_printf(w_test);
	dprintf(fd1, sep);
	ft_printf(sep);

	test_1_i(fd1, fd2);
	test_2_i(fd1, fd2);
	test_3_i(fd1, fd2);
	test_4_i(fd1, fd2);
	test_5_i(fd1, fd2);
	test_6_i(fd1, fd2);
}


//UNSIGNED TEST
static void test_1_u(int fd1, int fd2)
{
	const char	*test_name = "test1 : ";
	const char	*str = "%u";
	const int	nb = 1;

	ft_printf(test_name);
	ft_printf(str, nb);
	ft_printf("\n");

	dprintf(fd1, test_name);
	dprintf(fd1, str, nb);
	dprintf(fd1, "\n");
}


static void test_2_u(int fd1, int fd2)
{
	const char	*test_name = "test2 : ";
	const char	*str = "%u";
	const int	nb = -1;

	ft_printf(test_name);
	ft_printf(str, nb);
	ft_printf("\n");

	dprintf(fd1, test_name);
	dprintf(fd1, str, nb);
	dprintf(fd1, "\n");
}


static void test_3_u(int fd1, int fd2)
{
	const char	*test_name = "test3 : ";
	const char	*str = "%u";
	const int	nb = INT_MAX;

	ft_printf(test_name);
	ft_printf(str, nb);
	ft_printf("\n");

	dprintf(fd1, test_name);
	dprintf(fd1, str, nb);
	dprintf(fd1, "\n");
}


static void test_4_u(int fd1, int fd2)
{
	const char	*test_name = "test4 : ";
	const char	*str = "%u";
	const int	nb = UINT_MAX;


	ft_printf(test_name);
	ft_printf(str, nb);
	ft_printf("\n");

	dprintf(fd1, test_name);
	dprintf(fd1, str, nb);
	dprintf(fd1, "\n");
}

static void test_5_u(int fd1, int fd2)
{
	const char	*test_name = "test5 : ";
	const char	*str = "%u";
	const int	nb = UINT_MAX;

	ft_printf(test_name);
	ft_printf(str, nb);
	ft_printf("\n");

	dprintf(fd1, test_name);
	dprintf(fd1, str, nb);
	dprintf(fd1, "\n");
}

static void test_6_u(int fd1, int fd2)
{
	const char	*test_name = "test6 : ";
	const char	*str = "%u";
	const int	nb = 0;

	ft_printf(test_name);
	ft_printf(str, nb);
	ft_printf("\n");

	dprintf(fd1, test_name);
	dprintf(fd1, str, nb);
	dprintf(fd1, "\n");
}


void unsigned_integer_test(int fd1, int fd2)
{
	char	*w_test = "\nU_INT TEST\n";
	char	*sep = "-----------\n";
	dprintf(fd1, w_test);
	ft_printf(w_test);
	dprintf(fd1, sep);
	ft_printf(sep);

	test_1_u(fd1, fd2);
	test_2_u(fd1, fd2);
	test_3_u(fd1, fd2);
	test_4_u(fd1, fd2);
	test_5_u(fd1, fd2);
	test_6_u(fd1, fd2);
}

//POINTER

static void test_1_p(int fd1, int fd2)
{
	const char	*test_name = "test1 : ";
	const char	*str = "%p";
	const int	*ptr;

	ft_printf(test_name);
	ft_printf(str, ptr);
	ft_printf("\n");

	dprintf(fd1, test_name);
	dprintf(fd1, str, ptr);
	dprintf(fd1, "\n");
}

static void	test_2_p(int fd1, int fd2)
{
	const char	*test_name = "test2 : ";
	const char	*str = "%p";
	char		*ptr = NULL;

	dprintf(fd1, test_name);
	dprintf(fd1, str, ptr);
	dprintf(fd1, "\n");

	ft_printf(test_name);
	ft_printf(str, ptr);
	ft_printf("\n");
}

static void	test_3_p(int fd1, int fd2)
{
	const char	*test_name = "test3 : ";
	const char	*str = "%p%";
	char		*ptr = NULL;

	dprintf(fd1, test_name);
	dprintf(fd1, str, ptr);
	dprintf(fd1, "\n");

	ft_printf(test_name);
	ft_printf(str, ptr);
	ft_printf("\n");
}


void pointer_test(int fd1, fd2)
{
	char	*w_test = "\nPOINTER TEST\n";
	char	*sep = "-----------\n";
	ft_printf(w_test);
	dprintf(fd1, w_test);
	ft_printf(sep);
	dprintf(fd1, sep);

	test_1_p(fd1, fd2);
	test_2_p(fd1, fd2);
	test_3_p(fd1, fd2);
}

//STRING TEST

static void test_1_s(int fd1, int fd2)
{
	const char	*test_name = "test1 : ";
	const char	*str = "%s";
	const char	*str2 = "Hello World";

	ft_printf(test_name);
	ft_printf(str, str2);
	ft_printf("\n");

	dprintf(fd1, test_name);
	dprintf(fd1, str, str2);
	dprintf(fd1, "\n");
}

static void test_2_s(int fd1, int fd2)
{
	const char	*test_name = "test2 : ";
	const char	*str = "%s";
	const char	*str2 = NULL;

	ft_printf(test_name);
	ft_printf(str, str2);
	ft_printf("\n");

	dprintf(fd1, test_name);
	dprintf(fd1, str, str2);
	dprintf(fd1, "\n");
}

static void test_3_s(int fd1, int fd2)
{
	const char	*test_name = "test3 : ";
	const char	*str = "Hello %s";
	const char	*str2 = "World";

	ft_printf(test_name);
	ft_printf(str, str2);
	ft_printf("\n");

	dprintf(fd1, test_name);
	dprintf(fd1, str, str2);
	dprintf(fd1, "\n");
}

static void test_4_s(int fd1, int fd2)
{
	const char	*test_name = "test4 : ";
	const char	*str = "%s%s";
	const char	*str2 = "Hello";
	const char	*str3 = "World";

	ft_printf(test_name);
	ft_printf(str, str2, str3);
	ft_printf("\n");

	dprintf(fd1, test_name);
	dprintf(fd1, str, str2, str3);
	dprintf(fd1, "\n");
}

static void test_5_s(int fd1, int fd2)
{
	const char	*test_name = "test5 : ";
	const char	*str = "%s%s%";
	const char	*str2 = "Hello";
	const char	*str3 = "World";

	ft_printf(test_name);
	ft_printf(str, str2, str3);
	ft_printf("\n");

	dprintf(fd1, test_name);
	dprintf(fd1, str, str2, str3);
	dprintf(fd1, "\n");
}

static void test_6_s(int fd1, int fd2)
{
	const char	*test_name = "test6 : ";
	const char	*str = "%s%s%s";
	const char	*str2 = "Hello";
	const char	*str3 = "World";
	const char	*str4 = "Hello World";

	ft_printf(test_name);
	ft_printf(str, str2, str3, str4);
	ft_printf("\n");

	dprintf(fd1, test_name);
	dprintf(fd1, str, str2, str3, str4);
	dprintf(fd1, "\n");
}

static void test_7_s(int fd1, int fd2)
{
	const char	*test_name = "test7 : ";
	const char	*str = "Hello %s%%";
	const char	*str2 = "World";

	ft_printf(test_name);
	ft_printf(str, str2);
	ft_printf("\n");

	dprintf(fd1, test_name);
	dprintf(fd1, str, str2);
	dprintf(fd1, "\n");
}

static void test_8_s(int fd1, int fd2)
{
	const char	*test_name = "test8 : ";
	const char	*str = "%%%";

	ft_printf(test_name);
	ft_printf(str);
	ft_printf("\n");

	dprintf(fd1, test_name);
	dprintf(fd1, str);
	dprintf(fd1, "\n");
}

void string_test(int fd1, int fd2)
{
	char	*w_test = "\nSTRING TEST\n";
	char	*sep = "-----------\n";
	ft_printf(w_test);
	dprintf(fd1, w_test);
	ft_printf(sep);
	dprintf(fd1, sep);

	test_1_s(fd1, fd2);
	test_2_s(fd1, fd2);
	test_3_s(fd1, fd2);
	test_4_s(fd1, fd2);
	test_5_s(fd1, fd2);
	test_6_s(fd1, fd2);
	test_7_s(fd1, fd2);
	test_8_s(fd1, fd2);
}

//TEST HEXA MIN

static void test_1_x(int fd1, int fd2)
{
	const char	*test_name = "test1 : ";
	const char	*str = "%x";
	const int	nb = 42;

	ft_printf(test_name);
	ft_printf(str, nb);
	ft_printf("\n");

	dprintf(fd1, test_name);
	dprintf(fd1, str, nb);
	dprintf(fd1, "\n");
}

static void test_2_x(int fd1, int fd2)
{
	const char	*test_name = "test2 : ";
	const char	*str = "%x";
	const int	nb = -42;

	ft_printf(test_name);
	ft_printf(str, nb);
	ft_printf("\n");

	dprintf(fd1, test_name);
	dprintf(fd1, str, nb);
	dprintf(fd1, "\n");
}

static void test_3_x(int fd1, int fd2)
{
	const char	*test_name = "test3 : ";
	const char	*str = "%x";
	const int	nb = 0;

	ft_printf(test_name);
	ft_printf(str, nb);
	ft_printf("\n");

	dprintf(fd1, test_name);
	dprintf(fd1, str, nb);
	dprintf(fd1, "\n");
}

static void test_4_x(int fd1, int fd2)
{
	const char	*test_name = "test4 : ";
	const char	*str = "%x";
	const int	nb = 2147483647;

	ft_printf(test_name);
	ft_printf(str, nb);
	ft_printf("\n");

	dprintf(fd1, test_name);
	dprintf(fd1, str, nb);
	dprintf(fd1, "\n");
}

static void test_5_x(int fd1, int fd2)
{
	const char	*test_name = "test5 : ";
	const char	*str = "%x";
	const int	nb = -2147483648;

	ft_printf(test_name);
	ft_printf(str, nb);
	ft_printf("\n");

	dprintf(fd1, test_name);
	dprintf(fd1, str, nb);
	dprintf(fd1, "\n");
}

static void test_6_x(int fd1, int fd2)
{
	const char	*test_name = "test6 : ";
	const char	*str = "%x";
	const int	nb = 2147483648;

	ft_printf(test_name);
	ft_printf(str, nb);
	ft_printf("\n");

	dprintf(fd1, test_name);
	dprintf(fd1, str, nb);
	dprintf(fd1, "\n");
}

static void test_7_x(int fd1, int fd2)
{
	const char	*test_name = "test7 : ";
	const char	*str = "%x";
	const int	nb = NULL;

	ft_printf(test_name);
	ft_printf(str, nb);
	ft_printf("\n");

	dprintf(fd1, test_name);
	dprintf(fd1, str, nb);
	dprintf(fd1, "\n");
}

static void test_8_x(int fd1, int fd2)
{
	const char	*test_name = "test8 : ";
	const char	*str = "%x%x%x";
	const int	nb = 42;
	const int	nb2 = 0;
	const int	nb3 = -42;

	ft_printf(test_name);
	ft_printf(str, nb, nb2, nb3);
	ft_printf("\n");

	dprintf(fd1, test_name);
	dprintf(fd1, str, nb, nb2, nb3);
	dprintf(fd1, "\n");
}

static void test_9_x(int fd1, int fd2)
{
	const char	*test_name = "test9 : ";
	const char	*str = "%x";
	const int	nb = 0;

	ft_printf(test_name);
	ft_printf(str, nb);
	ft_printf("\n");

	dprintf(fd1, test_name);
	dprintf(fd1, str, nb);
	dprintf(fd1, "\n");
}

//TESTS HEXA MAJ

void hexa_test(int fd1, int fd2)
{
	char	*w_test = "\nHEXA Lower TEST\n";
	char	*sep = "-----------\n";
	ft_printf(w_test);
	dprintf(fd1, w_test);
	ft_printf(sep);
	dprintf(fd1, sep);

	test_1_x(fd1, fd2);
	test_2_x(fd1, fd2);
	test_3_x(fd1, fd2);
	test_4_x(fd1, fd2);
	test_5_x(fd1, fd2);
	test_6_x(fd1, fd2);
	test_7_x(fd1, fd2);
	test_8_x(fd1, fd2);
	test_9_x(fd1, fd2);
}

static void test_1_X(int fd1, int fd2)
{
	const char	*test_name = "test1 : ";
	const char	*str = "%X";
	const int	nb = 42;

	ft_printf(test_name);
	ft_printf(str, nb);
	ft_printf("\n");

	dprintf(fd1, test_name);
	dprintf(fd1, str, nb);
	dprintf(fd1, "\n");
}

static void test_2_X(int fd1, int fd2)
{
	const char	*test_name = "test2 : ";
	const char	*str = "%X";
	const int	nb = -42;

	ft_printf(test_name);
	ft_printf(str, nb);
	ft_printf("\n");

	dprintf(fd1, test_name);
	dprintf(fd1, str, nb);
	dprintf(fd1, "\n");
}

static void test_3_X(int fd1, int fd2)
{
	const char	*test_name = "test3 : ";
	const char	*str = "%X";
	const int	nb = 0;

	ft_printf(test_name);
	ft_printf(str, nb);
	ft_printf("\n");

	dprintf(fd1, test_name);
	dprintf(fd1, str, nb);
	dprintf(fd1, "\n");
}

static void test_4_X(int fd1, int fd2)
{
	const char	*test_name = "test4 : ";
	const char	*str = "%X";
	const int	nb = 2147483647;

	ft_printf(test_name);
	ft_printf(str, nb);
	ft_printf("\n");

	dprintf(fd1, test_name);
	dprintf(fd1, str, nb);
	dprintf(fd1, "\n");
}

static void test_5_X(int fd1, int fd2)
{
	const char	*test_name = "test5 : ";
	const char	*str = "%X";
	const int	nb = -2147483648;

	ft_printf(test_name);
	ft_printf(str, nb);
	ft_printf("\n");

	dprintf(fd1, test_name);
	dprintf(fd1, str, nb);
	dprintf(fd1, "\n");
}

static void test_6_X(int fd1, int fd2)
{
	const char	*test_name = "test6 : ";
	const char	*str = "%X";
	const int	nb = 2147483648;

	ft_printf(test_name);
	ft_printf(str, nb);
	ft_printf("\n");

	dprintf(fd1, test_name);
	dprintf(fd1, str, nb);
	dprintf(fd1, "\n");
}

static void test_7_X(int fd1, int fd2)
{
	const char	*test_name = "test7 : ";
	const char	*str = "%X";
	const int	nb = NULL;

	ft_printf(test_name);
	ft_printf(str, nb);
	ft_printf("\n");

	dprintf(fd1, test_name);
	dprintf(fd1, str, nb);
	dprintf(fd1, "\n");
}

static void test_8_X(int fd1, int fd2)
{
	const char	*test_name = "test8 : ";
	const char	*str = "%X%X%X";
	const int	nb = 42;
	const int	nb2 = 0;
	const int	nb3 = -42;

	ft_printf(test_name);
	ft_printf(str, nb, nb2, nb3);
	ft_printf("\n");

	dprintf(fd1, test_name);
	dprintf(fd1, str, nb, nb2, nb3);
	dprintf(fd1, "\n");
}

static void test_9_X(int fd1, int fd2)
{
	const char	*test_name = "test9 : ";
	const char	*str = "%X";
	const int	nb = 0;

	ft_printf(test_name);
	ft_printf(str, nb);
	ft_printf("\n");

	dprintf(fd1, test_name);
	dprintf(fd1, str, nb);
	dprintf(fd1, "\n");
}

void hexa_test_upper(int fd1, int fd2)
{
	char	*w_test = "\nHEXA Upper TEST\n";
	char	*sep = "-----------\n";
	ft_printf(w_test);
	dprintf(fd1, w_test);
	ft_printf(sep);
	dprintf(fd1, sep);

	test_1_X(fd1, fd2);
	test_2_X(fd1, fd2);
	test_3_X(fd1, fd2);
	test_4_X(fd1, fd2);
	test_5_X(fd1, fd2);
	test_6_X(fd1, fd2);
	test_7_X(fd1, fd2);
	test_8_X(fd1, fd2);
	test_9_X(fd1, fd2);
}

int main(void)
{
	int fd1;
	int fd2;

	fd1 = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	fd2 = open("my_input.txt", O_WRONLY | O_APPEND);

	character_test(fd1, fd2);
	integer_test(fd1, fd2);
	unsigned_integer_test(fd1, fd2);
	pointer_test(fd1, fd2);
	string_test(fd1, fd2);
	hexa_test(fd1, fd2);
	hexa_test_upper(fd1, fd2);
}
