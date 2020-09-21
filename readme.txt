-------------------------------------------------------------------------------
|%    `*'   ,  The    ~*~      .~     ,*^  /\ \;    +        `*     ^~.   `  %|
|    ;~~.___ + _ __ , __  __ +  ___     ___\ \ \___  ~ , __   _ __   .^   |   |
|  *    /'___\/\`'__\/\ \/\ \ /' _ `\  /'___\ \  _ `\ +/'__`\/\`'__\     -+-  |
|."    /\ \__/\ \ \/ \ \ \_\ \/\ \/\ \/\ \__/\ \ \ \ \/\  __/\ \ \/ `!    |  *|
|   |  \ \____\\ \_\+ \ \____/\ \_\ \_\ \____\\ \_\ \_\ \____\\ \_\   :.    ; |
|  -+-  \/____/ \/_/ ` \/___/  \/_/\/_/\/____/ \/_/\/_/\/____/ \/_/   ~*~     |
|%  |  +~.    *    .;   `  ,   *.     ^*~  .    `~.   *.      ;*`   language.%|
-------------------------------------------------------------------------------

 A functional language for the brave's shell.
 Authored by Jader Martins in 2020.

===============================================================================
=        T h e   C r u n c h e r   D o c u m e n t a t i o n   Version 1.0    =
===============================================================================
1. Introduction
    Cruncher is a shell scripting language that extends Haskell's functional
    with common shell operations based o MapReduce paradigm.


~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
2. Requirements

    To compile and run cruncher you need:

      - Linux Ubuntu/Debian >= 16.4/9
      - gcc >= 8.3.0
      - Flex >= 2.6.4
      - GNU Make >= 4.2.1


~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
3. Compiling

    * First run flex on `cruncher.l` to generate the lexical analyzer:

        $ make flex

    Then compile the generated analyzer:

        $ make


~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
4. Testing

    Run the compiled analyzer in test examples:

        $ make test
