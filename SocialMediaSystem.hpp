#pragma once

#include<map>
#include<iostream>
#include "User.hpp"
#include "Notification.hpp"
#include "Post.hpp"
#include "NotificationType.hpp"
#include "Comment.hpp"
#include<algorithm>

class SocialMediaSystem{
  private:
    static SocialMediaSystem* instance;
    std::map<int,User*> users;
    std::map<int,Post*> posts;
    std::map<int,std::vector<Notification*>> notifications;
    static int currentTime;

    
    SocialMediaSystem(){
        std::cout<<"instance has been created!!!"<<std::endl;
    }
  public:
    
    static SocialMediaSystem* getInstance(){
        if(instance==nullptr){
            instance=new SocialMediaSystem();
        }
        return instance;
    }  
 
    void registerUser(User *user){
        users[user->getUserId()]=user; 
    } 

    User* loginUser(std::string email,std::string password){
        for(auto it:users){
            if(it.second->getEmail()==email && it.second->getPassword()==password){
                return it.second;
            } 
        }
        return nullptr;
    }

    void updateUserProfile(User *user){
        users[user->getUserId()]=user;
    }
    
    void addNotification(int userId,Notification *notification){
       notifications[userId].push_back(notification);
    }

     
    int getNotificationid(){
        int id = rand()%999999999;
        return id;
    } 

    int getTimestamp(){
        return currentTime++;
    }


    void sendFriendRequest(int senderId ,int receiverId){
        if(users.find(receiverId)==users.end()){
            return;
        }
        User *receiver = users[receiverId];
        std::string content = "User with id "+ std::to_string(senderId) + " has send you a friend Request:)";
        Notification* notification = new Notification(getNotificationid(),receiverId,getTimestamp(),content,FRIEND_REQUEST);
        addNotification(receiverId,notification);
    }


    void acceptFriendRequest(int userId,int friendId){
        User *user = users[userId];
        User *frnd = users[friendId];
        if(user!=nullptr && frnd!=nullptr){
            user->getFriends().push_back(frnd->getUserId());
            frnd->getFriends().push_back(user->getUserId());
            std::string content = "friend request has been accepted by " + std::to_string(userId);
            Notification* notification = new Notification(getNotificationid(),friendId,getTimestamp(),content,FRIEND_REQUEST_ACCEPTED);
            addNotification(friendId,notification);
        }
    }

    void createPost(Post *post){
       posts[post->getPostId()]=post; 
       User *user = users[post->getUserId()];
       if(user!=nullptr){
          user->getPosts().push_back(post->getPostId());
       }
    }   
    
   static bool comp(Post *p1,Post *p2){
      return p1->getTimestamp()>p2->getTimestamp();
   }
   
    std::vector<Post*> getNewsFeed(int userId){
        std::vector<Post*> feeds;
        if(users.find(userId)==users.end())return feeds;
        User *user = users[userId]; 
        for(int friendId:user->getFriends()){
                if(users.find(friendId)!=users.end())
                  {
                      User *frnd = users[friendId];
                      for(int postId:frnd->getPosts()){
                          feeds.push_back(posts[postId]);
                      }
                  }
        }

        for(int postId:user->getPosts()){
            feeds.push_back(posts[postId]);
        }
             
        std::sort(feeds.begin(),feeds.end(),comp); 
        return feeds;
    }

   void likeOnPost(int userId,int postId){
       if(users.find(userId)==users.end())return;
       if(posts.find(postId)==posts.end())return;
       Post *post = posts[postId];
       std::vector<int> &likes = post->getLikes();
       if(find(likes.begin(),likes.end(),userId)==likes.end()){
           likes.push_back(userId);
           std::string content = "User with id " + std::to_string(userId) + " has liked your post";
           Notification* notification = new Notification(getNotificationid(),post->getUserId(),getTimestamp(),content,LIKE);
           addNotification(post->getUserId(),notification);
       }
   }

   void commentOnPost(Comment *com){
       int userId = com->getUserId();
       int postId = com->getPostId();
       if(users.find(userId)==users.end())return;
       if(posts.find(postId)==posts.end())return;
       Post *post = posts[postId];
       std::vector<int> &comments = post->getComments();
       comments.push_back(userId);
       std::string content = "User with id " + std::to_string(userId) + " has commented on your post";
       Notification* notification = new Notification(getNotificationid(),post->getUserId(),getTimestamp(),content,COMMENT);
       addNotification(post->getUserId(),notification);
   } 
    
    std::vector<Notification*> getNotification(int userId){
        return notifications[userId];
    }

};

SocialMediaSystem* SocialMediaSystem::instance=nullptr;
int SocialMediaSystem::currentTime=0;
