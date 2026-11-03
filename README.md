# semester_2_OOP_project
This is the open ended OOP project from my second semester. We were free to make whatever we wanted, so I tried to make a basic turn based game using only barebones graphics on the terminal itself with the help of ASCII art and Windows.h.

# Tools

- C++

# Features

- Arrow key and Enter key based terminal game. **No mouse use is involved.**
- Randomized damage with attacks based on different formula for most attacks.
- Turn based game similar to some of the popular game on the market.
- Functionality to save the game in the middle of the battle.
- The player can select the type of audio they want to use as background music.
- Different ASCII based sprites included raw.

# Areas for Improvement
- The context is being modified upon each screen change through the use of recursion. During second semester I did not know much about stacks and how they are used in the CPU itself to handle switching between different contexts and sections of the memory. I did regret my design later on when I studied my Computer Organization and Assembly course next semester. Current design is basically Brute Force through recursion.
- Even though the code is modular, at the time I did not have much time to complete the project, so I coded it without thinking of the reusability and the design first. The functions are basically acting like monolithic sections in like half of the code.
- The attack system can be improved. I tried to make the damage randomized, but some of the attacks are basically useless and others are overpowered.
- The types of the different monsters have been coded in but they are not being used in damage formulas because I did not have enough time.

# Notes
- **Convert the mp3s to wav first before compiling the code yourself or they will not be compiled into the game.**
- **DO NOT RUN THE GAME INSIDE VSCODE. The compiled exe must be run as a maximized standalone terminal or the graphics will be messed up.**
- The audios used as background music are just the top few copyright free audios I sourced from https://pixabay.com/music/ and am using them under section 5 of their terms and service "Content License granted to you for Content (other than CC0 Content)". Please be respectful of their website and visit them to source audios.
- The ASCII art is sourced from "https://www.asciiart.eu/". I DO NOT own anything. I only modified these sprites enough to fit on my laptop screen using C++ cout statements.
- The names of the audio files are just placeholders.
- The death effect sound is the public domain sound effect called Wilhelm scream.
- Read the comments in the code for the in-game formulas and logic.


