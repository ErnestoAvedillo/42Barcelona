120     put_nbr(out);
121     write (1, "\n", 1);
122     put_nbr(out);
123     write (1, "\n", 1);
124     return (0);
125 }
126 */
~
~
ft_printf.c                                                                                   126,2          Bot
  1 #include <unistd.h>
  2 #include <stdarg.h>
  3
  4 int put_str(char *str)
  5 {
  6     int i=-1;
  7     int out = 0;
  8     if (!str)
  9     {
 10         out = write(1, "(null)", 6);
 11         return (out);
 12     }
 13     while(str[++i])
 14         out += write(1, &str[i], 1);
 15     return (out);
 16 }
 17
 18 int put_nbr(int n)
 19 {
 20     int out = 0;
 21     char c;
 22     if (n == -2147483648)
 23     {
 24         out = write(1, "-2147483648", 11);
 25         return (out);
 26     }
 27     if ( n < 0)
 28     {
 29         n *= -1;
 30         write(1, "-", 1);
 31     }
 32     if (n >= 10)
 33         out += put_nbr(n / 10);
 34     c = n % 10 + '0';
 35     out += write(1, &c, 1);
 36     return (out);
 37 }
 38
 39 int put_hex(unsigned int n)
 40 {
 41     int out = 0;
 42     char c[]="0123456789abcdef";
 43     if ( n < 0)
 44     {
 45         n *= -1;
 46         write(1, "-", 1);
 47     }
 48     if (n >= 16)
 49         out += put_hex(n / 16);
 50     out += write(1, &c[n % 16], 1);
 51     return (out);
 52 }
 53
 54 int print_arg(char c, va_list arg)
 55 {
 56     int n, out;
 57     char ct, *str;
 58     out = 0;
 59     if(c == 's')
 60     {
 61         str = va_arg(arg, char*);
 62         out = put_str(str);
 63     }
 64     else if(c == 'c')
 65     {
 66         ct = va_arg(arg, int);
 67         out = write(1, &ct, 1);
 68     }
 69     else if(c == 'i' || c == 'd')
 70     {
 71         n =  va_arg(arg,int);
 72         out = put_nbr(n);
 73     }
 74     else if(c == 'x')
 75     {
 76         n =  va_arg(arg,int);
 77         out = put_hex(n);
 78     }
 79     else if(c == '%')
 80         out = write(1, &c, 1);
 81     return (out);
 82 }
 83
 84 int ft_printf(const char *str, ... )
 85 {
 86     int i = -1;
 87     va_list arg;
 88     int out = 0;
 89     va_start(arg, str);
 90     while (str[++i])
 91     {
 92         if (str[i] == '%')
 93             out += print_arg(str[++i], arg);
 94         else
 95             out += write(1, &str[i], 1);
 96     }
 97     va_end(arg);
 98     return (out);
 99 }
100 /*
101 #include <stdio.h>
102 #include <limits.h>
103
104 int main (int av, char **ac)
105 {
106     if(av<2)
107         return (0);
108     int i = -1234567;
109     int j = -255;
110     int out=0;
111     char *strt= NULL;
112    put_hex(16);
113     write (1, "\n", 1);
114    put_hex(32);
115     write (1, "\n", 1);
116    put_hex(255);
117     write (1, "\n", 1);
118     out = ft_printf (" %% este es el argumento 1=== %s , %c, %d, %x, %d, %s \n", ac[1], 'e', i,j,INT_MIN, strt);
119     out = printf (" %% este es el argumento 1=== %s , %c, %d, %x, %d, %s \n", ac[1], 'e', i,j, INT_MIN, strt);
    put_nbr(out);
121     write (1, "\n", 1);
122     put_nbr(out);
123     write (1, "\n", 1);
124     return (0);
125 }
126 */
~
~
