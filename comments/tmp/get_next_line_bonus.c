/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donglee2 <donglee2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 19:45:21 by donglee2          #+#    #+#             */
/*   Updated: 2023/04/05 09:23:23 by donglee2         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdlib.h>

/*
Repeated calls (e.g., using a loop) to yourget_next_line()function should let you read the text file pointed to by the file descriptor,one line at a time.
 •Your function should return the line that was read. 
 If there is nothing else to read or if an error occurred, it should return NULL.
 •Make sure that your function works as expected both when (reading a file) and when (reading from the standard input).
 •Please notethat the (returned line should include the terminating\ncharacter), (except if the end of file was reached) (and does not end with a\ncharacter.)
 •Your header file get_next_line.h must at least contain the prototype of the get_next_line()function.
 •Add all the helper functions youo≤ µou need in theget_next_line_utils.cfile
 */
/*
External functs.read, malloc, free 
*/
// 구조체????

/*
어떻게 해야하는가?
1. open txt file// 이 함수 call하기 전에.
2. read txt file
3. return line add that 'read func' read

structyre type??
static variable??

*/
char	*get_next_line_(int fd)
{
	char	*new_line;
	static;

	if (fd == -1)
		return (NULL);
	read(fd, buf, );

	return (new_line);
}
