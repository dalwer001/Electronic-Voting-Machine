#include<bits/stdc++.h>
#include<fstream>
#include<cctype>
#include<iomanip>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<conio.h>
#include<dos.h>
#include<windows.h>

using namespace std;


class candidates_record
{
public:
    int candidate_namecode ;
    char candidatename[50];
    char partyname[50];
    int Income;
    int age;
    char area[50];
    char name[50];
    int password;
    void candidate_Information();
    int return_id() const;
    int show_account() const;

}; candidates_record cr;

class voters_record
{
public:
    int voters_namecode ;
    char votername[50];
    int age;
    char area[50];
    char name[50];
    char gender[50];
    int password;
    void voters_Information();
    int return_id1() const;
    int show_account1() const;

}; voters_record vr;



int candidates_record::return_id() const
{
    //return name;
	return password;
}




int candidates_record::show_account() const
{
    cout<<"Name|"<<setw(15)<<"Party name|"<<setw(15)<<"Income|"<<setw(15)<<"Age|"<<setw(15)<<"Area"<<endl;
    cout<<name<<setw(15)<<partyname<<setw(15)<<Income<<setw(15)<<age<<setw(15)<<area<<endl;
}


int voters_record::return_id1() const
{
    //return name;
	return password;
}

int voters_record::show_account1() const
{
    cout<<"Name|"<<setw(15)<<"Age|"<<setw(15)<<"Area|"<<setw(15)<<"Gender"<<endl;
    cout<<name<<setw(15)<<age<<setw(15)<<area<<setw(15)<<gender<<endl;
}








void candidates_record::candidate_Information()
{   system("Cls");
    cout<<"Enter candidate Name:";
    cin>>name;
    cout<<"Enter Candidate name code:";
    cin>>password;
    if(password==12345)
    {
        cout<<"Not valid\n";
        system("Pause");
        cin.get();
        candidate_Information();
    }
    else
    {
        cout<<"Got to next";
    }
system("Cls");
    cout<<"Enter the candidate name:";
    cin.ignore();
    cin.getline(name,50);
    cout<<"Enter the candidate party name :";
    cin.getline(partyname,50);
    cout<<"Enter the candidate income:";
    cin>>Income;
    if(Income>=50000)
    {
        cout<<"valid\n";
        cout<<"Go to next\n";
    }
    else
    {
        cout<<"not valid";
        system("Pause");
        cin.get();
        candidate_Information();
    }
    cout<<"Enter the candidate age:";
    cin>>age;
    if(age>=35)
    {
        cout<<"Valid\n";
    }
    else
    {
        cout<<"Not Valid";
        system("Pause");
        cin.get();
        candidate_Information();
    }
    cout<<"Enter the candidate area:";
    cin>>area;



    cout<<"Thank You.\nPress Enter to go back to main page."<<endl;
    cin.get();
    Sleep(1500);

}



void voters_record::voters_Information()
{   system("Cls");
    cout<<"Enter voters Name:";
    cin>>name;
    cout<<"Enter  voters name code:";
    cin>>password;
    system("Cls");


    cout<<"Enter the Voters name:";
    cin.ignore();
    cin.getline(name,50);
    cout<<"Enter the candidate age:";
    cin>>age;
    if(age>=18)
    {
        cout<<"valid \n";
    }
    else
    {
        cout<<"Not valid";
        system("Pause");
        cin.get();
        voters_Information();
    }
    cout<<"Enter the candidate area:";
    cin>>area;
    cout<<"Enter Gender";
    cin>>gender;


    cout<<"Thank You.\nPress Enter to go back to main page."<<endl;
    cin.get();
    Sleep(1500);

}








void Delete_candidate_information(int n)
{
	candidates_record cr;
	ifstream inFile;
	ofstream outFile;
	inFile.open("candidate information.txt",ios::binary);
	if(!inFile)
	{
		cout<<"\n\n\tFile could not be open !! Press any Key...";
	}
	outFile.open("Temp.txt",ios::binary);
	inFile.seekg(0,ios::beg);
	while(inFile.read(reinterpret_cast<char *>(&cr), sizeof(candidates_record)))
	{
		if(cr.return_id()!=n)
		{
			outFile.write(reinterpret_cast<char *>(&cr), sizeof(candidates_record));
		}
	}
	inFile.close();
	outFile.close();
	remove("candidate information.txt");
	rename("Temp.txt","candidate information.txt");
	cout<<"\n\n\tRecord Deleted ..";
    cout<<"\n\nPress Enter To Return Main Menu.";
}


void Delete_voters_information(int n)
{
	voters_record vr;
	ifstream inFile;
	ofstream outFile;
	inFile.open("voters information.txt",ios::binary);
	if(!inFile)
	{
		cout<<"\n\n\tFile could not be open !! Press any Key...";
	}
	outFile.open("Temp1.txt",ios::binary);
	inFile.seekg(0,ios::beg);
	while(inFile.read(reinterpret_cast<char *>(&vr), sizeof(voters_record)))
	{
		if(vr.return_id1()!=n)
		{
			outFile.write(reinterpret_cast<char *>(&vr), sizeof(voters_record));
		}
	}
	inFile.close();
	outFile.close();
	remove("voters information.txt");
	rename("Temp1.txt","voters information.txt");
	cout<<"\n\n\tRecord Deleted ..";
    cout<<"\n\nPress Enter To Return Main Menu.";
}








void Edit_candidate_information(int n)
{
	bool found=false;
	candidates_record cr;
	fstream File;
	File.open("candidate information.txt",ios::binary|ios::in|ios::out);
	if(!File)
	{
		cout<<"\n\n\tFile could not be open !! Press any Key...";
		return;
	}
	while(!File.eof() && found==false)
	{
		File.read(reinterpret_cast<char *> (&cr), sizeof(candidates_record));
		if(cr.return_id()==n)
		{
			cr.candidate_Information();
			cout<<"\n\n\tEnter The New Details of account"<<endl;
			cr.candidate_Information();
			int pos=(-1)*static_cast<int>(sizeof(candidates_record));
			File.seekp(pos,ios::cur);
			File.write(reinterpret_cast<char *> (&cr), sizeof(candidates_record));
			cout<<"\n\n\t Record Updated";
			cout<<"\n\n\tPress Enter To Return Main Menu.";
			found=true;
		  }
	}
	File.close();
	if(found==false)
		cout<<"\n\n\t Record Not Found ";
}





void Edit_voters_information(int n)
{
	bool found=false;
	voters_record vr;
	fstream File;
	File.open("voters information.txt",ios::binary|ios::in|ios::out);
	if(!File)
	{
		cout<<"\n\n\tFile could not be open !! Press any Key...";
		return;
	}
	while(!File.eof() && found==false)
	{
		File.read(reinterpret_cast<char *> (&vr),sizeof(voters_record));
		if(vr.return_id1()==n)
		{
			vr.voters_Information();
			cout<<"\n\n\tEnter The New Details of account"<<endl;
			vr.voters_Information();
			int pos=(-1)*static_cast<int>(sizeof(voters_record));
			File.seekp(pos,ios::cur);
			File.write(reinterpret_cast<char *> (&vr), sizeof(voters_record));
			cout<<"\n\n\t Record Updated";
			cout<<"\n\n\tPress Enter To Return Main Menu.";
			found=true;
		  }
	}
	File.close();
	if(found==false)
		cout<<"\n\n\t Record Not Found ";
}







void Show_all_candidate_information()
{
	candidates_record cr;
	ifstream inFile;
	inFile.open("candidate information.txt",ios::binary);
	if(!inFile)
	{
		cout<<"\n\n\tFile could not be open !! Press any Key...";
	}
	cout<<"\t\t\t\tALL ACCOUNT HOLDER LIST\n\n";


	while(inFile.read(reinterpret_cast<char *> (&cr), sizeof(candidates_record)))
	{
		cr.show_account();

	}
	inFile.close();
}




void Show_all_voters_information()
{
	voters_record vr;
	ifstream inFile;
	inFile.open("voters information.txt",ios::binary);
	if(!inFile)
	{
		cout<<"\n\n\tFile could not be open !! Press any Key...";
	}
	cout<<"\t\t\t\tALL ACCOUNT HOLDER LIST\n\n";


	while(inFile.read(reinterpret_cast<char *> (&vr), sizeof(voters_record)))
	{
		vr.show_account1();
	}
	inFile.close();
}











void write_account()
{
    candidates_record cr;
	ofstream outFile;
	outFile.open("candidate information.txt",ios::binary|ios::app);
	cr.candidate_Information();
	outFile.write(reinterpret_cast<char *> (&cr), sizeof(candidates_record));
	outFile.close();

}



void write_account1()
{
    voters_record vr;
	ofstream outFile;
	outFile.open("voters information.txt",ios::binary|ios::app);
	vr.voters_Information();
	outFile.write(reinterpret_cast<char *> (&vr), sizeof(voters_record));
	outFile.close();

}

void logo_show()
{
system("color 0b");
   cout<<"\n\t\t                  ______          ";
   cout<<"\n\t\t                 |_    _|             ";
   cout<<"\n\t\t    *------*       |  |       *------*";
   cout<<"\n\t\t    *-*  *-*       |  |       *-*  *-*";
   cout<<"\n\t\t      *  *    _____|__|_____    *  *       ";
   cout<<"\n\t\t      *  *   |  ___    ___  |   *  *       ";
   cout<<"\n\t\t      *  *   |_|   |  |   |_|   *  *       ";
   cout<<"\n\t\t      *  *       B |  | A       *  *       ";
   cout<<"\n\t\t      *  *        _|  |_        *  *       ";
   cout<<"\n\t\t      *  *       |______|       *  *       ";
   cout<<"\n\t\t      *  *_________|  |_________*  *       ";
   cout<<"\n\t\t      *____________|  |____________*       ";
   cout<<"\n\t\t                  _|  |_                  ";
   cout<<"\n\t\t                 |______|                \n\n\n\n";
}



void admin()
{
     char username[30] ;
        char pass[12] ;
    cout<<"Input User name: ";
    cin>>username;
    cout<<"Enter User Password: ";
    char ch;
    int i=0;
    while(1)
    {
        ch=getch();
        if(ch==13)
        {
            pass[i]='\0';
            break;
        }
        else if(ch==8)
        {
            if(i>0)
            {
                i--;
                cout<<"\b \b";
            }
        }
        else if(ch==32||ch==9)
        {
            continue;
        }
        else
        {
            pass[i]=ch;
            i++;
            cout<<"*";
        }
    }
    pass[i]='\0';
    cout<<"\n";
    if((strcmp(username,"Dalwer")==0)&&(strcmp(pass,"12345")==0))
    {
        cout<<"";
    }
    else
    {
        cout<<"\n\n !!Sorry Try Again.....\n"<<endl;
        getch();
        system("cls");
        admin();
        system("Cls");
    }
}

void vote()
{
    cout<<"Sorry! sir";
}
void vote_result()
{
    cout<<"I can not do this sir...extremely sorry sir";
}



void menu()
{
    system("Cls");
    cout << "\t\t\t<====== Electronic Voting Machine ======>";
    cout <<"\n\n                                          ";
    cout << "\n\n";
    cout<<"\n\n\t\t\t     MAIN Menu    ";
    cout<<"\n\t\t\t====================\n\n";
    cout<<"Enter your choice: "<<endl;
    cout<<"1.candidate Information::"<<endl;
    cout<<"2.Show all candidate information"<<endl;
    cout<<"3.Edit candidate information"<<endl;
    cout<<"4.Delete candidate information"<<endl;



   // cout<<"3.Delete candidate information"<<endl;
  //  cout<<"4.Edit staff information"<<endl;

    cout<<"5.voters Information:"<<endl;
    cout<<"6.Show all voters information"<<endl;
    cout<<"7.Edit voters information"<<endl;
    cout<<"8.Delete voters information"<<endl;


    cout<<"9.vote:"<<endl;
    cout<<"0.exit program"<<endl;

    cout<<"enter your choice"<<endl;



}

int main()
{
    candidates_record cr;
    voters_record vr;
    int c1;
    int num1;
    int c;
    int num;
    logo_show();
    Sleep(1000);
    admin();
    Sleep(500);
    do
    {
        system("Cls");

        menu();
        cin>>c;
        cout<<endl<<endl;
        switch(c)
        {
        case 1:

            write_account();
            break;
 // ad.  Delete_voters_information(int b);
//  ad.  Edit_voters_information(int c);

            break;
        case 2:
           Show_all_candidate_information();

            break;
        case 3:
            system("Cls");
            admin();
            cout<<"\n\n\tEnter The Name Code : "; cin>>num;
            cout<<endl;
            Edit_candidate_information(num);
           break;
       case 4:
           system("Cls");
           admin();

            cout<<"\n\n\tEnter The Name Code : "; cin>>num;
            cout<<endl;
           Delete_candidate_information(num);
			break;
        case 5:
            write_account1();

            break;
        case 6:
             Show_all_voters_information();
            break;
        case 7:
            system("Cls");
            admin();
            cout<<"\n\n\tEnter The ID NO. : "; cin>>num1;
            cout<<endl;
            Edit_voters_information(num1);
           break;
        case 8:
            system("Cls");
            admin();
            cout<<"\n\n\tEnter The ID NO. : "; cin>>num1;
            cout<<endl;
            Delete_voters_information(num1);
			break;
        case 9:system("Cls");
            vote();
            vote_result();

            break;
        case 0:
            return 0;
            break;

        default:
            cout<<"Invalid choice ";
        }
        cout<<endl;
        cout<<"Press enter to continue... ";
        cin.get();
        cin.ignore();
    }while(c<=11);
return 0;
}


