/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpons <tpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/28 16:27:03 by tpons             #+#    #+#             */
/*   Updated: 2020/12/07 15:48:14 by tpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

void check_strlen()
{
	char *empty = "";
	char *hello_world = "Hello world !";
	char *alphabet = "abcdefghijklmnopqrstuvwxyz";

	printf("\n================================\n");
	printf("========== FT_STRLEN ===========\n");
	printf("================================\n\n");
	printf("%-20s: \"%s\"\n", "char *", empty);
	printf("%-20s: 0\n", "expected lenght");
	printf("%-20s: %zu\n", "libc", strlen(empty));	
	printf("%-20s: %zu\n", "libasm", ft_strlen(empty));
	printf("\n");
	printf("%-20s: \"%s\"\n", "char *", hello_world);
	printf("%-20s: 13\n", "expected lenght");
	printf("%-20s: %zu\n", "libc", strlen(hello_world));	
	printf("%-20s: %zu\n", "libasm", ft_strlen(hello_world));
	printf("\n");
	printf("%-20s: \"%s\"\n", "char *", alphabet);
	printf("%-20s: 26\n", "expected lenght");
	printf("%-20s: %zu\n", "libc", strlen(alphabet));	
	printf("%-20s: %zu\n", "libasm", ft_strlen(alphabet));
	printf("\n");
	
	// ------- NULL = SEGFAULT
	// printf("%-20s: \"%s\"\n", "char *", alphabet);
	// printf("%-20s: 0\n", "expected lenght");
	// printf("%-20s: %zu\n", "libc", strlen(NULL));	
	// printf("%-20s: %zu\n", "libasm", ft_strlen(NULL));
	// printf("\n");
}

void clear_buffer(char *buffer, int size)
{
	int i = 0;
	while (i < size)
		buffer[i++] = 0;
}

void check_strcpy()
{
	char buffer[30];
	
	char *empty = "";
	char *hello_world = "Hello world !";
	char *alphabet = "abcdefghijklmnopqrstuvwxyz";
	
	printf("\n================================\n");
	printf("========== FT_STRCPY ===========\n");
	printf("================================\n\n");
	printf("%-20s: \"%s\"\n", "char []", empty);
	printf("%-20s: \"%s\"\n", "libc", strcpy(buffer, empty));	
	clear_buffer(buffer, 30);
	printf("%-20s: \"%s\"\n", "libasm", ft_strcpy(buffer, empty));	
	clear_buffer(buffer, 30);
	printf("\n");
	printf("%-20s: \"%s\"\n", "char []", hello_world);
	printf("%-20s: \"%s\"\n", "libc", strcpy(buffer, hello_world));	
	clear_buffer(buffer, 30);
	printf("%-20s: \"%s\"\n", "libasm", ft_strcpy(buffer, hello_world));	
	clear_buffer(buffer, 30);
	printf("\n");
	printf("%-20s: \"%s\"\n", "char []", alphabet);
	printf("%-20s: \"%s\"\n", "libc", strcpy(buffer, alphabet));	
	clear_buffer(buffer, 30);
	printf("%-20s: \"%s\"\n", "libasm", ft_strcpy(buffer, alphabet));
	clear_buffer(buffer, 30);
	printf("\n");

	// ------- NULL = SEGFAULT
	// printf("%-20s: \"%s\"\n", "char []", alphabet);
	// printf("%-20s: buffer[50]\n", "copy to");
	// printf("%-20s: \"%s\"\n", "libc", strcpy(NULL, NULL));	
	// clear_buffer(buffer, 30);
	// printf("%-20s: \"%s\"\n", "libasm", ft_strcpy(NULL, NULL));
	// clear_buffer(buffer, 30);
	// printf("\n");
}

void check_strcmp()
{
	char *empty = "";
	char *hello_world = "Hello world !";
	char *hello_human = "Hello human !";
	char *hello_world2 = "Hello world !";
	
	printf("\n================================\n");
	printf("========== FT_STRCMP ===========\n");
	printf("================================\n\n");
	printf("%-20s: \"%s\"\n", "char *", hello_world);
	printf("%-20s: \"%s\"\n", "compared to", hello_human);
	printf("%-20s: \"%d\"\n", "libc", strcmp(hello_world, hello_human));
	printf("%-20s: \"%d\"\n", "libasm", ft_strcmp(hello_world, hello_human));
	printf("\n");
	printf("%-20s: \"%s\"\n", "char *", hello_world);
	printf("%-20s: \"%s\"\n", "compared to", hello_world2);
	printf("%-20s: \"%d\"\n", "libc", strcmp(hello_world, hello_world2));
	printf("%-20s: \"%d\"\n", "libasm", ft_strcmp(hello_world, hello_world2));
	printf("\n");
	printf("%-20s: \"%s\"\n", "char *", hello_world2);
	printf("%-20s: \"%s\"\n", "compared to", empty);
	printf("%-20s: \"%d\"\n", "libc", strcmp(hello_world2, empty));
	printf("%-20s: \"%d\"\n", "libasm", ft_strcmp(hello_world2, empty));
	printf("\n");

	// ------- NULL = SEGFAULT
	// printf("%-20s: \"%s\"\n", "char *", hello_world2);
	// printf("%-20s: %s\n", "compared to", "NULL");
	// printf("%-20s: \"%d\"\n", "libc", strcmp(NULL, hello_world2));
	// printf("%-20s: \"%d\"\n", "libasm", ft_strcmp(NULL, empty));
	// printf("\n");
}

void check_write()
{
	char *hello_world = "Coucou\n";
	char *empty = "";

	printf("\n================================\n");
	printf("========== FT_WRITE ============\n");
	printf("================================\n\n");
	printf("%-20s: \"%s\"\n", "char *", hello_world);
	printf("%-20s: \"%zd\"\n", "libc", write(1, hello_world, 7));
	// printf("\n");
	printf("%-20s: \"%zd\"\n", "libasm", ft_write(1, hello_world, 7));
	printf("\n");
	printf("%-20s: \"%s\"\n", "char *", empty);
	printf("%-20s: \"%zd\"\n", "libc", write(1, empty, 0));
	// printf("\n");
	printf("%-20s: \"%zd\"\n", "libasm", ft_write(1, empty, 0));
	printf("\n");
	printf("%-20s: \"%s\"\n", "char *", hello_world);
	printf("%-20s: \"%zd\"\nError was :%s\n", "libc", write(-7, hello_world, 7), strerror(errno));
	// printf("\n");
	printf("%-20s: \"%zd\"\nError was :%s\n", "libasm", ft_write(1, NULL, 7), strerror(errno));
	// printf("\n");
	
}

int main()
{
    check_strlen();
	check_strcpy();
	check_strcmp();
	check_write();
    return (0);
}
