#include <unistd.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

// void ft_putnbr(int num)
// {
//     long long l_num;

//     l_num = (long long)num;
//     if (l_num < 0)
//     {
//         ft_putchar('-');
//         l_num *= -1;
//     }
//     if (l_num >= 10)
//     {
//         ft_putnbr(l_num / 10);
//         l_num = l_num % 10;
//     }
//     if (l_num < 10){
//         ft_putchar(l_num + '0');
//     }
// }
// void ft_recul(unsigned int num)
// {
//     if (num == 0)
//         return ;
//     ft_recul(num / 16);
//     ft_putchar("0123456789abcdef"[num % 16]);
// }
int count = 0;

int ft_putnbr(long long num)
{
	if (num < 0)
	{
		ft_putchar ('-');
		count++;
		num *= -1;
	}
	if (10 <= num)
	{
		ft_putnbr(num / 10);
		num = num % 10; 
	}
	if (num < 10)
	{
		ft_putchar("0123456789"[num]);
		count++;
	}
	return(count);
}

void ft_putnbr_16(unsigned int num)
{
	if (num == 0)
		return ;
	ft_putnbr_16(num /16);
	ft_putchar("0123456789abcdef"[num % 16]);
}

#include <stdio.h>

int main(void)
{
    int a = -123456;
    int b = 0xab;

    printf("%d\n", ft_putnbr(a));
    printf("\n");
    ft_putnbr_16(b);
}

 