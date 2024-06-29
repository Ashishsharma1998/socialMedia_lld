#include "SocialMediaSystem.hpp"
#include "User.hpp"
#include "Post.hpp"
#include "Comment.hpp"
#include<vector>
using namespace std;



int main(){
   SocialMediaSystem *instance = SocialMediaSystem::getInstance();
   
   User *user1 = new User(1,"Ashish Sharma","ashish@mail.com","123456","proflePic1.png","sab tk hai",{},{});
   User *user2 = new User(2,"John Sharma","john@mail.com","123456","proflePic2.png","sab tk hai,haa yrr",{},{});
   
   instance->registerUser(user1);
   instance->registerUser(user2);

   //login
   User *usr = instance->loginUser("ashish@mail.com","123456");
   if(usr!=nullptr){
       cout<<"user has successfully logged in!\n"; 
   }else{
       cout<<"invalid email or password\n"; 
   }

   //send friend request
   instance->sendFriendRequest(user1->getUserId(),user2->getUserId());
   instance->acceptFriendRequest(user2->getUserId(),user1->getUserId());


   //create post
   Post *post1 = new Post(8,user1->getUserId(),{},{},"This is first post",{},{},instance->getTimestamp());
   Post *post2 = new Post(7,user2->getUserId(),{},{},"This is second post",{},{},instance->getTimestamp());
   
   instance->createPost(post1);
   instance->createPost(post2);

   //like the post
   instance->likeOnPost(user1->getUserId(),post2->getPostId());
   
   //comment on post
   Comment *comment1 = new Comment(3,user2->getUserId(),post1->getPostId(),"Looks good",{},instance->getTimestamp()); 
   instance->commentOnPost(comment1);
   

   //new feed
   vector<Post*> feeds = instance->getNewsFeed(user1->getUserId());
   cout<<"News feeds"<<endl;
   for(auto post:feeds){
    cout<<"content-->"<<post->getContent()<<endl;
    cout<<"likes-->"<<post->getLikes().size()<<endl;
    cout<<"comment-->"<<post->getComments().size()<<endl;
   }

   //Notifications
   cout<<"Notifications"<<endl;
   vector<Notification*> notifications = instance->getNotification(user1->getUserId());
   for(auto noti:notifications){
    cout<<"notificationType-->"<<noti->getNotificationType()<<" ";
    cout<<"notificationContent-->"<<noti->getContent()<<endl;
   }

   return 0; 
}