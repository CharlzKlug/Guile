/* eval gcc (pkg-config --cflags guile-3.0) -o ts main.c \
   (pkg-config --libs guile-3.0) */
#include <libguile.h>
#include <stdio.h> // For `printf`.

void inner_main(void* input_data, int argc, char **argv) {
  int foo() {
    return 42;
  }
  scm_init_guile();
  scm_c_eval_string("(define (display-value input-val) \
                       (display input-val) \
                       (display \"\n\"))");
  scm_c_eval_string("(display-value 42)");
  printf("from foo(): %d\n", foo());
}

int main(int argc, char **argv) {
  scm_boot_guile(argc, argv, inner_main, NULL);
}
