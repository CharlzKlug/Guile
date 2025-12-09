/* eval gcc (pkg-config --cflags guile-3.0) -o mt main.c \
   (pkg-config --libs guile-3.0) */
#include <libguile.h>
#include <stdio.h>

SCM my_list_to_vector (SCM list) {
  SCM vector = scm_make_vector (scm_length (list), SCM_UNDEFINED);
  size_t len, i;

  len = scm_c_vector_length (vector);
  i = 0;
  while (i < len && scm_is_pair (list)) {
    scm_c_vector_set_x (vector, i, scm_car (list));
    list = scm_cdr (list);
    i++;
  }

  return vector;
}

SCM my_pedantic_list_to_vector (SCM list) {
  SCM vector = scm_make_vector (scm_length (list), SCM_UNDEFINED);
  size_t len, i;

  len = scm_c_vector_length (vector);
  i = 0;
  while (i < len) {
    scm_c_vector_set_x (vector, i, scm_car (list));
    list = scm_cdr (list);
    i++;
  }

  return vector;
}

int main() {
  scm_init_guile();
  SCM a = scm_from_int (42);
  scm_list_1(a);
  SCM my_vect = my_list_to_vector(scm_list_1(a));
  SCM my_vect2 = my_pedantic_list_to_vector(scm_list_1(a));
}
