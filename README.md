# beaver
My own mathematical OOP programming language.

![GitHub License](https://img.shields.io/github/license/OdysseyOfTheDragons/beaver)
![GitHub Repo stars](https://img.shields.io/github/stars/OdysseyOfTheDragons/beaver)
![GitHub repo size](https://img.shields.io/github/repo-size/OdysseyOfTheDragons/beaver)
![GitHub Sponsors](https://img.shields.io/github/sponsors/OdysseyOfTheDragons)

[![ko-fi](https://ko-fi.com/img/githubbutton_sm.svg)](https://ko-fi.com/A0A4V5RHQ)

## Origin

It's been years I dream about building my own programming language. But years passed, and nothing happened... until last year. For homework in my school, we had to do a simple `C` program to manipulate polynomials.

Interested, I dug a little bit further and built a working REPL from scratch, in order for the teacher to use the functionalities without looking at the code (well, he still had, of course, but he could at least play a little bit with it).

From that day onward, I read God knows how many websites, promising you to end the tutorial with a toy programming language. The thing is... I do not want to build a _toy_ programming language, but a full-featured programming language, oriented towards polynomials manipulation. And what's more, I don't want to build a LISP (people in the same situation as me will understand what I mean).

So here is a project, that will most likely die in a few months like every other project I started, but well, maybe I will learn things during that short time...

The name, _beaver_ comes from the fact that building a language takes time, and needs to be strong enough to resist waves. I think the name fits well with the way to build a language.

## The project

The project will start small, and I hope it will grow bigger and bigger over time.

Here are the specifications:

| **Specification** | Value |
| :--- | :--- |
| **Language** | `C`, `OCaml` |
| **Type** | Interpreted, Compiled |

Maybe some explanations are needed, no?

At school, we learn the `C` and `OCaml` programming languages. So my language will be built using ONLY these two languages. I think most of the code will be pure `C`, but I may want to use `OCaml` sometimes (even for a single function that would take less than 10 lines in `C`, and which would take 20 lines in `OCaml` with the interfacing to `C`. But hey, am I dumb or am I not?)

The language will be wholly interpreted, but there will be an option to compile: all the normally printed out strings will be stored, put in a dummy `C` program, and then compiled on the host machine. This is a trick, I know, but if it works, that's what counts.

I will try to implement the basic functionalities with a good complexity, be it in time or in space.
