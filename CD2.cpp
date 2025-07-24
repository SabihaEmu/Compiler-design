#include<iostream>
using namespace std;
int main()
{
   string input;
    cout<<"Enter the input(e.g,2+3=5):";
     getline(cin,input);

    int i= 0;
    bool a= false;
    bool b = false;
    while (input[i]!='\0')
        {
            if(input[i]=='+'||input[i]=='-'||input[i]=='*'||
               input[i]=='/'||input[i]=='%'||input[i]=='=')
               {
                   if(!a){
                        cout<<"operator1:"<<input[i]<<endl;
                        a=true;
                        }
                        else if (!b)
                            {
                                cout<<"operator2:"<<input[i]<<endl;
                        b= true;

                        }
               }
               i++;
        }
        if(!a&&!b){
            cout<<"No operators found"<<endl;
        }



    return 0;
}
