# Calculate program

Write a function called calculate() that takes two integers and a char representing
one of the following mathematical operations: +, -, *, /, or % (remainder). Use a switch
statement to perform the appropriate mathematical operation on the integers,
and return the result. If an invalid operator is passed into the function, the
function should print an error message. For the division operator, do an integer
division, and don’t worry about divide by zero.


## compile
- using cmake (automated building)
  - create build directory (in same heirarchy as "include" directory, NOT inside it)
  - run cmake in the new build directory (just run below commands)
  ``` 
    cmake ..
    make all
  ```
  - then just run "calculate" executable file
- don't like automation, compile all 3 c++ files together
  - exmp `g++ operations.cpp io.cpp main.cpp -o calculate`
