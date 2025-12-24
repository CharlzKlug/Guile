/* Compile in Fish: */
/* eval gcc -o simple-snrf main.c (pkg-config --cflags --libs guile-3.0) */

/* Использование guile-snarf: */
/* eval guile-snarf -o snrf.x main.c (pkg-config --cflags guile-3.0) */
#include <libguile.h>
#include <stdio.h>

SCM_SNARF_INIT(printf("This is SCM_SNARF_INIT Code.\n"))
int main(int argc, char **argv) {
#include "snrf.x"
  printf("Hello!\n");
  return 0;
}
