#pragma once


#include "NotificationType.hpp"
#include<string>

class Notification{
 private:
   int id;
   int userId;
   int timestamp;
   std::string content;
   NotificationType type;

  public: 
    Notification(int id,int userId,int timestamp,std::string content,NotificationType type){
        this->id=id;
        this->userId=userId;
        this->timestamp=timestamp;
        this->content=content;
        this->type=type;
    }

    int getNotificationId(){
        return id;
    }

    int getUserId(){
      return userId;
    }

    int getTimestamp(){
        return timestamp;
    }

    std::string getContent(){
        return content;
    }

    NotificationType getNotificationType(){
        return type;
    }
};