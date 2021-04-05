# CSIS370: C++ Implimentation Of Chess


Chess Prototype
===============

Start by creating the classes necessary for your application. For now, much of the required behavior can be 'stubbed out' - that is, the methods exist, but the body performs no action though it may need to return a bogus hard-coded value to satisfy the compiler.

I would like you to use [my diagram](../Diagrams/Chess2.pdf) (alternatively, [here](../Diagrams/Chess.dia) is a dia file). If you deviate from my design you must include a separate writeup that describes how and why you chose a different approach.

Some notes and corrections:

*   The diagraming tool I used had some odd conventions, specifically in the `Piece` class the italicized methods are "virtual" (some "pure virtual"); my diagram _should_ have italicized (and shown below) `display()` and `canMoveTo()` as those are "pure virtual" methods that can only be implemented in the subclasses.
*   The `Board` class is implementing the _singleton_ pattern where the `getBoard()` method will instantiate a `Board` instance the first time it's called and then continue to return that one instance; so the `Board` class needs an additional private attribute: `static Board* _theBoard` and since it's defined to be static, it's initially `null`.
*   And since the class `Board` is always "in scope" (i.e., "global") there's no reason for any class to have an association to the Board (i.e., `theBoard` in the diagram) as we simply ask for `Board.getBoard()` whenever and where ever we need to get ahold of that object.

Minimally you must:

*   Define **all** of the classes along with their attributes and methods. You will need to fully implement appropriate constructors and destructors (if necessary) for each class. You will need to make **appropriate** choices for attributes that are implemented by container classes and for the placement of attributes that implement the relationships identified on the diagram.
*   Implement a `main()` function (i.e., program) that instantiates necessary objects and positions `Piece`s on the `Board` in their proper starting locations.
*   Implement a simple `display()` method for the `Board` class that displays the current arrangement of pieces on the board. You will obviously need to add some minimal code to `Square`, the `Piece` class and subclasses.

You may work ahead, but please **do not** include any substantial additional code in what you submit; I will have more than enough to read through!

The board ought to look something like this at the beginning of the game:
```
        a    b    c    d    e    f    g    h
     -----------------------------------------
   8 | BR | BN | BB | BQ | BK | BB | BN | BR | 8
     -----------------------------------------
   7 | BP | BP | BP | BP | BP | BP | BP | BP | 7
     -----------------------------------------
   6 |    |    |    |    |    |    |    |    | 6
     -----------------------------------------
   5 |    |    |    |    |    |    |    |    | 5
     -----------------------------------------
   4 |    |    |    |    |    |    |    |    | 4
     -----------------------------------------
   3 |    |    |    |    |    |    |    |    | 3
     -----------------------------------------
   2 | WP | WP | WP | WP | WP | WP | WP | WP | 2
     -----------------------------------------
   1 | WR | WN | WB | WQ | WK | WB | WN | WR | 1
     -----------------------------------------
        a    b    c    d    e    f    g    h
 ```

**Submit:**

*   **Documented** source code (both code and header files) **in a file named `chess.zip`** (if you include any folders or subdirectories in the zipfile you **must** include a traditional makefile for the `make` utility (**not** `cmake`) that creates an executable named chess in the top-most directory - be careful to use only relative pathnames in your makefile). Unlike Java, your main() program should appear as a stand-alone function in a file named chess.cpp. The main function should do nothing more than instantiate neccessary objects, arrange the board, have the board display itself, and then exit.
    
    I will be testing your program and expect to see output that **displays the initial state of the board and then exits**. Thus you should implement the `display()` methods in the `Piece` subclasses and `Board`.
