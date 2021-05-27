#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib> 
#include "LinkedList.h"
using namespace std;

void print_qna()
{
    string Name;
    string salary;
    string response1,response2;
    cout<<"***************************************************************************************\n\n";

    cout<<"Please answer the following four questions and I will determine the place you should travel.\n\n";
    cout<<"\t\t1. What is your full name?\t\t";
    getline(cin,Name);

    bool flag=true;
    while(true){

        cout<<"\n\t\t2. How much money do you make per year?\t";
        getline(cin,salary,'\n');
        bool flag=false;

        for(int i=0;i<salary.size();i++)
        {
            if(salary[i]>='0' && salary[i]<='9')continue;
            else {
                flag = true;
                break;
            }
    
        }
        if(flag==true)
        {
            cout<<"\nOops! You entered something wonky. Please enter a number with no symbols or commas.\n";
        }
        else break;
    }
    while(true){
        cout<<"\n\t\t3. Are you a fan of fiction books? (y or n)\t";
        getline(cin,response1,'\n');

        if(response1=="y" || response1=="n") break;

        else cout<<"Oops! You entered something wonky. Please enter a number with no symbols or commas.\n"; 
    }

    while(true){
    cout<<"\n\t\t4. Do you love adventure? (y or n)\t";
    getline(cin,response2,'\n');

        if(response2=="y" || response2=="n") break;

        else cout<<"Oops! You entered something wonky. Please enter a number with no symbols or commas.\n"; 
    }

    cout<<"\n"<<Name<<", based on your salary ($"<<salary<<") and the fact that ";
    if(response1=="y") cout<<"you are a fan of fiction and ";
    else cout<<"you are not a fan of fiction and ";

    if(response1=="y") cout<<"you love adventure ";
    else cout<<"you hate adventure ";

    cout<<"you are going to travel to the followinng Destination!\n\n";




}
int main()
{
    ifstream fptr;
    fptr.open("placeFile.txt");
    
    LinkedList<Destination> L;

    string name,des,cost,danger;
    float Cost;
    int Danger;

    while(getline(fptr,name,'#'))
    {
        getline(fptr,des,'#');
        getline(fptr,cost,'#');
        getline(fptr,danger,'#');

        stringstream C(cost);
        stringstream D(danger);
        C>>Cost;
        D>>danger;

        Destination Temp(name,des,Cost,Danger);

        L.insertNode(Temp); 
    } 
    fptr.close();

    cout<<"\nHello! My name is Gavin O Cleirigh and I am your professional travel agent, tour director and guide!\n"<<endl;

    cout<<"#############################################################"<<endl;
	cout<<"#                    _                                      #"<<endl;  
	cout<<"#                  -=\\`\\                                    #"<<endl;  
	cout<<"#              |\\ ____\\_\\__                                 #"<<endl;  
	cout<<"#            -=\\c`\"\"\"\"\"\"\" \"`)                               #"<<endl;  
	cout<<"#               `~~~~~/ /~~`\\                               #"<<endl;  
	cout<<"#                 -==/ /                                    #"<<endl;  
	cout<<"#                   '-'                                     #"<<endl;  
	cout<<"#                  _  _                                     #"<<endl;  
	cout<<"#                 ( `   )_                                  #"<<endl;  
	cout<<"#                (    )    `)                               #"<<endl;  
	cout<<"#              (_   (_ .  _) _)                             #"<<endl;  
	cout<<"#                                             _             #"<<endl;  
	cout<<"#                                            (  )           #"<<endl;  
	cout<<"#             _ .                         ( `  ) . )        #"<<endl;  
	cout<<"#           (  _ )_                      (_, _(  ,_)_)      #"<<endl;  
	cout<<"#         (_  _(_ ,)                                        #"<<endl;  
	cout<<"#############################################################"<<endl;

    cout<<"\nBelow are all the possible travel destinations that I can hook you up with:\n\n";
    for(int i=0;i< L.getLength();i++)
    {
        cout<<"**********DESTINATION #"<<i+1<<"*********"<<endl;
        cout<<L.getNodeValue(i)<<endl;;
    }

    print_qna();

    srand(time(0));
    cout<<L.getNodeValue(rand()%L.getLength());

 

    return 0;
}