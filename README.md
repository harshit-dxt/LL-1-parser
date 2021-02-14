# Group_name: CG31.
# Student information: 
* Diali Kundu(1801055).
*  Harshit Dixit (1801070).
# contributions : 
* Diali Kundu : left recursion removal function , parsing table create function.
* Harshit Dixit : First and Follow set calculate functions, parser create function , sample lex file.
    It would be wrong to say that any function was implemented by one person completely, it took a lot of time and discussion on each person's part.
# Creating Predictive Parser using c++
* Clone the repository and excute the following commands.
* g++ parser.cpp
* lex lexer.l
* gcc -o myScan lex.yy.c -ll
* cat input.txt | ./myScan | ./a.out
* In parser.cpp, for any user provided grammar, left recursion (if present) is removed by   eliminate_left_recursion function .
* Further get_first_nonterminal calculates the FIRST set for all the non-terminals.
* get_first_terminals calculates the FIRST set for all the terminals.
* Follow calculates FOLLOW set for each terminal and non terminal.
* parsing_table calculates the parsing table for the given grammar.
* create_predictive_parser creates general predictive parser for any grammar.
