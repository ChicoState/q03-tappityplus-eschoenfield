#include "tappity.h"
#include <string>
using namespace std;

/**
 * Class for tappity
**/

//Constructor sets the reference phrase
tappity::tappity(std::string reference)
{
  ref=reference;
  inp="";
}

//Provide the input to be compared to the reference. Before this 
//function is called, the input should be considered an empty string
void tappity::entry(std::string input)
{
  inp=input;
}

//Compares the length of the reference to that of the input and
//returns the absolute value of the difference, or 0 if they are the
//same length
int tappity::length_difference()
{
  int r = ref.length();
  int i = inp.length();
  if(r==i){
    return 0;
  }
  else{
    int dif=0;
    if(r>i){
      dif=r-i;
    }
    else{
      dif=i-r;
    }
    return dif;
  }
}

//Compares the content of the reference to that of the input and
//calculates the accuracy of matching characters. If the two strings
//are identical, accuracy should be 100. However, for each 
//corresponding character that does not match in the same location,
//the percentage of corresponding characters should be returned.
//For example, if the reference and input have 10 letters and the input
//matches 8 of the corresponding reference characters, the function 
//should return 80. When input does not have the same number of
//characters as the reference, the accuracy should represent the percent
//of matching characters between the shorter and   longer strings. For
//example, if one string has 8 characters matching the corresponding
//locations in another string that has 16 characters, the accuracy is 50.
double tappity::accuracy()
{
  if(ref==inp){
    return 100.0;
  }
  if((ref.length()==0) || (inp.length()==0)){
    return 0.0;
  }
  double max=0.0;
  int min=0;
  int perc=0;
  if(ref.length() > inp.length()){
    max=ref.length();
    min=inp.length();
  }
  else{
    max=inp.length();
    min=ref.length();
  }
  for(int i=0; i<min; i++){
    if(ref[i]==inp[i]){
      perc+=1;
    }
  }
  double final = (perc/max)*100;
  return final;
  // else{
  //   for(int i=0; i<ref.length(); i++){
  //     if(ref[i]!=inp[i])
  //   }
  //   return -(perc/ref.length());
  // }
  // return 0;
}
