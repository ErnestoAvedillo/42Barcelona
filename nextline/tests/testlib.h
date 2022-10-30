/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testlib.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 11:16:38 by eavedill          #+#    #+#             */
/*   Updated: 2022/10/29 11:21:06 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef TESTLIB_HEAD
# define TESTLIB_HEAD
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "../entrega/get_next_line.h"
# include "../../Libft/entrega/libft.h"


#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"


int standardread(char *filename, int nrlines);

#endif

