#pragma once

#include<vector>
#include<string>

class Post{
  private:  
    int id;
    int userId;
    std::vector<int> comments , likes;
    std::string content;
    std::vector<std::string> imageUrls,videoUrls; 
    int timestamp;
  public:
    Post(int id,int userId,std::vector<int> comments,std::vector<int> likes,std::string content,std::vector<std::string> imageUrls,std::vector<std::string> videoUrls,int timestamp){
      this->id=id;
      this->comments=comments;
      this->content=content;
      this->imageUrls=imageUrls;
      this->videoUrls=videoUrls;
      this->userId=userId;
      this->likes=likes;
      this->timestamp=timestamp;
    }  

    int getPostId(){
        return id;
    }

    int getUserId(){
        return userId;
    }

    std::string getContent(){
        return content;
    }

    std::vector<int>& getComments(){
      return comments;
    }

    std::vector<int>& getLikes(){
      return likes;
    }


    std::vector<std::string> getImageUrls(){
        return imageUrls;
    }

    std::vector<std::string> getVideoUrls(){
        return videoUrls;
    }

    int getTimestamp(){
        return timestamp;
    }

};