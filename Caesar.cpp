#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <sstream>
#include <string>
using namespace std;

void lpp (string msg){
 string imsg = msg;
 const char* E = "echo \"";
 const char* L = "\" | lp  ";
 string total = string(E) + string(imsg) + string(L);
 //cout << total << "\n\n";
 const char* cmd = total.c_str();
 system(cmd);
}

string cipher(string input, string sVal){
//read number associated with the options flag for bit shifting.
stringstream strValue;
strValue << sVal;
int intValue;
strValue >> intValue;
string::iterator it = input.begin();
string msg = "";
for (;it < input.end(); ++it)
    {
     int x = (int)*it - intValue;
     //output the character value shifted over by the number  in argument argv[2]
         if ((x<65) || (x>90))
            x=x+26;
         if ((x > 90)||(x<65))
            msg += " ";
         else
            msg += (char)x;
     }

return msg;
}

int main(int argc, char** argv)
{
    int opt;
    string input = "";
    string usage = "Usage: Caeser -options integer string"
               "\n-a encipher string by the number provided, and print"
               "\n-b encipher string by the number provided "
               "\n-h encipher string by the number provided, and print "
               "\n\t with an alphabet bar for notes" ;

    bool flagA = false;
    bool flagB = false;
    bool flagH = false;
    // Retrieve the (non-option) argument:
    if ((argc <= 3) || (argv[argc-1] == NULL) || (argv[argc-1][0] == '-'))
       cerr << usage << endl;
    else
       input = argv[argc-1];

    // Debug:
    cout << "input = " << input << endl;
    // Shut GetOpt error messages down (return '?'):
    opterr = 0;
    // Retrieve the options:
    while ( (opt = getopt(argc, argv, "abchf")) != -1 ) {  // for each option...
        switch ( opt ) {
            case 'a':
                    flagA = true;
                break;
            case 'b':
                    flagB = true;
                break;
            case 'h':
					flagH = true;
                break;
            case 'c':
					cout << "Cracking Cipher not implemented yet\n\n";

            case 'f':
					cout << "encipher file... not implemented yet\n\n";
                break;
            case '?':  // unknown option...
                    cerr << "Unknown option: '" << char(optopt) << "'!" << "\n\n" << usage << endl;
                break;
        }
    }

string sVal = argv[2];
string msg = cipher(input, sVal);

         if (flagA == true)
            {
             lpp(msg);
		     cout << msg << "\n";
		    }

         if (flagB == true)
             cout << msg << "\n";

         if (flagH == true)
			 {
				 cout << msg << "\n";
				 string hlp = "\n\n A  B  C  D  E  F  G  H  I  J  K  L  M  N  O  P  Q  R  S  T  U  V  W  X  Y  Z";
				 msg+= hlp;
				 lpp(msg);
			 }

 cout << endl;
return 0;
}
