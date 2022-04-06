#include<string.h>
#include<iostream>
#include<fstream>
#include<conio.h>
using namespace std;
class Parking //Class to operate on Parking management
{
private: //Private data members which are not accessable outside class
int total2w,total4w,type,ccount,bcount;
double cost2w,cost4w;
char vno[15],date[9],time[9],t[15];
void TokenOutput() //Private function to print the vehicle details on output screen
{
if(type==2)
cout<<t<<"\t"<<vno<<"\t"<<date<<"\t"<<time<<"\t"<<cost2w<<endl;
else
cout<<t<<"\t"<<vno<<"\t"<<date<<"\t"<<time<<"\t"<<cost4w<<endl;

}

public:
Parking(int t2, int t4, double c2, double c4) //constructor to initialize values to the variables
{
total2w=t2;
total4w=t4;
cost2w=c2;
cost4w=c4;
type=0;
strcpy(date,"-");
strcpy(time,"-");
strcpy(vno,"-");
ccount=bcount=0;
}


void TokenInput() //Function to take all the vehicle details from the user
{
cout<<"Enter 2 for 2 wheeler \nEnter 4 for 4 wheeler: "<<endl;
cin>>type;
if(type==2 && bcount>=total2w) //condition when 2 wheeler parking is full
cout<<"Sorry! 2 wheeler parking full...";
else if(type==4 && ccount>=total4w) //condition when 4 wheeler parking is full
cout<<"Sorry! 4 wheeler parking full...";

else if(type == 2 || type == 4) //when there is space available in the parking
{
cout<<"Enter vehicle number: ";
fflush(stdin);
gets(vno);
cout<<"Enter entry date in dd/mm/yy formate: ";
fflush(stdin);
gets(date);
cout<<"Enter entry time: ";
fflush(stdin);
gets(time);
cout<<"Vehilce Type\tVehicle No.\tEntry Date\tEntry Time\tParking cost"<<endl;
cout<<"__________________________"<<endl;
if(type==2)
{
strcpy(t,"2 wheeler");
bcount++;
TokenOutput();
}
else
{
strcpy(t,"4 wheeler");
ccount++;
TokenOutput();
}
addtofile();
}
else
cout<<"Wrong Choice!!!"<<endl;
}



void Exit() //Function to remove vehicle from parking
{
cout<<"Enter type of vehicle:\n2 for 2 wheeler\n4 for 4 wheeler: ";
cin>>type;
if(type==2)
bcount--;
else
ccount--;
cout<<"One "<<type<<" wheeler exit successfully."<<endl;
}




void SpaceAvailable() //Function to inform the user about space available in parking
{
cout<<endl<<"Space available in 2 wheeler is : ";
cout<<(total2w-bcount);
cout<<endl<<"Space available in 4 wheeler is : ";
cout<<(total4w-ccount);
}
void creatfile();
void addtofile();
void readfile();
};
void Parking::creatfile() //Function to create a folder to store vehicle details
{
ofstream W;
W.open("VehicleData.txt"); /*Simply opening and closing the file so that all
the data previously stored gets deleted*/
bcount=ccount=0;
W.close();
}

void Parking::addtofile() /*Function to store the vehicle details in a file so
that the details don't get deleted after the program ends*/
{
ofstream W;
W.open("VehicleData.txt",ios::app); //Opening file in append mode
W.write((char*)this,sizeof(*this)); //Writting all the details of vehicle in the file
W.close(); //Closing the file
cout<<"\nRecord Added Successfully"<<endl;
}

void Parking::readfile() //Function to read the vehicle details stored in file
{
int c=0;
ifstream R;
R.open("VehicleData.txt",ios::in); //Opening file in read mode
if(R.fail()) //Check if file fails to open
cout<<"File not found!"<<endl;
else //If file opens succeccfully
{
R.read((char*)this,sizeof(*this)); //Reading the first line of file
while(!R.eof()) //Loop to read and present all the vehicle details stored in file
{
TokenOutput();
c++;
R.read((char*)this,sizeof(*this));
}
if(c==0)
cout<<"File is empty..."<<endl;
}
R.close(); //Closing of file
}

int main() //Driver Function
{
int choice,t2,t4,c2,c4;
cout << "*Parking Managment System*" << endl;
cout << "Presented by :" << endl;
cout << "Shreya Singh(Roll No-1913636)" << endl;
cout << "Shivani Singh Rathore(Roll No-1913632)" << endl;
cout << "-------------------------" << endl;
    cout<<"Enter total space available:\nFor 2 wheeler: ";
    cin>>t2;
    cout<<"For 4 wheeler: ";
    cin>>t4;
    cout<<"Enter parking cost: \nFor 2 wheeler: ";
    cin>>c2;
    cout<<"For 4 wheeler: ";
    cin>>c4;
    Parking P(t2,t4,c2,c4);
    do
    {
       system("cls");
       cout << "-----MENU-----" << endl;
       cout << "1. Create new file " << endl;
       cout << "2. VehicleInput " << endl;
       cout << "3. DisplayList" << endl;
       cout << "4. SpaceAvailability" << endl;
       cout << "5. VehicleExit" << endl;
       cout << "6. DeleteList" << endl;
       cout << "7. Exit" << endl;
       cout << "Enter your choice : ";
       cin >> choice;    
    switch(choice)
      {
case 1:
  P.creatfile();
  cout<<"New File Created!"<<endl;
  getch();
break;
case 2:
        P.TokenInput();
    getch();
       break;
        case 3:
cout<<"Vehilce Type\tVehicle No.\tEntry Date\tEntry Time\tParking cost"<<endl;
cout<<"__________________________"<<endl;
P.readfile();
getch();
break;
        case 4:  
  P.SpaceAvailable();
        getch();
        break;
case 5:  
        P.Exit();
        getch();
        break;
        case 6:
P.creatfile();
cout<<"List Deleted!"<<endl;
getch();
        break;
        case 7:  
        cout << "Exit....!" << endl;
        break;
        default:
        cout << "Invalid choice!" << endl;
        getch();
}
  }while(choice!=7);
  return 0;
}
