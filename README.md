# LeetCode Problems

This repository is intended to document the LeetCode questions on algorithms and data structures in modern C++.

## How to get setup?

- [Download Visual Studio Code](https://code.visualstudio.com/download)
- [Install Docker](https://docs.docker.com/get-docker/)
- Open the project in the root folder with VSCode.
- Click on the left down corner symbol "><"
- Then click on reopen in container (This will take care of building the Docker container)
- Note for using this withing PowerShell one needs to disable `git config --global core.autocrlf input` [Error while running Docker code in PowerShell](https://forums.docker.com/t/error-while-running-docker-code-in-powershell/34059/8)

## How to add a new problem?

- Create a directory with the number of the problem and the name, remove special characters replace spaces with "_"
   eg: 13. Roman to Integer resolves in 13_Roman_to_Integer
- When submitting a problem a create the cpp file in a way that you just need to copy the class for submitting eg:

   ```cpp
     class Solution
     {
     public:
       void leetCodeFunction()
       {
         // Code goes here;
       }
     }
   ```

## License

[MIT](https://choosealicense.com/licenses/mit/)
