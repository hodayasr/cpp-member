
#pragma once
#include <iostream>
#include<iterator>
#include <map>
using namespace std;

class Member
{
    public:
    
    int id;
        map<int,Member*> following;
        map<int,Member*> followers;
        
    public:
       static int count();
        Member(); // constructor
         ~Member(); // distructor
        void follow(Member& other);
        void unfollow(Member& other);
        int  numFollowers();
        int numFollowing();
    
        
};