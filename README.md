## Welcome

The **main.cpp** file in this repository illustrates how to implement the Strategy Design Pattern.

This program was created using **Code::Blocks**, which can be found at **www.codeblocks.org**

To use the program, just run the program and view the result via the console output.

If you are unfamiliar with Object Oriented polymorphic behavior, run the program via the debugger, placing a watch on "log" on line 75.  In this way you can see, at run-time, how the Logger* type of log is transformed into one of the other child class types.  

Additionally, on line 61 the logger->log() method resolves to a specific child class even though logger is a Logger* type.
