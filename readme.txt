                                     __
        The                         /\ \ 
  ___   _ __   __  __    ___     ___\ \ \___      __   _ __
 /'___\/\`'__\/\ \/\ \ /' _ `\  /'___\ \  _ `\  /'__`\/\`'__\
/\ \__/\ \ \/ \ \ \_\ \/\ \/\ \/\ \__/\ \ \ \ \/\  __/\ \ \/
\ \____\\ \_\  \ \____/\ \_\ \_\ \____\\ \_\ \_\ \____\\ \_\ 
 \/____/ \/_/   \/___/  \/_/\/_/\/____/ \/_/\/_/\/____/ \/_/
                                                             language.

 A functional language for the brave's shell.


* Requirements

    To compile and run cruncher you need:
    - Linux Ubuntu/Debian
    - GCC
    - Flex

* Compiling

    First run flex on `cruncher.l` to generate the lexical analyzer:

        $ flex cruncher.l

    Then compile the generated analyzer:

        $ gcc -lfl cruncher.yy.c -o cruncher.o

    Run the compiled analyzer in an test example:

        $ ./cruncher.o test1.hs
