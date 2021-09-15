/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smetzler <smetzler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 10:07:14 by smetzler          #+#    #+#             */
/*   Updated: 2021/09/15 11:45:35 by smetzler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

void gnl(int fd, int i)
{
	char*	text;
	
	text = get_next_line(fd);
	printf("main%d: %s", i, text);
	free(text);
	text = NULL;
	return ;
}

int	main(void)
{
	int		fd;

	fd = open("/Users/smetzler/42/owngit/get_next_line/cp/gnl_tester/files/multiple_line_with_nl", O_RDONLY);
	gnl(fd, 1);
	gnl(fd, 2);
	gnl(fd, 3);
	gnl(fd, 4);
	gnl(fd, 5);
	gnl(fd, 6);
	// gnl(fd, 7);
	// gnl(fd, 8);
 }