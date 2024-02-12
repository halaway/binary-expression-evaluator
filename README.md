# Binary Expression Evaluator
Understanding Recursive Data Structures.

## Dependencies

- Windows 10 / Mac
- c++11


## Description

Essentially, this aims to create a Binary Search Tree in C++, which can be implemented
to solve and display Arithmetic Expressions of two possible forms: _"A+B"_ and _"AB*"_ where the operator is positioned to a particular form. This was also intended to test my understanding of other useful data structures such as Stacks and Queues. With this in mind, I was hoping to better understand 
how a compiler might possibly analyze and parse syntax through a trivial approach.

| <img width="242" alt="Screen Shot 2024-02-11 at 10 24 00 PM" src="https://github.com/halaway/binary-expression-evaluator/assets/31904474/5f279daa-1b7d-4188-9fef-550d7c45b955"> |
|:--:| 
| *Visual* |

A possible visual interpretation of how an algebraic expression of a particular form utilizes two stacks for distinguishing between operators and operands while treating a subset of an expression as its own subtree, effectively creating a tree while performing traversals and evaluations all in O(N). 

| <img width="301" alt="Screen Shot 2024-02-11 at 10 28 51 PM" src="https://github.com/halaway/binary-expression-evaluator/assets/31904474/d5953b91-9fb3-4f1c-b46d-ffa922c4f8b0"> |
|:--:| 
| *Implementation* |



## Features

- Arithmetic Expressions can be displayed appropriately with balanced parentheses such as:
- _((((A+B)-C)+D)*E)_ or _((4* 2)*(3+6))_ where each inner node is an operator and every leaf is an operand.
- Secondly, while this program is minimal, it does attempt to implement a Map using a BST with key-value pairs of the form: 
- _(Key, Value)_


## Contributing

If you have a suggestion for what should be improved, your contributions will be greatly appreciated. Simply: 
1. Fork the Project
2. Create your Feature Branch 
3. Commit your Changes
4. Push to the Branch 
5. Open a Pull Request


## Authors

@donnolis

## Acknowledgments

I particularly do not have any links to the sources I used in creating this, but these for sure played a crucial role. 
- Stackoverflow
- Geeksforgeeks 
- Progamiz
- A C++ textbook

## Note

There are perhaps a lot of issues as I didn't really choose to test how certain inputs would break my already 
buggy code, but for the most part, everything seems to work. Again, this is by no means professional as I was simply messing around and
shoving concepts together. 

_Out of Boredom and curiosity, this is my Creation._





