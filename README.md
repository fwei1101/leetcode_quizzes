# Leetcode Quizzes Local Runner/Debugger

## Description

When you need to debug your solution to leetcode quizzes but don't wanna subscribe its plan, deploy this repo on your local machine can help you.

## Features

* Quick creation of quiz project so you can focus on the solution
* Easy parse of test input and output
* Support multiple test cases
* Support vscode debugger
* Support data structures such as
	* Singly Linked List
	* Binary Tree

## Dependency

* C++11 and above
* [yaml-cpp](https://github.com/jbeder/yaml-cpp)

## How to use

`cd` to the repo root and setup some environment variables
```bash
> . ./setup_workspace.sh
```
Create a quiz project
```bash
> cquiz -c <category_name> -n <quiz_name>
```
This will give you
* `<category_name>/<quiz_name>/src/solution.cpp` where your solution to this quiz should go
* `<category_name>/<quiz_name>/test/tcs.yaml` where the input and expected output of the quiz should go
* `<category_name>/<quiz_name>/src/main.cpp` which drives the test if you properly **modify it**.

To test your solution, you should go to `<category_name>/<quiz_name>` and
```bash
> make test
```
