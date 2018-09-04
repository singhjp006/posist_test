#include <bits/stdc++.h>

using namespace std;




class node{
    public:
    // private:
           long long ownerId;
           vector<node*> children;
           long long nodeNumber;
           
    
    string timeStamp;
    string data;
    string nodeId;
    node* parent;
    string hashValue;
    
    node(long long owner,long long number){
        ownerId=owner;
        nodeNumber=number;
    }
    
    string getTimeStamp(){
    long long  now = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    ostringstream ss,ss2;
   ss << now;
   string s1(ss.str());
   return s1;
    
    }
};





// x 1 for encrypting , x=2 for decrypting
string encDec(string str,int x,long long n,long long k){
 // we can also encrypt using SHA1 library by openssl for encrypting 

    
    
   switch(x)
   {
      //first case for encrypting a string
      case 1:
         for(long long i = 0;i<n; i++){
            str[i] = str[i] + k;
         }
             
        break;

        
      

      //second case for decrypting a string
      case 2:
         for(long long i = 0;i<n; i++)
         str[i] = str[i] - k; 

      
      break;

      default:
         cout << "\nInvalid Input !!!\n";
         exit(0);
   }
   
   return str;
}



node* createNode(long long ownerId,long long nodeNumber,float value,string ownerName,long long key,node *parent){
   ostringstream ss,ss2;
   ss << ownerId;
   string s1(ss.str());
   ss2 << value;
   string s2(ss2.str());
   
   // value to be encrypted
   string ans=s1+s2+ownerName;
   ans=encDec(ans,1,ans.length(),key);
   
    
    node *n=new node(ownerId,nodeNumber);
    n->timeStamp=n->getTimeStamp();
    n->data=ans;
    n->parent=parent;
    
    // set current as child to its parent
    if(n->parent!=NULL){
        n->parent->children.push_back(n);
    }
    
    
    
    n->nodeId="";
    
    
    return n;
    
}




int main()
{
    static long long id=0;
    vector<node*> v;
    node* n=new node(1,2);
    v.push_back(n);
    
    node * root=createNode(1,id++,1.0,"aa",2,n);
   



    return 0;
}
