#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<iomanip.h>
#include<process.h>

class user {
	private:
		char name[30];
		char uid[20];
		char pass[10];

	public:
		user(){
		}
		user(char n[30], char id[10], char p[10]){
			strcpy(name, n);
			strcpy(uid, id);
			strcpy(pass, p);
		}
		char *returnuid(){
			return uid;
		}
		char *returnpass(){
			return pass;
		}
};

class admin {
	private:
		char name[30];
		char aid[20];
		char pass[10];

	public:
		void newadmin(){
			cout<<"Enter Name: ";	gets(name);
			cout<<"Enter Admin Id: ";	cin>>aid;
			cout<<"Enter Password: ";	cin>>pass;
		}
		char *returnaid(){
			return aid;
		}
		char *returnpass(){
			return pass;
		}
};

void login(int);
void userw();
void adminw();
char* crypt(const char *);

ifstream fin;
ofstream fout;

void main(){
int ch;
while(1){
clrscr();
	cout<<setw(35)<<endl<<"cryp+"<<setw(35)<<endl<<"=====";
	cout<<endl<<endl<<"\t\t1. Admin Login"<<endl<<"\t\t2. User Login"<<endl<<"\t\t0. Exit"<<endl<<endl<<"\t\t\tGo to: ";
		cin>>ch;
		if(ch==0)
			exit(0);
		else if(ch==1)
			login(1);
		else if(ch==2)
			login(2);
		else {
			cout<<endl<<endl<<"\t\t\t\tInvalid choice. Try Again.";
			getch();
		}
	}
}

void login(int ch){
clrscr();
	cout<<setw(35)<<endl<<"cryp+"<<setw(35)<<endl<<"=====";
	char *id, *pass;
	if(ch==2){
		user u;
		fin.open("Users.dat", ios::binary);
		while(!fin.eof()){
		 if(fin.eof())	break;
			fin.read((char*)&u, sizeof(user));
			cout<<endl<<endl<<"\tID: ";	cin>>id;
			if(strcmpi(u.returnuid(), id)==0){
				cout<<endl<<"\tPassword: ";
				int i=0;	char ch;
				while(1){
				ch=getch();
					if(ch=='\r')	break;
				pass[i]=ch;
				i++;
				cout<<'*';
				}
				if(strcmpi(u.returnpass(), pass))
					userw();
				else {
					cout<<endl<<endl<<"\t\tWrong password.";
					getch();
				}
			}
			else {
				cout<<"User not found. Try again.";
				getch();
			}
		 }
		 fin.close();
	}
	else if(ch==1){
		admin a;
		fin.open("Admin.dat", ios::binary);
cout<<endl<<endl<<"\t1. New admin register"<<endl<<"\t2. Registered admin login"<<endl;
int c; 	cout<<"\t\tEnter choice: ";		cin>>c;
if(c==1){
	cout<<endl<<endl<<"\tNew Admin Register";
	int n; cout<<endl<<"\tNumber of admins to be registered: ";	cin>>n;
	fout.open("Admin.dat", ios::binary);
	for(int i=0; i<n; i++){
		cout<<endl<<endl;
		a.newadmin();
		fout.write((char*)&a, sizeof(admin));
	}
	fout.close();
	cout<<endl<<endl<<"\tRecords added successfully";
	getch();
}
if(c==2){
while(!fin.eof()){
		 if(fin.eof())	break;
			fin.read((char*)&a, sizeof(admin));
			cout<<endl<<endl<<"\tID: ";	cin>>id;
			if(strcmpi(a.returnaid(), id)==0){
				cout<<endl<<"\tPassword: ";
				int i=0;	char ch;
				while(1){
				ch=getch();
					if(ch=='\r')	break;
				pass[i]=ch;
				i++;
				cout<<'*';
				}
				if(strcmpi(a.returnpass(), pass))
					adminw();
				else {
					cout<<endl<<endl<<"\t\tWrong password.";
					getch();
				}
			}
			else {
				cout<<"Admin doesn't exist";
				getch();
			}
		 }
		 fin.close();
	}
}
}
void userw(){
char str[500];
uwork:
clrscr();
	cout<<setw(35)<<endl<<"cryp+"<<setw(35)<<endl<<"=====";
	cout<<endl<<endl<<"\t1. Encrpt/Decrypt and display"<<endl<<"\t2. Encrypt/Decrypt and save to file"<<endl<<"\t3. Exit";
	int ch;		cout<<endl<<endl<<"\tEnter choice: ";	cin>>ch;
	if(ch==1){
	cout<<endl<<endl<<"\tEnter text (max 500 chaacters | in CAPS only)  to encrypt/decrypt: "<<endl;
		gets(str);
		cout<<endl<<endl<<"Encrypted/Decrypted text: "<<endl;
		cout<<crypt(str);
	getch();
	}
	else if(ch==2){
	cout<<endl<<endl<<"\tEnter text (max 500 characters | in CAPS only) to encrypt/decrypt: "<<endl;
		gets(str);
		fout.open("cryp+.txt");
		fout<<crypt(str);
		fout.close();
		cout<<endl<<endl<<"\tText saved to 'cryp+.txt'.";
	getch();
	}
	else if(ch==3)
		exit(0);
	else {
		cout<<endl<<endl<<"\tInvalid. Try again.";
		getch();
	}
	goto uwork;
}

void adminw(){
admin a;
awork:
clrscr();
	cout<<setw(35)<<endl<<"cryp+"<<setw(35)<<endl<<"=====";
cout<<endl<<endl<<"\t1. New User Register"<<endl<<"2. User Workspace(encryption/decryption)"<<endl<<"3. Exit";
	int ch;		cout<<endl<<endl<<"\t\tEnter choice: ";		cin>>ch;
if(ch==1){
	int n; 	cout<<endl<<endl<<"\tNumber of users to be registered: ";	cin>>n;
	fout.open("Users.dat", ios::binary);
	char *name, *uid, *pass;
	for(int i=0; i<n; i++){
	cout<<endl<<"\tEnter name: ";	gets(name);
	cout<<"\tEnter User ID: ";	cin>>uid;
	cout<<"\tEnter Password: ";	cin>>pass;
	user u(name, uid, pass);
		fout.write((char*)&u, sizeof(user));
	}
	fout.close();
	cout<<endl<<endl<<"\tRecords added successfully";
	getch();
}
else if(ch==2)
	userw();
else if(ch==3)
	exit(0);
else {
	cout<<endl<<endl<<"Invalid choice. Try again.";
	getch();
	}
goto awork;
}

char alpha[]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";		//reference alphabets
char rotors[3][27] = {"EKMFLGDQVZNTOWYHXUSPAIBRCJ", "AJDKSIRUXBLHWTMCQGZNPYFVOE", "BDFHJLCPRTXVZNYEIWGAKMUSQO"};	//rotor settings for encryption
char reflector[] = "YRUHQSLDPXNGOKMIEBFZCWVJAT";		//setting for second pass through rotors
char key[] = "HTC";			//key combination for encryption/decryption

long mod26(long a)			//to shuffle through the rotor combination after each iteration
{
  return (a%26+26)%26;
}

int li(char l)				//returns the position of character in alphabet series, example: A=0, B=1
{
  return l-65;
}

int index(char* str, int find)		//returns the number of characters present in 'str' before first occurence of 'find'
{
  int ctr=0;
  for(int i=0; i<strlen(str); i++){
	if(str[i]!=find)
		++ctr;
	else
		break;
  }
  return ctr;
}

char* crypt (const char *ct)		//main encryption/decryption function
{
  int L = li(key[0]);               //setting for left rotor
  int M = li(key[1]);               //setting for middle rotor
  int R = li(key[2]);               //setting for roght rotor

  char* output;

  for ( int x = 0; x < strlen(ct) ; x++ ) {
	int ct_letter = li(ct[x]);

	R = mod26(R + 1);
//first pass through rotors
	char a = rotors[2][mod26(R + ct_letter)];
	char b = rotors[1][mod26(M + li(a) - R)];
	char c = rotors[0][mod26(L + li(b) - M)];
//pass through reflector
	char ref = reflector[mod26(li(c) - L)];
//second pass through rotors
	int d = mod26(index(rotors[0], alpha[mod26(li(ref) + L)]) - L);
	int e = mod26(index(rotors[1], alpha[mod26(d + M)]) - M);
	char f = alpha[mod26(index(rotors[2], alpha[mod26(e + R)]) - R)];

	output[x]=f;		//after pass through rotors and reflector, each letter saved in output string
  }
output[strlen(ct)]='\0';

  return output;
}