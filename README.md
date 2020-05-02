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

### Addendum 1

I added the icon I used for this app, because it appears in the .pro file. Its a little start icon, which I got from this amazing website: https://icon-icons.com/

### Addendum 2

I included an executable in the 'Deploy' folder that you can run and try the program for yourself. (Its only a Windows executable.)

You will need to have MSVC Redistributable installed on your device (x64 is preferred), which you can download here: https://support.microsoft.com/en-us/help/2977003/the-latest-supported-visual-c-downloads

Also, a decent anti-virus will delete the program once you download it.
