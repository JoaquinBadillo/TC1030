# Modelling a Streaming Service 🎞💻
Author: Joaquín Badillo

## Running the program
To run the program make sure you have a C++ compiler installed in your computer, the GCC compiler is a great option. Then you can compile the game using your prefered method, if you don't know how to compile (and you have the GCC compiler) you will want to move to the `src` directory and execute
```
$ g++ main.cpp -o main 
```
if it gets compiled correctly you should be able to execute
```
$ ./main
```

If your compiler does not compile correctly with that command you may need to include all the header files for it to link them correctly. That means you should try to execute 
```
$ g++ main.cpp video.hpp episode.hpp movie.hpp streaming.hpp -o main
```
Now you should be able to execute `$ ./main`. Otherwise check GCC was installed properly.

## Using the program
Once the program executes you will see a menu displayed in your terminal. To use any of the options listed on the menu just input the number associated to that option on the menu. Of course, to find movies and series you should load the data first; but it is not mandatory to do so, you will be able to select any other option even if you get no results.

## Important details
The board is constantly getting deleted and updated. In order to work as intended the program executes the command `@cls||clear` in the terminal. It seems to work on the Ubuntu Linux Distro, however I haven't checked it on other operative systems and Windows systems might have trouble with it. I hope it works fine on this OS, if it does not work as intended I would encourage you to use WSL, MacOS should not have any trouble since the console in Linux is cleared in the same way.