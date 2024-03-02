/*Syed Ukkashah Ahmed Shah
  23K-0055
*/
#include<iostream>
#include<cctype>
using namespace std;
class ValidateString{
    string str;
    public:
    ValidateString(string check):str(check){}
    //a function is made const to make sure it never modifies data members in an obj
    bool isValid(string validate) const {
    for (char c : validate) {
        if (!isalpha(c)) { // Check if the character is not an alphabet letter. Defined in the cctype header file
            return false;
    }
}
return true; // If all characters are alphabet letters, return true
}
string get_string () const{
        return str;
    }

};
int main()
{
    ValidateString s1("Ukkashah"), s2("K23-0055");
    cout<<s1.get_string()<<" is "<<(s1.isValid(s1.get_string()) ? "alphabetic" : "not alphabetic")<<endl;
    cout<<s2.get_string()<<" is "<<(s2.isValid(s2.get_string()) ? "alphabetic" : "not alphabetic")<<endl;
    return 0;
}