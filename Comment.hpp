#pragma once

#include<string>
#include<vector>

class Comment{
  private:
    int id;
    int userId;
    int postId;
    std::string content;
    std::vector<int> likes;
    int timestamp;

   public:
      Comment(int id,int userId,int postId,std::string content,std::vector<int> likes,int timestamp){
        this->id=id;
        this->userId=userId;
        this->content=content;
        this->postId=postId;
        this->likes=likes;
        this->timestamp=timestamp;
      }

      int getCommentId(){
        return id;
      } 

      int getPostId(){
        return postId;
      }

      int getUserId(){
        return userId;
      }

      std::string getContent(){
        return content;
      }

      std::vector<int>& getLikes(){
        return likes;
      }

      int getTimestamp(){
        return timestamp;
      }
};
