#ifndef TIEBA_INFO_DEF_H_
#define TIEBA_INFO_DEF_H_
#include "../common_def.h"
#include "serialize_util.h"
#include "common_util.h"
namespace gezi {
namespace tieba {
struct QuoteInfo
{
uint64 postId;
uint userId;
string userName;
uint64 ip;
string content;
bool operator == (const QuoteInfo& other) const;
//friend class boost::serialization::access;
template<class Archive>
void serialize(Archive &ar, const unsigned int version);
};
struct PostInfo
{
uint64 postId;
uint64 threadId;
uint userId;
uint forumId;
uint64 ip;
int64 createTime;
string title;
string content;
string userName;
string forumName;
QuoteInfo quoteInfo;
bool operator == (const PostInfo& other) const;
bool operator < (const PostInfo& other) const;
bool IsThread() const;
bool IsQuote() const;
//friend class boost::serialization::access;
template<class Archive>
void serialize(Archive &ar, const unsigned int version);
};
struct UrlInfo;
struct ExtendedPostInfo : public PostInfo
{
map<string, UrlInfo> urlInfoMap;
vector<string> urls;
//friend class boost::serialization::access;
template<class Archive>
void serialize(Archive &ar, const unsigned int version);
};
struct PostsInfo
{
vector<uint64> pids;
vector<uint64> tids;
vector<uint> uids;
vector<int64> times;
vector<uint> fids;
vector<string> fnames;
vector<string> titles;
vector<string> contents;
vector<uint64> ips;
vector<bool> isThreads;
size_t size();
};
struct UserPostsInfo
{
uint userId;
int numPosts;
vector<uint64> pids;
vector<uint64> tids;
vector<int64> times;
vector<string> titles;
vector<string> contents;
vector<uint64> ips;
vector<bool> isThreads;
vector<bool> isPostsDeleted;
vector<uint> fids;
vector<string> fnames;
vector<string> level1Names;
vector<string> level2Names;
vector<int64> ranks;
vector<int64> hotValues;
size_t size();
//friend class boost::serialization::access;
template<class Archive>
void serialize(Archive &ar, const unsigned int version);
};
struct CommentInfo
{
uint64 threadId;
uint64 postId;
uint64 commentId;
string userName;
uint64 userId;
uint64 ip;
int64 createTime;
string content;
bool operator == (const CommentInfo& other);
//friend class boost::serialization::access;
template<class Archive>
void serialize(Archive &ar, const unsigned int version);
};
typedef vector<CommentInfo> Comments;
struct FullPostsInfo
{
uint64 threadId;
uint forumId;
string title;
string forumName;
bool isDeleted;
int numPosts;
vector<uint64> pids;
vector<uint> uids;
vector<uint64> ips;
vector<int64> times;
vector<string> unames;
vector<string> contents;
vector<Comments> commentsVec;
size_t size();
bool IsValid();
const Comments& GetComments(int idx) const;
//friend class boost::serialization::access;
template<class Archive>
void serialize(Archive &ar, const unsigned int version);
};
struct ReplyInfo
{
uint64 threadId;
uint64 userId;
uint64 postId;
uint forumId;
uint64 ip;
int64 createTime;
};
struct UserInfo
{
uint userId;
string userName;
int64 regTime;
int userSex;
int followCount;
int followedCount;
string email;
string mobile;
int birthYear;
int isGroupOwner;
int userType;
int userStatus;
string userTag;
string userDetail;
bool operator == (const UserInfo& other) const;
//friend class boost::serialization::access;
template<class Archive>
void serialize(Archive &ar, const unsigned int version);
};
struct UserPostNumInfo
{
uint userId;
int numPosts;
int numThreads;
int numGoods;
int numPhotos;
//friend class boost::serialization::access;
template<class Archive>
void serialize(Archive &ar, const unsigned int version);
};
struct UserLikeForumInfo
{
struct Node
{
string forumName;
int64 time;
int level;
int curScore;
int leftScore;
bool operator == (const Node& other) const;
bool operator < (const Node& other) const;
//friend class boost::serialization::access;
template<class Archive>
void serialize(Archive &ar, const unsigned int version);
};
int GetLevel(string forumName);
uint userId;
int maxLevel;
int numLikes;
int sumLevels;
map<string, Node> infoMap;
vector<string> forumNames;
vector<int> levels;
//friend class boost::serialization::access;
template<class Archive>
void serialize(Archive &ar, const unsigned int version);
};
struct ThreadInfo
{
uint64 threadId;
uint64 userId;
uint64 postId;
uint forumId;
string forumName;
int64 createTime;
uint64 ip;
string address;
string title;
string content;
bool isDeleted;
bool hasMedia;
bool operator == (const ThreadInfo& other) const;
//friend class boost::serialization::access;
template<class Archive>
void serialize(Archive &ar, const unsigned int version);
};
struct DeleteInfo
{
uint64 tid;
uint64 pid;
string opUid;
string monitorType;
int64 opTime;
bool isDeleted;
bool operator == (const DeleteInfo& other) const;
//friend class boost::serialization::access;
template<class Archive>
void serialize(Archive &ar, const unsigned int version);
};
struct ForumInfo
{
uint fid;
uint rank;
uint hotValue;
string level1Name;
string level2Name;
bool operator == (const ForumInfo& other) const;
//friend class boost::serialization::access;
template<class Archive>
void serialize(Archive &ar, const unsigned int version);
};
struct UrlInfo
{
string url;
float rank;
bool isJump;
float jumRank;
string content;
bool operator == (const UrlInfo& other);
//friend class boost::serialization::access;
template<class Archive>
void serialize(Archive &ar, const unsigned int version);
};
struct ImgInfo
{
vector<int> gameporn_rate;
vector<int> text_ratio;
vector<int> color_rate;
vector<int> simi_rate;
vector<int> textbox_num;
vector<string> ocr_img;
vector<int> porn_rate;
int imgCount;
uint64 pid;
size_t size();
bool operator == (const ImgInfo& other) const;
//friend class boost::serialization::access;
template<class Archive>
void serialize(Archive &ar, const unsigned int version);
};
static const int kMaxRequestCount = 100;
#ifdef PYTHON_WRAPPER
struct PyHack_Comments
{
Comments comments;
};
#endif
}
}
#endif
