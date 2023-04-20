# Getting Started

## Installing GitHub CLI

### MacOS

1. Open the Terminal app on your Mac
2. Run the command: `brew install gh`
3. Wait for the installation process to finish

### Windows

1. Download the GitHub CLI installer from the official website: https://cli.github.com/
2. Open the installer and follow the instructions on the screen
3. Wait for the installation process to finish

## Installing Git

### MacOS

1. Open the Terminal app on your Mac
2. Run the command: `brew install git`
3. Wait for the installation process to finish

### Windows

1. Download the Git installer from the official website: https://git-scm.com/download/win
2. Open the installer and follow the instructions on the screen
3. Wait for the installation process to finish
## Cloning a Repository

## Authneticate your GitHub account

The `gh auth` command is used to authenticate with GitHub. This command allows you to configure and manage your GitHub credentials directly from the command line.

To use `gh auth`, follow these steps:

1. Open the Terminal app on your computer
2. Run the command: `gh auth login`
3. Follow the prompts to authenticate with GitHub. You will be asked to provide your GitHub credentials (username and password), and you will need to complete two-factor authentication (if enabled).
4. Choose the `GitHub.com` authentication method
5. Once you have successfully authenticated, you can check your authentication status by running the command: `gh auth status`

You can also use `gh auth` to configure other authentication settings, such as token scopes and expiry. For more information on using `gh auth`, you can run the command: `gh auth --help`.


## To clone a repository from GitHub to your local machine:

1. Open the Terminal app on your computer
2. Navigate to the directory where you want to clone the repository using the `cd` command
3. Run the command: `gh repo clone AnasGamal/turing-text`
4. Wait for the cloning process to finish
## Pushing Changes from Local to Remote Repo

1. Open the Terminal app on your computer
2. Navigate to the local repository directory using the `cd` command
3. Make sure you are on the "evaluate" branch by running the command: `git checkout evaluate`
4. Run the command: `git add .` to stage all the changes
5. Run the command: `git commit -m "commit message"` to commit the changes with a message
6. Run the command: `git push origin evaluate` to push the changes to the remote repository
7. Enter your GitHub credentials when prompted
8. Wait for the changes to be uploaded to the remote repository


## Other Useful Git Commands

Here are some other useful Git commands that you may need to use:

- `git status`: shows the status of your local repository and any changes you have made
- `git pull`: retrieves the latest changes from the remote repository and merges them with your local repository
- `git branch`: shows a list of all branches in your local repository
- `git checkout <branch-name>`: switches to the branch specified by `<branch-name>`
- `git merge <branch-name>`: merges the branch specified by `<branch-name>` with your current branch
- `git remote add <remote-name> <repository-url>`: adds a new remote repository with the specified name and URL
- `git remote -v`: shows a list of all remote repositories connected to your local repository

# Project Overview:

## PROJECT TURING TEXT

The Turing Text project is an SMS text-based application designed to run the Turing Test between ChatGPT (an AI language model) and a human participant. The goal is to evaluate the AI's ability to imitate human-like conversation and determine whether it can be distinguished from a real person.

The project involves multiple roles, including human agents (participants), evaluators (judges), and AI agents (ChatGPT). Human agents and evaluators are paired in the game, while AI agents participate by providing responses. The game proceeds by sending prompts to both human agents and AI agents, and they respond accordingly.

Evaluators compare the responses and generate a result based on the similarity between AI-generated and human-generated responses.

The system uses the Twilio API to enable communication through SMS messages. A delegator class analyzes incoming messages from users, assigns roles as human agents or evaluators, and pairs them for the game. The HelpTool generates prompts and notifies paired participants when they are ready to start the game.

A Game class manages individual game sessions involving a human agent, an evaluator, and an AI agent. The GameBook class keeps track of all game sessions and saves the data for future analysis.

Overall, the project aims to create an engaging, interactive experience where human participants and AI agents can communicate, and evaluators can assess the AI's performance in generating human-like conversation.

Here's a summary of all the classes in the updated UML diagram, their responsibilities, and their relationships:

1. SMSInterface: Handles communication with the Twilio API for sending and receiving messages.
   - Connects to the Twilio API and webhook.
   - Sends and receives messages to/from the Delegator.
2. Player: A superclass for Human and AI participants in the game.
   - Parent class for Human and AI.
3. Human: Represents human participants and stores their phone number.
   - Inherits from Player.
   - Parent class for HumanAgent and Evaluator.
4. AI: Represents AI participants and stores their API token.
   - Inherits from Player.
   - Participates in the Game.
5. HumanAgent: Represents human users who play the game.
   - Inherits from Human.
   - Gets paired with an Evaluator by the Delegator.
   - Participates in the Game.
   - Receives prompts from HelpTool.
6. Evaluator: Represents human users who evaluate the game responses.
   - Inherits from Human.
   - Gets paired with a HumanAgent by the Delegator.
   - Participates in the Game.
   - Compares responses and generates Results.
   - Receives prompts from HelpTool.
7. Results: Stores the evaluation results, including the score and comparison.
   - Generated by the Evaluator.
8. Delegator: Analyzes messages from users, assigns roles, and pairs HumanAgents and Evaluators.
   - Receives messages from SMSInterface.
   - Assigns HumanAgent, Evaluator, and AI to the Game.
   - Keeps track of games in the GameBook.
9. HelpTool: Generates prompts and notifies HumanAgents and Evaluators when they are paired.
   - Generates prompts for HumanAgent and Evaluator.
10. Game: Manages a single game session involving a HumanAgent, an Evaluator, and an AI.
    - Starts and ends the game session.
    - Saves game data to the GameBook.
11. GameBook: Keeps track of all game sessions and saves their data.
    - Adds games to the record.
    - Saves game data.

These classes interact and collaborate to manage the game sessions, handle communication with users, delegate roles, and evaluate game results.

![image](https://user-images.githubusercontent.com/95186419/232374317-fa640684-239f-457b-9f28-5e3b678b75da.png)

![image](https://user-images.githubusercontent.com/95186419/233129714-4eadd00e-4cca-46a3-947a-6aee8691e982.png)

