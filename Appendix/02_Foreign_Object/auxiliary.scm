(define (test-run x)
  (display x)
  (display "\n"))

(define (print-foo-data-val input-foo)
  (test-run (get-val-from-foo-data input-foo)))
