# SimpleFlashcards

Recently I started learning Japanese once again, and I decided to write a smol flashcard program that I could use universally for anything. I'm actually happy about how it turned out. 

## Dependencies

This program was written in Qt5.12, and there are many Qt specific dependencies. (I obviously used the Chad coding way for everything, not the incel "haha dragging elements onto a window goes brrrrrrrrr" way.)

## Manual

Upon starting the program, you are required to select a file, in which each line contains a pair of words. Obviously, as you can see it in the source as well, I didn't make it foolproof, so if you mess up the file, then just close the program and restart it - and make sure that the contents of your input file is in the "right" format. It's best to feed it files that are UTF8 encoded (it works with Japanese text as well, so thats something :) )

I included example files in the 'examples' folder, if you are curious.

You can use the "Flip" button to 'filp' the card back and forth, and the "Previous" and "Next" buttons to hop along the words. 

There is a small indicator on the top left corner, displaying the number of word-pairs, and where you are in the list. 

Otherwise, I think the usage is self-explanatory - but if you come across something weird, then drop a comment and I'll check it out!
