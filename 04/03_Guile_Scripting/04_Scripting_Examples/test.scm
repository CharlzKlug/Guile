#! /usr/bin/env sh
exec guile -e '(@ (fac) main)' -s "$0" "$@"
!#

(define-module (fac)
  #:export (main))

(define (main args)
  (display "hello!\n"))
