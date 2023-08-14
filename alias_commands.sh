#!/bin/bash
alias sendit="git add . && git commit -m 'Mandatory tasks' && git push" && alias gccerror="gcc -Wall -pedantic -Werror -Wextra -std=gnu89 main.c" && alias gccperror="gcc -Wall -pedantic -Werror -Wextra -std=gnu89 main.c _putchar.c" && alias gccstd="gcc -Wall -pedantic -Werror -Wextra -std=gnu89" && alias gccdebug="gcc -g -Wall -pedantic -Werror -Wextra -std=gnu89" && alias leaks="valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes" && alias branch="git push --set-upstream origin" && alias debug="gdb ./a.out"
