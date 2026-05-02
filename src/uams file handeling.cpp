Log in

Sign up
You said:
#include<iostream>
#include<windows.h>
#include<conio.h>
#include<unistd.h>
#include<fstream>
using namespace std;
//*********************** Functions ***1***********************
 const int Size=10;
void Header();
void Login_Menu();
void Login_admin();
void Login_Student();
int Admin_Menu();
int Student_Menu();
void Campus();
void Prefrence();
void view();
void View_Fee_Details();

void Signup();
void Add_Student(string Name[Size],int Matric_Marks[Size],int FSC_Marks[Size],int Ecat_Marks[Size]);
void View_Students(string Name[Size],int Matric_Marks[Size],int FSC_Marks[Size],int Ecat_Marks[Size],float Aggre[Size]);
void Aggregate(int Matric_Marks[Size],int FSC_Marks[Size],int Ecat_Marks[Size],float aggregate[Size]);
void Update_Student(string Name[Size],int Matric_Marks[Size],int FSC_Marks[Size],int Ecat_Marks[Size]);
void Del_Student(string Name[Size],int Matric_Marks[Size],int FSC_Marks[Size],int Ecat_Marks[Size],float Aggre[Size]);
//************************** Arrays *************************
string Name[Size];
int Matric_Marks[Size];
int FSC_Marks[Size];
int Ecat_Marks[Size];
float Aggre[Size];
//************************** Variables ***********************
int Login,d,del,Password1,Password2,option,choice;
string Username1,Username2,Pref3,Pref2,Pref1,Camp_1,Camp_2;
char a;
//************************ Main Function **********************
int main(){
while(true){
	Login_Menu();
if(Login==1){
	Login_admin();
	if(Username1=="admin"&& Password1==123){
	cout<<"  			Login Successful";
	sleep(2);
	while(true){
		Admin_Menu();
		if(option==1){
			Add_Student( Name, Matric_Marks, FSC_Marks, Ecat_Marks);}
		if(option==2){
			Aggregate( Matric_Marks, FSC_Marks, Ecat_Marks, Aggre);}
		if(option==3){
			View_Students(Name, Matric_Marks, FSC_Marks, Ecat_Marks, Aggre);}
		if(option==4){
			Update_Student( Name, Matric_Marks, FSC_Marks, Ecat_Marks);}
		if(option==5){
			Del_Student( Name, Matric_Marks, FSC_Marks, Ecat_Marks, Aggre);}
			if(option==6){
			Signup();}
		if(option==7){
			break;}}}
	else {
	cout<<endl;
	cout<<"  			Username Or Password is incorrect\n	please Try Again"<<endl;
	sleep(2);}}
//************************** Student calling ****************************
if(Login==2){
	Login_Student();
	if(Username1==Username2&&Password1==Password2){
		cout<<"  			Login Successful";
		sleep(2);
		while(true){
		Student_Menu();
		if(choice==1){
		Prefrence();}
		if(choice==2){
		Campus();}
		if(choice==3){
		View_Fee_Details();}
		if(choice==4){
		view();}
		if(choice==5){
		break;}}}
	else{
	cout<<endl;
	cout<<"  			Username Or Password is incorrect\n	please Try Again"<<endl; 
	sleep(2);}}
if(Login==3){
	break;}}}
//************************ Header ****************************
void Header(){
	system("cls");
	system("COLOR E0");

  cout << "\033[31m _____       _                      _  _           _____    _         _            _              _____                                            _     " << endl;
    cout << "\033[31m|  |  | ___ |_| _ _  ___  ___  ___ |_|| |_  _ _   |  _  | _| | _____ |_| ___  ___ |_| ___  ___   |     | ___  ___  ___  ___  ___  _____  ___  ___ | |_   " << endl;
    cout << "\033[31m|  |  ||   || || | || -_||  _||_ -|| ||  _|| | |  |     || . ||     || ||_ -||_ -|| || . ||   |  | | | || .'||   || .'|| . || -_||     || -_||   ||  _|  " << endl;
    cout << "\033[31m|_____||_|_||_| \\_/ |___||_|  |___||_||_|  |_  |  |__|__||___||_|_|_||_||___||___||_||___||_|_|  |_|_|_||__,||_|_||__,||_  ||___||_|_|_||___||_|_||_|    " << endl;
    cout << "\033[31m                                           |___|                                                                       |___|                              " << endl;

    // Resetting the color to the default terminal color
    cout << "\033[34m";
cout<<endl;}
//*********************** Login Menu ***********************
void Login_Menu(){
	Header();
	cout<<"  			Select one of the following "<<endl<<endl;
	cout<<"  			1- Login as Admin. "<<endl;
	cout<<"  			2- Login as Student. "<<endl;
	cout<<"  			3- Exit Program. "<<endl;
	cout<<"  			   Your Option : ";
	cin>>Login;}
//************************** Admin Login ********************
void Login_admin(){
	Header();
	cout<<"  			Enter Admin Username : ";
	cin>>Username1;
	cout<<"  			Enter Admin Password : ";
	cin>>Password1;
	cout<<endl;
	}
	 
//************************* Student Login *******************
void Login_Student(){
	Header();
	cout<<"  			Enter Username : ";
	cin>>Username2;
	cout<<"  			Enter Password : ";
	cin>>Password2;
	cout<<endl;
	}
//************************** Admin Menu *********************
int Admin_Menu(){
	Header();
	cout<<"  			Select one of the following "<<endl;
	cout<<"  			1- Add Students. "<<endl;
	cout<<"  			2- Calculate aggegate of Students. "<<endl;
	cout<<"  			3- View All Students."<<endl;
	cout<<"  			4- Update Student Record."<<endl;
	cout<<"  			5- Delete Student Record. "<<endl;
	cout<<"  			6- Add accounts or Password. "<<endl;
	cout<<"  			7- Exit Program. "<<endl;
	cout<<"  			   Your Option : ";
	cin>>option;
	return option;}
//*************************** Student Menu ****************
int Student_Menu(){
	Header();
	cout<<"  			Select one of the following "<<endl<<endl;
	cout<<"  			1- Add your Prefrence. "<<endl;
	cout<<"  			2- Add campus of Student."<<endl;
	cout<<"  			3- View View_Fee_Details of Student. "<<endl;
	cout<<"  			4- View your record"<<endl;
	cout<<"  			5- Exit Program. "<<endl;
	cout<<"  			   Your Option : ";
	cin>>choice;
	return choice;}
//************************* Add Students by admin *******************
void Add_Student(string Name[Size],int Matric_Marks[Size],int FSC_Marks[Size],int Ecat_Marks[Size]){
	Header();
	fstream file;
	file.open("file.txt", ios::out);
	file<<"Sr#    Name   Matric_Marks_Marks    1styear     Ecat_Marks \n";
for(int i=0;i<Size;i++){
	cout<<"  			Enter the Name of "<<i+1<<" Student : ";
	cin>>Name[i];
	file<<i+1<<"\t"<<Name[i]<<"\t";
	cout<<"  			Enter Matric_Marks Marks of "<<i+1<<" Student : ";
	cin>>Matric_Marks[i];
	file<<Matric_Marks[i]<<"\t";
	cout<<"  			Enter 1st Year Marks of "<<i+1<<" Student : ";
	cin>>FSC_Marks[i];
	file<<FSC_Marks[i]<<"\t";
	cout<<"  			Enter Ecat_Marks Marks of "<<i+1<<" Student : ";
	cin>>Ecat_Marks[i];
	file<<Ecat_Marks[i]<<"\n";
	cout<<"  			   Record is saved"<<endl;
	cout<<"  			Press (y) if you want to add a new Student or Press (n) if not : ";
	cin>>a;
	system("cls");
	Header();
	if(a=='n')
	break;}
	file.close();}
//*************************** Aggre by admin ******************
void Aggregate(int Matric_Marks[Size],int FSC_Marks[Size],int Ecat_Marks[Size],float Aggre[Size]){
	Header();
	cout<<"  			Enter Sr# of the Student whose Aggregate you want to calculate : ";
	cin>>d;
	Aggre[d-1]=(Matric_Marks[d-1]/11)*0.25+(FSC_Marks[d-1]/4.13)*0.30+(Ecat_Marks[d-1]/4)*0.45;
	cout<<"  			Aggre is "<<Aggre[d-1]<<endl;
	cout<<"  			Press any key to return to the main Menu :";
    getch();}
//************************** View by admin ************************
void View_Students(string Name[Size],int Matric_Marks[Size],int FSC_Marks[Size],int Ecat_Marks[Size],float Aggre[Size]){
	Header();
	fstream file;
	file.open("file.txt", ios::out);
	cout<<"  Sr#\t\tName \t Matric_Marks\t  FSC_Marks\t Ecat_Marks\t Aggre\n"<<endl;
	file<<"  Sr#\t\tName \t Matric_Marks\t  FSC_Marks\t Ecat_Marks\t Aggre\n"<<endl;
	for(int i=0;i<Size;i++){
	cout<<"   "<<i+1<<"    \t"<<Name[i]<<"   \t  "<<Matric_Marks[i]<<"   \t	"<<FSC_Marks[i]<<"   	\t"<<Ecat_Marks[i]<<"   	\t"<<Aggre[i]<<endl;
	file<<"   "<<i+1<<"    \t"<<Name[i]<<"   \t  "<<Matric_Marks[i]<<"   \t	"<<FSC_Marks[i]<<"   	\t"<<Ecat_Marks[i]<<"   	\t"<<Aggre[i]<<endl;}
	cout<<"  			You Stored This Record. "<<endl<<endl;
    cout<<"  			Press any key to return to the main Menu :";
    getch();
	file.close();}
//********************* Delete Student By admin *********************
void Del_Student(string Name[Size],int Matric_Marks[Size],int FSC_Marks[Size],int Ecat_Marks[Size],float Aggre[Size]){
	Header();
	cout<<"  			Enter sr# of the Student who you want to delete : ";
	cin>>d;
	Name[d-1]="  ",Matric_Marks[d-1]=0,FSC_Marks[d-1]=0,Ecat_Marks[d-1]=0,Aggre[d-1]=0;
	cout<<"  			Data of Student "<<d<<" is deleted."<<endl<<endl;
    cout<<"  			Press any key to return to the main Menu :";
    getch();}
//*************************** campus *******************************
void Campus(){
	Header();
	fstream data;
	data.open("Student.txt", ios::out);
	cout<<"  			Add atleast 2 Campuses of your interest "<<endl;
	cout<<"  			1st campus is ";
	cin>>Camp_1;
	data<<"  			Your campuses are : ";
	data<<Camp_1<<"\t";
	cout<<"  			2nd campus is ";
	cin>>Camp_2;
	data<<Camp_2;
	cout<<"  			Press any key to return to the main Menu :";
    getch();
	data.close();}
//**************************** View_Fee_Details ***************************
void View_Fee_Details(){
	Header();
	fstream data;
	data.open("Student.txt", ios::out);
	cout<<"  			Fee Details of 8 semesters"<<endl;
	cout<<"  		   	  1st semester = 120,000"<<endl;
	cout<<"  			  2nd semester = 100,000"<<endl;
	cout<<"  			  3rd semester = 100,000"<<endl;
	cout<<"  			  4th semester = 95,000"<<endl;
	cout<<"  			  5th semester = 90,000"<<endl;
	cout<<"  			  6th semester = 85,000"<<endl;
	cout<<"  			  7th semester = 80,000"<<endl;
	cout<<"  			  8th semester = 105,000"<<endl;
	data<<" Fee Details of 8 semesters are :"<<endl;
	data<<" 1st semester = 120,000\n 2nd semester = 100,000\n 3rd semester = 100,000"<<endl;
	data<<" 4th semester = 95,000\n 5th semester = 90,000\n 6th semester = 85,000"<<endl;
	data<<" 7th semester = 80,000\n 8th semester = 105,000"<<endl;		
    cout<<"  			Press any key to return to the main Menu :";
    getch();
	data.close();	}
//************************ Pref ***********************
void Prefrence(){
	Header();
	fstream data;
	data.open("Student.txt", ios::out);
	cout<<"  			Choose Prefrence:1_CE , 2_CS , 3_EE"<<endl;
	cout<<"  			Add 3 Prefrence of your interest "<<endl;
	data<<"  			Your Prefrence are : ";
	cout<<"  			1st Prefrence is ";
	cin>>Pref1;
	data<<Pref1<<"\t";
	cout<<"  			2nd Prefrence is ";
	cin>>Pref2;
	data<<Pref2<<"\t";
	cout<<"  			3rd Prefrence is ";
	cin>>Pref3;
	data<<Pref3<<"\n";
    cout<<"  			Press any key to return to the main Menu :";
    getch();
	data.close();}
//************************ view Student record **********************
void view(){
	Header();
	fstream data;
	data.open("Student.txt", ios::out);
	cout<<"  			Choose Campus :1_Main campus , 2_Fsd campus"<<endl;
	cout<<"  			Your campuses are : "<<Camp_1<<" and "<<Camp_2<<endl;
	cout<<"  			Your Pref are : "<<Pref1<<" , "<<Pref2<<" and "<<Pref3<<endl;
	data<<" Your campuses are : "<<Camp_1<<" and "<<Camp_2<<endl;
	data<<" your Prefrence are : "<<Pref1<<" , "<<Pref2<<" and "<<Pref3<<endl;
    cout<<"  			Press any key to return to the main Menu :";
    getch();
	data.close();}
//************************ Update Student record **********************
void Update_Student(string Name[Size],int Matric_Marks[Size],int FSC_Marks[Size],int Ecat_Marks[Size])
{
		Header();
	fstream file;
	file.open("file.txt", ios::out);
	file<<"Sr#    Name   Matric_Marks_Marks    1styear     Ecat_Marks \n";
for(int i=0;i<Size;i++){
	cout<<"  			Enter the Name of "<<i+1<<" Student : ";
	cin>>Name[i];
	file<<i+1<<"\t"<<Name[i]<<"\t";
	cout<<"  			Enter Matric_Marks Marks of "<<i+1<<" Student : ";
	cin>>Matric_Marks[i];
	file<<Matric_Marks[i]<<"\t";
	cout<<"  			Enter 1st Year Marks of "<<i+1<<" Student : ";
	cin>>FSC_Marks[i];
	file<<FSC_Marks[i]<<"\t";
	cout<<"  			Enter Ecat_Marks Marks of "<<i+1<<" Student : ";
	cin>>Ecat_Marks[i];
	file<<Ecat_Marks[i]<<"\n";
	cout<<"  			   Record is updated"<<endl;
	cout<<"  			Press (y) if you want to add a new Student or Press (n) if not : ";
	cin>>a;
	system("cls");
	Header();
	if(a=='n')
	break;}
	file.close();
}

//*************************** sign up ****************************
void Signup()
{
	system("cls");
	Header();
	cout<<"  			Enter Sign up Account for Student";
	cout<<endl;
	cout<<"  			Enter Username : ";
	cin>>Username1;
	cout<<"  			Enter Password : ";
	cin>>Password1;
	cout<<"  			Press any key to return to the main Menu :";
    getch();
} 