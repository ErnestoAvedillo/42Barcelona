~/bin/bash
make -C$HOME/Desktop/42GHRepo/Libft/entrega/ all
make -C$HOME/Desktop/42GHRepo/Libft/test_lib/ all
echo compilo
gcc -Wall -Wextra -Werror -o test.a test.c ./test_lib/test_lib.a ./entrega/libft.a
