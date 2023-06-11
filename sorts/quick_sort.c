void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b =tmp;
	return ;
}

void quickSort(int start, int end, int *a)
{
	if (start >= end)
		return;
	int key = start, i = start + 1, j = end, temp;
	while (i <= j)
	{
		while (i <= end && a[i] <= a[key])
			i++;
		while (j > start && a[j] >= a[key])
			j--;

		if (i > j)
			swap(&a[key], &a[j]);
		else
			swap(&a[i], &a[j]);
	}

	quickSort(start, j - 1);
	quickSort(j + 1, end);
}