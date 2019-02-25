/*************************************************************************
* Program:                                                                 
*    Project 8, Mad Lib                                                    
*    Brother Ridges, CS124                                                 
* Author:                                                                  
*    Alexander Berryhill                                                   
* Summary:                                                                 
*    This program will read a Mad Lib off a file then take user input      
*    and display the Mad Lib with user input.                              
*                                                                          
*                                                                          
*                                                                          
*    Estimated:  0.5 hrs                                                   
*    Actual:     0.5 hrs                                                   
*      The most difficult part was                                         
*************************************************************************/

#include <fstream>
#include <locale>
#include <iostream>
using namespace std;

/*************************************************************************
 *                                                                         
 ************************************************************************/
void getFile(char fileName[])
{
   cout << "Please enter the filename of the Mad Lib: ";
   cin >> fileName;
   return;
}

/*************************************************************************
 *                               
 ************************************************************************/
void readFile(char fileName[], char space[][256], char file[][256])
{
   int spaceSpot = 0;
   int fileY = 0;
   int fileX = 0;
   char tempFile [];
   ifstream fin;
   fin.open(fileName);
   if (fin.fail())
   {
      cout << "Failed to open file: " << fileName << endl;
      return;
   }
   fin.getline(tempFile, 256);

   for (int i = 0; tempFile[i] != '\0'; i++)
   {
      if (tempFile[i] == ':')
      {
         if(tempFile[i+1] >= 'a' || tempFile[i + 1] <= 'z')
         {
            char temp[256];
            int place = 0;
            while (tempFile[i] != ' ')
            {
               temp[place];
               place++;
               i++;
            }
            spaceSpot++;
            fileY++;
            fileX = 0;
         }
         else if (tempFile[i + 1] == '!')
         {
            file[fileY][fileX - 1] = '';
            file[fileY][fileX] = '\n';
            fileX++;
            i += 2;
         }
         else if (tempFile[i + 1] == '<')
         {
            file[fileY][fileX] = '\"';
            fileX++;
            i += 2;
         }
         else if (tempFile[i + 1] == '>')
         {
            file[fileY][fileX - 1] = '';
            file[fileY][fileX] = '\"';
            fileX++;
            i++;
         }
         else if (tempFile[i + 1] == '.')
         {
            file[fileY][fileX - 1] = '';
            file[fileY][fileX] = '.';
            fileX++;
            i++;
         }
         else if (tempFile[i + 1] == ',')
         {
            file[fileY][fileX - 1] = '';
            file[fileY][fileX] = ',';
            fileX++;
            i++;
            
         }
      }
      else
      {
         file[fileY][fileX] = tempFile[i];
      }
   }
   fin.close();
   return;
}
/*************************************************************************
 *                                                                         
 ************************************************************************/
void askQuestion(char space[][256], char filledSpace[][256])
{
   char fixedSpace[24][256];
   for (int i = 0; space[i] != '\0'; i++)
   {
      fixedSpace[i][0] = toupper(space[i][0]);
      for (int j = 1; space[i][j] != '\0'; j++)
      {
         if (space[i][j] == '_')
         {
            fixedSpace[i][j] = ' ';
            fixedSpace[i][j + 1] = toupper(space[i][j + 1]);
            j++;
         }
         else
         {
            fixedSpace[i][j] = space[i][j];
         }
  return;
}

/*************************************************************************
 *                                                                         
 ************************************************************************/
void display(char file[][256], char filledSpace[][256])
{
   for (int i = 0; file[i] != '\0'; i++)
   {
      cout << file[i];
      if (filledSpace[i] != '\0')
      {
         cout << filledSpace[i];
      }
   }
   return;
}

/*************************************************************************
 *                                                                         
 *                                                                         
 ************************************************************************/
int main()
{
   char fileName[256];
   char space[24][256];
   char filledSpace[][256]
   char file[24][256];

   getFileName(fileName);
   readFile(fileName, space, file);
   getAnswers(space, filledSpace);
   display(file, filledSpace);
   return 0;
}