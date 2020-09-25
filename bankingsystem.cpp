#include<bits/stdc++.h>
#include<Windows.h>
using namespace std;
class BANK{
    char accountholdername[20];
    long int accountnumber;
    int totalbalance;
public:
    int deposit;
    int withdraw;
    int ac;
    char enteredpassword[20];
    char enteredusername[20];
    char username[20];
    char password[20];
    void enterdata();
    void enter();
    void showdata();
    void write();
    void read();
    void update();
    void Delete();
    void Search(int);
    void check();
    void withdrawl();
    void Deposit();
}B;
    int Count=0;
    char ch;
void BANK::enterdata(){
    cout<<"ENTER THE NAME OF ACCOUNT HOLDER\n";
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    gets(accountholdername);
    cout<<"ENTER THE ACCOUNT NUMBER\n";
    cin>>accountnumber;
    cout<<"ENTER YOUR TOTAL BALANCE\n";
    cin>>totalbalance;
    cout<<"ENTER YOUR USERNAME\n";
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    gets(username);
    cout<<"ENTER YOUR PASSWORD\n";
    gets(password);
}
void BANK::showdata(){
    cout<<"ACCOUNT HOLDER:"<<accountholdername<<endl;
    cout<<"ACCOUNT NUMBER:"<<accountnumber<<endl;
    cout<<"TOTAL BALANCE:"<<totalbalance<<endl;
}
void BANK::write(){
     ofstream outfile;
    outfile.open("record.dat",ios::binary|ios::app);
    enterdata();
    outfile.write((char*)&B,sizeof(BANK));
    for(int i=0;i<20;i++){
    enteredpassword[i]=password[i];
    }
    for(int i=0;i<20;i++){
    enteredusername[i]=username[i];
    }
    outfile.close();

}
void BANK::check()
{
    cout<<"REENTER THE USERNAME AND PASSWORD FOR CONFIRMATION\n";
    cout<<"ENTER YOUR USERNAME\n";
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    gets(username);
    cout<<"ENTER YOUR PASSWORD\n";
    gets(password);
    ofstream outfile;
    outfile.open("record.dat",ios::binary|ios::app);
    while(!outfile.eof()){
    if(strcmp(enteredpassword,B.password)==0 && strcmp(enteredusername,B.username)==0)
    {
        cout<<"ACCESS GRANTED";
        break;
        Count++;
    }
    else
    {
        cout<<"your username or password is wrong\n";
        break;
    }
    }
}
void BANK::read(){
    ifstream infile;
    infile.open("record.dat",ios::binary);
    if(!infile)
    {
        cout<<"ERROR IN OPENING FILE\n";
        return;
    }
    cout<<"DATA YOU HAVE ENTERED\n";
    while(!infile.eof())
    {
        if(infile.read((char*)&B,sizeof(BANK)))
        {
             showdata();
        }
    }
   infile.close();
}
void BANK::Deposit()
{
    check();
    cout<<"\nENTER THE AMOUNT YOU WANT TO DEPOSIT\n";
    cin>>deposit;
    totalbalance+=deposit;
    cout<<"\nAMOUNT DEPOSITED:"<<deposit<<"\nYOUR TOTAL BALANCE:"<<totalbalance;
}
void BANK::withdrawl()
{   check();
    cout<<"\nENTER THE AMOUNT YOU WANT TO WITHDRAW\n";
    cin>>withdraw;
    totalbalance-=withdraw;
    cout<<"AMOUNT WITHDRAWN:"<<withdraw<<"\nYOUR TOTAL BALANCE:"<<totalbalance;
}
void BANK::Search(int ac){
   cout<<"ENTER THE ACCOUNT NUMBER<<endl";
   cin>>ac;
   if(accountnumber==ac) 
   cout<<"SEARCH SUCCESSFUL YOUR ACCOUNT WAS FOUND<<endl";
    else
    cout<<"SEARCH FAILED";
} 
int main(){
    cout<<"                ###     #     #     #   #   #   #  #     #   #####          #     #     #     #     #    #     #####  #####  #     #  ######  #     #  ########"<<endl;
 Sleep(500);
    cout<<"                #  #   #  #   ##    #   #  #    #  ##    #   #   #          ##   ##    #  #   ##    #   #  #   #   #  #      ##   ##  #       ##    #     #"<<endl;
 Sleep(500);
    cout<<"                #  #  #    #  # #   #   # #     #  # #   #   #              # # # #   #    #  # #   #  #    #  #      #      # # # #  #       # #   #     #"<<endl;
 Sleep(500);
    cout<<"                ###   ######  #  #  #   ##      #  #  #  #   #              #  #  #   ######  #  #  #  ######  #      ####   #  #  #  ####    #  #  #     #"<<endl;
 Sleep(500);
    cout<<"                #  #  #    #  #   # #   # #     #  #   # #   #  ##          #     #   #    #  #   # #  #    #  #  ##  #      #     #  #       #   # #     #"<<endl;
 Sleep(500);
    cout<<"                #  #  #    #  #    ##   #  #    #  #    ##   #   #          #     #   #    #  #    ##  #    #  #   #  #      #     #  #       #    ##     #"<<endl;
 Sleep(500);
    cout<<"                # #   #    #  #     #   #   #   #  #     #   #####          #     #   #    #  #     #  #    #  #####  #####  #     #  ######  #     #     #"<<endl;
 Sleep(500);
    cout<<"                                                          #######   #     #   ######  #######  ######  #      #"<<endl;
 Sleep(500);
    cout<<"                                                          #          #   #    #          #     #       # #   ##"<<endl;
 Sleep(500);
    cout<<"                                                          #           # #     #          #     #       #  # # #"<<endl;
 Sleep(500);
    cout<<"                                                          #######      #      ######     #     ####    #   #  #"<<endl;
 Sleep(500);
    cout<<"                                                                #      #           #     #     #       #      #"<<endl;
 Sleep(500);
    cout<<"                                                                #      #           #     #     #       #      #"<<endl;
 Sleep(500);
    cout<<"                                                          #######      #      ######     #     ######  #      #"<<endl;
 Sleep(500);
    a: cout<<"\n\n\n\n\n\t\t\t\t\t\t\t\tWELCOME TO BANKING MANAGEMENT SYSTEM\n\t\t\t\t\t\t\t\tPRESS 1 FOR ENTERING DATA\n\t\t\t\t\t\t\t\tPRESS 2 FOR SHOWING ENTERED DATA\n\t\t\t\t\t\t\t\tPRESS 3 FOR UPDATING DATA\n\t\t\t\t\t\t\t\tPRESS 4 FOR DEPOSITING MONEY\n\t\t\t\t\t\t\t\tPRESS 5 FOR WITHDRAWLING MONEY\n\t\t\t\t\t\t\t\tPRESS 6 FOR EXIT\n\t\t\t\t\t\t\t\t";
    do{
    int n, ac;
    cin>>n;
    switch(n){
    case 1:
        B.write();
        break;
    case 2:
        B.check();
        break;
    case 3:
        B.read();
         break;
    case 4:
        B.withdrawl();
         break;
    case 5:
        B.Deposit();
         break;
    case 6:
        exit(0);
        break;
    default:
        cout<<"WRONG INPUT";
    }
        cout<<"\nWANNA CHECK MORE:";
        cin>>ch;

    }while(ch=='y'||ch=='Y');
    return 0;
}
