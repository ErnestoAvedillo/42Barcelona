cd test_lib
make all
cd ../Libft
make all
cd ..
gcc -Wall -Wextra -Werror  -ILibft/ -Itest_lib/   -o test.a test.c Libft/Libft.a test_lib/test_libft.a -LLibft/ -Ltest_lib/
