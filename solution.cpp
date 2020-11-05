#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include "solution.h"
using namespace std;

int sum = 0;
int answer = 0;

TreeNode* MTree(TreeNode* root, int data)
{
   if(root == NULL) {
       root = (TreeNode*)malloc(sizeof(TreeNode));
       root->left = NULL;
       root->val = data;
       return root;
   }
   else {
       root->left = MTree(root->left, data);
       return root;
   }
}

struct TreeNode* Solution::buildTree(string filename) {
   TreeNode bTree[16001];
   TreeNode* root = NULL; 
   int numPoints, temp;

   ifstream ifs(filename);

   if (ifs.is_open())
   {
      ifs >> numPoints;
      for (int i = 1; i <= numPoints; i++)
      {
        ifs >> temp;
        root = MTree(root, temp);

        bTree[i].val = root->val;
        bTree[i].left = NULL;
        bTree[i].right = NULL;
        root = root->left;

        if(i%2 == 0) {
            bTree[i/2].left = &bTree[i];
        }
        else {
            bTree[i/2].right = &bTree[i];
        }
      }
   }
}

void dfs(TreeNode* node){
        if(!node) return;
        
        if(!node->left && !node->right){ //leaf node case
            sum = sum*10 + node->val;
            answer += sum;
            return;
        }
        sum = sum*10 + node->val;
        
        if(node->left) {
            dfs(node->left);
            sum/=10;
        }
      
        if(node->right) {
            dfs(node->right);
            sum/=10;
        }
}

unsigned long long int Solution::getPathSum (struct TreeNode* root) {
        if(!root) return answer;
        
        dfs(root);
        return answer;
}








    

