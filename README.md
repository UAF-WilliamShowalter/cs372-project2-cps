# CS 372 Project 2
# CPS: C++ to PostScript

[![Pending](https://badge.waffle.io/Nezteb/cs372-project2-cps.svg?label=pending\/in-queue&title=Pending)](http://waffle.io/Nezteb/cs372-project2-cps)
[![Ongoing](https://badge.waffle.io/Nezteb/cs372-project2-cps.svg?label=ongoing\/normal&title=Ongoing)](http://waffle.io/Nezteb/cs372-project2-cps)
[![Critical](https://badge.waffle.io/Nezteb/cs372-project2-cps.svg?label=ongoing\/critical&title=Critical)](http://waffle.io/Nezteb/cs372-project2-cps)

Collaborators: Noah Betzen, William Showalter, Saira Walia.

This is the source code repository for a C++ to PostScript project for CS372.

`main.cpp` is the release suite.

`test.cpp` is the test/debug suite. (confirmed working)

Both compile with: `clang++ -std=c++1y -Wall` (don't forget to also compile `classes/*.cpp`).

The important files of this project are:

`main.cpp` (main suite, currently empty)

`test.cpp` (test suite, main focus of project)

`classes/Shape.*` (code for base class Shape)

`classes/Polygon.*` (code for class Polygon)

`classes/Rectangle.*` (code for class Rectangle)

`classes/Circle.*` (code for class Circle)

`classes/Square.*` (code for class Square)

`classes/Triangle.*` (code for class Triangle)

`classes/Spacer.*` (code for class Spacer)

`classes/Star.*` (code for class Star, custom shape)

`classes/ShapeDecorator.*` (code for class ShapeDecorator, using Decorator design pattern)

`classes/RotatedShape.*` (code for class RotatedShape)

`classes/ScaledShape.*` (code for class ScaledShape)

`classes/CompoundShape.*` (code for class CompoundShape)

`classes/Layered.*` (code for class Layered)

`classes/Horizontal.*` (code for class Horizontal)

`classes/Vertical.*` (code for class Vertical)

By including all of the code in the `classes` directory, all functionality will be displayed in any main code.

By compiling our `test.cpp` file with all of the class code and running the output executable, a fiel called `experiment.ps` is generated with the postscript generated.

This project will make use of <a href="https://waffle.io/nezteb/cs372-project2-cps">Waffle.io badges</a>, which can be seen near the top of this readme. Click on any of them to be directed to the page.

This project will have a <a href="https://drive.google.com/folderview?id=0Bx9SJ1Pr_IlKfkFZU0c5dHR6TDhvZzJSWm5NQzJiWkE0ZGtKWXlzMmFybUxEQTFvMUtGOGc&usp=sharing">Google Drive folder</a> for any non-code assets. Anyone with the link can view; only the collaborators of this project can edit.

An incomplete UML diagram for the project can also be found in the Google Drive folder.

The test/debug suite code makes use of <a href="https://github.com/philsquared/Catch">`catch.hpp`</a>, a C++ single-include unit-testing framework.