#pragma once

#include<string>
#include<vector>

class User{
 private:     
   int id;
   std::string name;
   std::string email;
   std::string password;
   std::string profilePic;
   std::string bio;
   std::vector<int> friends;
   std::vector<int> posts;
 public:
   User(int id,std::string name,std::string email,std::string password,std::string profilePic,std::string bio,std::vector<int> friends,std::vector<int> posts){
     this->id=id;
     this->email=email;
     this->password=password;
     this->name=name;
     this->bio=bio;
     this->friends=friends;
     this->posts=posts;
     this->profilePic=profilePic;
   }
   
   int getUserId(){
    return id;
   }

   std::vector<int>& getPosts(){
    return posts;
   }

   std::vector<int>& getFriends(){
    return friends;
   }

   std::string getName(){
     return name;
   }

   std::string getEmail(){
     return email;
   }

   std::string getPassword(){
     return password;
   }

   std::string getProfilePic(){
     return profilePic;
   }

   std::string getBio(){
     return bio;
   }
};