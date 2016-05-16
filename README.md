[![Build Status](https://travis-ci.org/priyankabandaru/Minefield.svg?branch=master)](https://travis-ci.org/priyankabandaru/Minefield)

# Minefield

This project can be used to keep track of a simplistic [Minesweeper](https://en.wikipedia.org/wiki/Minesweeper_%28video_game%29)-like game that has a 10x10 field where mines can be placed. Initially, the mines are hidden and the user makes guesses to try to find all the empty spaces *without* choosing any of the hidden mines.

## FieldType

FieldType is an enumerated type to represent the four possible states of the minefield:

`MINE_HIDDEN` a mine that has not been shown to the user

`MINE_SHOWN` a mine that has been shown to the user

`EMPTY_HIDDEN` an empty space that has not yet been guessed by the user

`EMPTY_SHOWN` an empty space that has been guessed by the user

## Member Functions

`Field()` Constructor creates a 10x10 grid with no mines

`void placeMine(int x, int y)` Places a mine at the x,y coordinate in the field

`FieldType get(int x, int y)` Retrieves the state of the field at location (x,y)

`bool isSafe(int x, int y)` **NOT YET IMPLEMENTED** Returns whether or not _map at (x,y) has a mine and throws an exception if the location is illegal

`void revealAdjacent(int x, int y)` **NOT YET IMPLEMENTED** Changes the location from EMPTY_HIDDEN to EMPTY_SHOWN for the location and any valid locations adjacent (immediately above, below, left, or right as printed) to the provided (x,y) location

# Quick Guide

A [Makefile](Makefile) is provided that includes:

* `make clean` removes all compilation and build files besides the source code

* `make` builds the **Field** class and its test class

* `make test` runs the FieldTest with a test runner
