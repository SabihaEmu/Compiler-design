# include <iostream>
using namespace std;
int main()
{
    string a;
    bool isNumeric = true;
    cout<< "Enter input:";
    cin>>a;
    for(int i = 0;a[i]!='\0';i++)
    {
        if(a[i]<'0'||a[i]>'9')
        {
            isNumeric = false;
            break;


        }

    }
    if(isNumeric&&a.length()>0)
        {
            cout<<"This is a numeric constant."<<endl;

        }
    else{
        cout<<"This is not numeric."<<endl;
    }





    return 0;
}
