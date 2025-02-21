1) MaxSharePrice.cpp -This code calculates the maximum profit that can be earned by buying and selling shares (stocks) on different days, with a limit of at most k transactions. A transaction means buying shares on one day and selling them on a later day.
   
2) Sixpep1TypingSpeed.cpp - This code is a typing speed test application that allows users to test and improve their typing speed and accuracy. It uses file handling to store and retrieve the highest score permanently, so the score persists even after the application is closed and reopened.

What the Code Does
Main Features:

Test Typing Speed: Users are given random words to type, and their typing speed and accuracy are measured.

Score Calculation: Points are awarded based on how quickly and accurately the user types the word.

High Score Tracking: The highest score achieved by any user is stored in a file (highscore.txt) and can be displayed.

Save and Quit: Users can save their progress and exit the application.

How It Works:

The program displays a menu with options:

New Word: A random word is selected from a predefined list, and the user types it. The time taken and accuracy are recorded, and points are awarded.

Score: Displays the user's current total score.

High Score: Displays the highest score ever achieved (stored in highscore.txt).

Save & Quit: Saves the current score (if it's the highest) and exits the application.

File Handling:

The highest score is stored in a file (highscore.txt). Whenever the application starts, it reads the highest score from this file.

If the user achieves a new high score, it updates the file with the new score.

3) Sixpep3.cpp - This code is a simple College Management System implemented in C++. It allows users to manage student records, including adding, displaying, deleting, editing, and searching for students based on their age, name, or district. The program stores student data in a file (College.txt) and uses a vector to manage the records in memory.
