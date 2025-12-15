#include <libguile.h>

/* eval guile-snarf -o image-type.x image-type.c (pkg-config --cflags guile-3.0) */
/* https://docs.oracle.com/cd/E86824_01/html/E54763/guile-snarf-1.html */
SCM_DEFINE (clear_image, "clear-image", 1, 0, 0,
            (SCM image_smob),
            "Clear the image.")

#define FUNC_NAME s_clear_image
{
  /* C code to clear the image in image_smob... */

}
#undef FUNC_NAME

void
init_image_type ()
{
#ifndef SCM_MAGIC_SNARFER
#include "image-type.x"
#endif
}
