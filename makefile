default:
	gcc -D_GNU_SOURCE -lm main.c

s:
	gcc -Wall -Wextra -Wpedantic -Werror -Werror -D_GNU_SOURCE lm -fsanitize=address -Werror main.c

c:
	rm ./a.out
	rm -R ./build/

clean:
	rm ./a.out
	rm -R ./build/