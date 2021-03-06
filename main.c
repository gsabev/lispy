#include <stdio.h>
#include <stdlib.h>
#include <editline/readline.h>
#include <editline/history.h>

#include "lispy.h"

int main(int argc, char** argv) {
  puts("Lispy version 0.0.1");
  puts("Press Ctrl+C to exit");

  init_grammar();

  while(1) {
    char* input = readline("lispy>");
    add_history(input);

    lval* result = eval(input);

    lval_print(*result);

    free_lval(result);
    free(input);
  }

  free_grammar();
  return 0;
}


