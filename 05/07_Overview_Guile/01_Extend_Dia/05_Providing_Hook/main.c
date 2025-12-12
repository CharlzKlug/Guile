/* eval gcc (pkg-config --cflags guile-3.0) -o ph main.c \
   (pkg-config --libs guile-3.0) */
#include <libguile.h>

int main() {
  scm_init_guile();
  scm_c_eval_string("(define (display-value input-val) \
                       (display input-val) \
                       (display \"\n\"))");
  scm_c_eval_string("(display-value 42)");
}
