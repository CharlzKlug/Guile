#! /usr/bin/env sh
exec guile -e 'main' -s "$0" "$@"
!#

(define (main args)
  (load-extension "libguile-bessel" "init_bessel")
  (display (j0 2))
  (display "\n"))
