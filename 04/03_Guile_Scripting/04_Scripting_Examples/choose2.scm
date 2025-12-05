#! /usr/bin/env sh
exec guile -e '(@ (fac) main)' -s "$0" "$@"
!#

(define-module (fac)
  #:export (main)
  #:declarative? #f)

(load "fact.scm")

(define (choose n m)
  (/ (fact m) (* (fact (- m n)) (fact n))))

(define (main args)
  (let ((n (string->number (cadr args)))
        (m (string->number (caddr args))))
    ;; (display (choose n m))
    (display (fact 2))
    (newline)))
