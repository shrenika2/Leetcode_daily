class ProductOfNumbers {
    vector<int> pp;
    int sz = 0 ;
public:
    ProductOfNumbers() {
        pp.push_back(1);
        sz = 0;
        
    }
    
    void add(int num) {
        if(num==0){
            pp = {1};
            sz = 0;
        }else {
            pp.push_back(pp[sz]*num);
            sz++;
        }
    }
    
    int getProduct(int k) {
        if(k>sz) return 0;

        return pp[sz]/pp[sz-k];

    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */