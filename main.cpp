
#include <iostream>
using namespace std;

#include "member.h"


member avi, beni, chana;

void test1() {
	member dana;
	chana.follow(dana);
	dana.follow(avi);
	cout << "  " << chana.numFollowers() << " " <<  chana.numFollowing() << endl; // 0 1
	cout << "  " << avi.numFollowers() << " " <<  avi.numFollowing() << endl; // 1 0
	cout << "  " << member::count() << endl; // 4
}
void test_unfollow(){
	member hodaya ,adi ,michal; //yitzhak,moshe,hadar;
	adi.follow(hodaya);
	michal.follow(hodaya);

	if(hodaya.numFollowers()!=2){
		cout<<"error- follow function"<<endl;
	}
	adi.unfollow(hodaya);
	if(hodaya.numFollowers()!=1){
		cout<<"error -unfollow function"<<endl;
	}
	michal.unfollow(hodaya);
	if(hodaya.numFollowers()!=0){
		cout<<"error- unfollow function"<<endl;
}
cout<<"the function 'unfollow()' work "<<endl;
}

void test_follow()
{
	member michal ,adi , shiran;
	shiran.follow(adi);
	adi.follow(michal);
	michal.follow(adi);
	shiran.follow(michal);
	adi.follow(shiran);
	
	//michal : num following- 1 , num followers-2
	//adi : num following- 2 ,num followers-2
	//shiran : num following- 2 ,num followers-1
	if((michal).numFollowing() != 1)||(michal.numFollowers() != 2)||
	(adi.numFollowing() != 2)||(adi.numFollowers() != 2)||
	(shiran.numFollowing() != 2)||(shiran.numFollowers() != 1)){

		cout << "error- follow function !" << endl;
	}

	else{

		cout << "the function 'follow()' work " << endl;
	}
}

int main() {
	test_unfollow();
	test_follow();
	cout << avi.numFollowers() << " " << avi.numFollowing() << endl; // 0 0
	avi.follow(beni);
	cout << avi.numFollowers() << " " << avi.numFollowing() << endl; // 0 1
	cout << beni.numFollowers() << " " << beni.numFollowing() << endl; // 1 0
	cout << member::count() << endl; // 3
	cout << endl;

	avi.follow(beni); // duplicate follow has no effect
	cout << avi.numFollowers() << " " << avi.numFollowing() << endl; // 0 1
	avi.unfollow(beni);	
	cout << avi.numFollowers() << " " << avi.numFollowing() << endl; // 0 0
	cout << endl;

	cout << chana.numFollowers() << " " <<  chana.numFollowing() << endl; // 0 0
	test1();
	cout << chana.numFollowers() << " " <<  chana.numFollowing() << endl; // 0 0
	cout << avi.numFollowers() << " " <<  avi.numFollowing() << endl; // 0 0
	cout << member::count() << endl; // 3
}