/* eval gcc (pkg-config --cflags guile-3.0) -o mt main.c \
   (pkg-config --libs guile-3.0) */

/* Content of file /home/user/tmp/imx.scm: */
/* (define (hello) */
/*   (display "Hello\n")) */

#include <libguile.h>

int main() {
  scm_init_guile();
  SCM code_file_name = scm_from_locale_string ("/home/user/tmp/imx.scm");
  scm_primitive_load (code_file_name);
  scm_eval_string (scm_from_locale_string ("(hello)"));
}
