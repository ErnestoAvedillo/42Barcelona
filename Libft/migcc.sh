make -C./entrega/ all
make -C./test_lib/ all
echo compilo
gcc -Wall -Wextra -Werror -o test.a test.c ./test_lib/test_lib.a ./entrega/libft.a
