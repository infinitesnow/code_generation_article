# Code generation with Jinja2 in C++
This repository is a companion to my [Medium](https://medium.com/@leledallalonga/code-generation-for-c-4f313deddaa2) article about methods for code generation in C++.

It showcases an implementation of the use case described in the article using Jinja2.

Make sure you have it installed:
```
pip install jinja2
```

First generate the code:
```
./gen_headers.py
```

Then build the project with `g++`:

```
g++ main.cpp
```

It should just work.
