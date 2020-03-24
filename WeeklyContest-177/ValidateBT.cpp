class Solution {
public:
    
    int countNodes(vector<int> &l , vector<int> &r , int root){
        
        if(root == -1) return 0;
        
        return 1+countNodes(l , r, l[root]) + countNodes(l , r, r[root]);
    }
    
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        
        vector<int> in_degree(n , 0);
        
        int root = -1;
        
        // Loop to count in-degrees for every node
        for(int i = 0; i< leftChild.size() ; i++){    
            if(leftChild[i] != -1 && ++in_degree[leftChild[i]] > 1) // if in-degree of a node exceeds 1 then return false
                return false;
            if(rightChild[i] != -1 && ++in_degree[rightChild[i]] > 1)
                return false;
        }
        
        // Loop to find the root of the tree
        for(int i = 0; i< leftChild.size(); i++){
            if(in_degree[i] == 0)
            {
                if(root == -1)
                    root = i;
                else
                    return false; // Bec there exists more than one root!
            }
        }
        
        if( root == -1) return false;
        
        
        return (countNodes(leftChild , rightChild , root) == n);
        
    }
};