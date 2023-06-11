/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_and_merge_sort.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donglee2 <donglee2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 15:11:57 by donglee2          #+#    #+#             */
/*   Updated: 2023/05/19 20:19:56 by donglee2         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
// swap function

void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

// bubble sort 

void	bubble_sort(int	*arr, int arrlen)
{
	size_t	idx;
	size_t	end;
	size_t	swapped;

	swapped = 0;
	idx = 0;
	end = arrlen - 1;
	while (0 < end)
	{
		idx = 0;
		while (idx < end)
		{
			if (arr[idx] > arr[idx + 1])
			{
				swap(&arr[idx], &arr[idx + 1]);
				swapped = 1;
			}
			idx++;
		}
		if (swapped == 0)
			break ;
		end--;
	}
}

// void	bubble_sort(int *arr, int left, int right)
// {
//     for (size_t end = right - left; end > 0; end--)
// 	{
//         int swapped = 0;
//         for (size_t i = left; i < left + end; i++)
// 		{
//             if (arr[i] > arr[i + 1])
// 			{
//                 swap(&arr[i], &arr[i + 1]);
//                 swapped = 1;
//             }
//         }
//         if (!swapped)
// 		{
//             // 이미 정렬된 경우 반복 중단
//             break;
//         }
//     }
// }

// // selection sort
// // arr[min_idx] shold be the first element of rest array

// void	selection_sort(int *arr, int left, int right)
// {
// 	size_t	min_idx;
// 	size_t	start;
// 	size_t	idx;
// 	size_t	strlen;

// 	strlen = right - left + 1;
// 	start = -1;
// 	while (++start < ft_strlen(arr))
// 	{
// 		min_idx = start;
// 		idx = start;
// 		while (idx < ft_strlen(arr))
// 		{
// 			if (arr[min_idx] > arr[idx])
// 				min_idx = idx;
// 			idx++;
// 		}
// 		swap(&arr[min_idx], &arr[start]);
// 	}
// }

// // insertion sort

// void	insertion_sort(int *arr, int left, int right)
// {
// 	size_t	start;
// 	size_t	idx;
// 	size_t	strlen;

// 	strlen = right - left + 1;
// 	start = 0;
// 	while (start < strlen)
// 	{
// 		idx = start;
// 		while (0 < idx)
// 		{
// 			if (arr[idx - 1] < arr[idx])
// 				swap(&arr[idx], &arr[idx - 1]);
// 			idx--;
// 		}
// 		start++;
// 	}
// }

// // void merge(int data[], int p, int q, int r)
// // {
// // 	int i = p, j = q + 1, k = p;
// // 	int tmp[8]; // 새 배열
// // 	while (i <= q && j <= r)
// // 	{
// // 		if (data[i] <= data[j])
// // 			tmp[k++] = data[i++];
// // 		else
// // 			tmp[k++] = data[j++];
// // 	}
// // 	while (i <= q)
// // 		tmp[k++] = data[i++];
// // 	while (j <= r)
// // 		tmp[k++] = data[j++];
// // 	for (int a = p; a <= r; a++)
// // 		data[a] = tmp[a];
// // }

// void	merge(char *arr, size_t left, size_t right)
// {
// 	size_t	head_1;
// 	size_t	head_2;
// 	size_t	mid;
// 	size_t	str_size;
// 	char	*tmp_str;
// 	size_t	idx;

// 	idx = 0;
// 	str_size = right - left + 1;
// 	tmp_str = (char *)malloc(sizeof(char) * (str_size + 1));
// 	tmp_str[str_size] = '\0';
// 	mid = (left + right) / 2;
// 	head_1 = left;
// 	head_2 = mid + 1;
// 	while (head_1 <= mid && head_2 <= right)
// 	{
// 		if (arr[head_1] <= arr[head_2])
// 		{
// 			tmp_str[idx] = arr[head_1];
// 			idx++;
// 			head_1++;		
// 		}
// 		else
// 		{
// 			tmp_str[idx] = arr[head_2];
// 			idx++;
// 			head_2++;
// 		}
// 	}
// 	free(tmp_str);
// }


// void	merge(char *arr, size_t left, size_t right)
// {
// 	size_t	head_1;
// 	size_t	head_2;
// 	size_t	mid;
// 	size_t	str_size;
// 	char	*tmp_str;
// 	size_t	idx;

// 	idx = 0;
// 	str_size = right - left + 1;
// 	tmp_str = (char *)malloc(sizeof(char) * (str_size + 1));
// 	tmp_str[str_size] = '\0';
// 	mid = (left + right) / 2;
// 	head_1 = left;
// 	head_2 = mid + 1;
// 	while (head_1 <= mid || head_2 <= right)
// 	{
// 		if (head_1 <= mid && (arr[head_1] <= arr[head_2] || head_2 > right))
// 		{
// 			tmp_str[idx] = arr[head_1];
// 			head_1++;
// 		}
// 		else
// 		{
// 			tmp_str[idx] = arr[head_2];
// 			head_2++;
// 		}
// 		idx++;
// 	}
// 	for (idx = 0; idx < str_size; idx++)
// 		arr[left + idx] = tmp_str[idx];
// 	free(tmp_str);
// }

// // merge sort

// void	merge_sort(char *arr, size_t left, size_t right)
// {
// 	size_t	mid;

// 	if (left < right)
// 	{
// 		mid = (left + right) / 2;
// 		merge_sort(arr, left, mid);
// 		merge_sort(arr, mid + 1, right);
// 		merge(arr, left, right);
// 	}
// }

// quick sort

int	main(void)
{
	int	arr1[5] = {3, 1, 5, 4, 2};
	int	arr2[6] = {3, 1, 5, 2, 6, 4};
	int	tmp1[5] = {};
	int	tmp2[6] = {};

	printf("***************************SORT SORT***************************\n");
	printf("int	arr1[6] = {3, 1, 5, 4, 2}\n");
	printf("int	arr2[7] = {3, 1, 5, 2, 6, 4}");
	printf("\n");
	printf("--------------------------BUBBLE SORT--------------------------\n");
	memcpy(tmp1, arr1, sizeof(arr1));
	memcpy(tmp2, arr2, sizeof(arr2));
	bubble_sort(tmp1, 5);
	bubble_sort(tmp2, 6);
	printf("tmp1 : ");
	for (int i = 0; i < 5; i++)
		printf("%d ", tmp1[i]);
	printf("\n");
	printf("tmp2 : ");
	for (int i = 0; i < 6; i++)
		printf("%d ", tmp2[i]);
// 	printf("------------------------SELECTION SORT------------------------\n");
// 	tmp1 = ft_strdup(str1);
// 	tmp2 = ft_strdup(str2);
// 	selection_sort(tmp1);
// 	selection_sort(tmp2);
// 	printf("tmp1 : %s\n", tmp1);
// 	printf("tmp2 : %s\n", tmp2);

// 	printf("------------------------INSERTION SORT------------------------\n");
// 	tmp1 = ft_strdup(str1);
// 	tmp2 = ft_strdup(str2);
// 	insertion_sort(tmp1);
// 	insertion_sort(tmp2);
// 	printf("tmp1 : %s\n", tmp1);
// 	printf("tmp2 : %s\n", tmp2);

// 	printf("--------------------------MERGE SORT--------------------------\n");
// 	tmp1 = ft_strdup(str1);
// 	tmp2 = ft_strdup(str2);
// 	merge_sort(tmp1, 0, 4);
// 	merge_sort(tmp2, 0, 5);
// 	printf("tmp1 : %s\n", tmp1);
// 	printf("tmp2 : %s\n", tmp2);


// 	printf("--------------------------QUICK SORT--------------------------\n");

// 	printf("str1 : %s\n", str1);
// 	printf("str2 : %s\n", str2);
}