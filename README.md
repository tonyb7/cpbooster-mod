cpbooster-mod
===

A script to move/rename the files generated by [cpbooster](https://github.com/searleser97/cpbooster) to a structure that suits my taste better.

This program does the following:
1. Renames the directory of the contest to a user-specified name
2. Creates a subdirectory for each problem, and moves all files related to the problem to that directory
3. Shortens the filename of each file to include only the problem letter and file extension.  

Usage:
1. Compile with `make`
2. Move executable to the folder where you store contests
3. Retrieve the contest via [cpbooster](https://github.com/searleser97/cpbooster) and [competitive-companion](https://github.com/jmerle/competitive-companion),
4. Run the executable, providing the current folder name as the first argument, and the desired folder name as the second argument.

Ex:
```
./mod Codeforces-EducationalCodeforcesRound102RatedforDiv.2 Edu102
```

