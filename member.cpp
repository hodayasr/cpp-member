#include <iostream>
using namespace std;
#include <map>
#include <iterator>
#include "member.h"

      static int memberID=0;
      
      // member : constructor
      member::member()
      {
          memberID++;
          this->id=memberID;
          
      }
      
      // member : disturctor
      member:: ~member()
      {
          memberID--;
	map<int,member*>::iterator find;
	map<int,member*>::iterator itr;

	for(itr=following.begin(); itr!=following.end(); ++itr)
	{
		find=itr->second->followers.find(this->id);
		itr->second->followers.erase(find);
		following.erase(itr);
	    
	}
	
	for(itr=followers.begin(); itr!=followers.end();++itr)
	{
		find=itr->second->following.find(this->id);

		itr->second->following.erase(find);
	}
          
      }
	
   int member::numFollowers()
   {
       return followers.size();
   }
   int member::numFollowing()
   {
    return following.size();   
   }
  
  // follow other member 
void member::follow(member& b)
{
   if(this->id!=b.id) // can't follow himself
   {
    pair<int,member*> ptr; 
    
    //check that not follow b already
	map<int,member*>::iterator find;
	find=followers.find(b.id);	
	if(find == followers.end())
	{
// if not follow him - add b to members of following
		ptr.first=b.id;
		ptr.second=&b;
		following.insert(ptr);

// add this member to b members of followers
		ptr.first=this ->id;
		ptr.second=this;
		b.followers.insert(ptr);
   }
       
   }
}

// unfollow other member
void member::unfollow(member& b)
{
    if(this->id!=b.id)
    {
    // remove from the map that follow after b
   map<int,member*>::iterator find;
	find=b.followers.find(this->id);
	b.followers.erase(find);

   // remove from the map that follow b after this member
   find=following.find(b.id);
	following.erase(find);
    }
}

    int member::count()
   {
       return memberID;
   }
   