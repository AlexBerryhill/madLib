/*************************************************************************
* Program:                                                                 
*    Project 10, Mad Lib                                                   
*    Brother Ridges, CS124                                                 
* Author:                                                                  
*    Alexander Berryhill                                                   
* Summary:                                                                 
*    This program will read a Mad Lib off a file then take user input      
*    and display the Mad Lib with user input.                              
*                                                                          
*                                                                          
*                                                                          
*    Estimated:  3.5 hrs                                                   
*    Actual:     13.5 hrs                                                  
*      The most difficult part was getting askQuestion to work.            
*************************************************************************/

#include <cassert>
#include <fstream>
#include <locale>
#include <iostream>
using namespace std;

/*************************************************************************
 * getFile will prompt and get a fileName from the user.                   
 ************************************************************************/
void getFile(char fileName[])
{
   cout << "Please enter the filename of the Mad Lib: ";//prompt           
   cin >> fileName;                   //GET                                
   cin.ignore(256, '\n');             // avoid later problems      
   return;
}

/*************************************************************************
 * empty will empty an array by filling it with null                       
 ************************************************************************/
void empty(char array[])
{
   for (int i = 0; i < 256; i++)//fill the array with null                 
   {
      array[i] = '\0';        //for emptying the space[] and tempSpace[]   
   }
   return;                    //used in interpret before askQuestion       
}

/*************************************************************************
 * removeNonsense will remove the stuff I have spent hours trying to find  
 * the source of but can not.                                              
 ************************************************************************/
void removeNonsense(char file[])
{
   int rNOffset = 0;
   for (int i = 0; file[i]; i++)
   {
      if (!(file[i] >= 1 && file[i] <= 'z'))//not null, but still not good
      {
         if (file[i - 1] != '\n')
            file[i - 1 - rNOffset] = '\0';
         file[i - rNOffset] = '\0';
      }
      else if (file[i] == ' ' && file[i - 1] == ' ')//double spaces        
      {
        file[i - ++rNOffset] = file[i];
      }
      else if (file[i] == ' ' && !(file[i + 1] >= 1 &&
                                   file[i + 1] <= 'z'))
      {
         file[i - rNOffset] = '\0';//spaces before the end of file.        
      }
      else
         file[i - rNOffset] = file[i];//everything else                    
   }
   return;
}

/*************************************************************************
 * askQuestion will ask a question found by interpret.                     
 ************************************************************************/
void askQuestion(char tempSpace[], char space[])
{
   char first = toupper(tempSpace[0]); //capitalize first letter into char
   cout << "\t" << first;             //tab before question + first letter
   for (int i = 1; tempSpace[i] != '\0'; i++)
   {
      if (tempSpace[i] == '_')         //turn _ into a space               
      {
         cout << " ";
      }
      else if (tempSpace[i] == toupper(tempSpace[i]))
      {
         char temp = tolower(tempSpace[i]);//everything else lower         
         cout << temp;
      }
      else                             //everything else   
  {
               cout << tempSpace[i];
      }
   }
   cout << ": ";                       //: and a space                     
   cin.get(space, 32);                 //get space                         
   cin.ignore(256, '\n');              //clear                             
   return;
}

/*************************************************************************
 * interpret will interpret any colons found in the file.                  
 ************************************************************************/
void interpret(char tempFile[], char file[], int &i, int &offset)
{
   switch (tempFile[i + 1])
   {
      case '\0': //Catch if after : is null                                
         cout << "invalid: " << tempFile[i + 1] << endl;
         break;
      case '!'://new line                                                  
         file[i - ++offset] = '\n';
         i += 2;
         offset += 2;
         if (tempFile[i + 2] == '!')
         {
            i++;
            file[i - offset] = '\n';
            i += 2;
            offset += 2;
         }
         break;
      case '<'://open quote                                    