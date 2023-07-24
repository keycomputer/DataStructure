
#include <iostream>

using namespace std;
string reverseWord(string str){
    
  //Your code here
   if (str =="")
     return "";
   return (reverseWord(str.substr(1, str.size())) + str[0] );
   
//   or 
//   for(int i=0, j=str.size()-1; i <j ; i++, j--)
//     {
//         char ch = str[i];
//         str[i] = str[j];
//         str[j] = ch;
//     }
}
int main()
{
    string str1 = "abcde";
    
    cout<<reverseWord(str1);
    return 0;
}
