/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
   TreeNode* nodeToParent(TreeNode* root, int start,map<TreeNode*,TreeNode*>& parent){
       TreeNode* temp=NULL;
       queue<TreeNode*> q;
       parent[root]=NULL;
       q.push(root);
       while(!q.empty()){
         TreeNode* front=  q.front();
         q.pop();
         if(front->val==start){
             temp=front;
         }
         if(front->left){
             parent[front->left]=front;
             q.push(front->left);
         }
         if(front->right){
             parent[front->right]=front;
             q.push(front->right);
         }


       }
       return temp;
   }
   int infectTree(TreeNode* root,map<TreeNode*,TreeNode*>& parent){
       int ans=0;
       map<TreeNode*,bool> visited;
       queue<TreeNode*> q;
       q.push(root);
       visited[root]=true;
       bool flag=false;
       while(!q.empty()){
        int size=q.size();
        for(int i=0;i<size;i++){
            TreeNode* front=q.front();
            q.pop();
            if(front->left && !visited[front->left]){
                visited[front->left]=true;
                q.push(front->left);
                flag=true;
            }
            if(front->right && !visited[front->right]){
                visited[front->right]=true;
                q.push(front->right);
                flag=true;
            }
            if(parent[front] &&!visited[parent[front]]){
                q.push(parent[front]);
                visited[parent[front]]=true;
                flag=true;
            }
        }
        if(flag==true){
            ans++;
            flag=false;
        }

       }
       return ans;
   } 
public:
    int amountOfTime(TreeNode* root, int start) {
        map<TreeNode*,TreeNode*> parent;
     TreeNode* temp=nodeToParent(root,start,parent);
     int ans=infectTree(temp,parent);
     return ans;   
    }
};
