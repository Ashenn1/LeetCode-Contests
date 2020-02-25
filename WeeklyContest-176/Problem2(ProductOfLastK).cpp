class ProductOfNumbers {
public:
    vector<int> q;
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        
        q.push_back(num);
        
    }
    
    int getProduct(int k) {
        
        int sum = 1;
        
        for(int i =q.size()-k; i<q.size();i++ ){
            sum*= q[i];
        }
        
        return sum;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */