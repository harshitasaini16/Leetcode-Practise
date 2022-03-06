class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result=0;
        bool bit=( (n & 1) == 1)? 1:0;
        for (int i=0 ;i<32;i++){
            result = (result<< 1)|(bit); 
			n = n >>1; 
            bit=( (n & 1) == 1)? 1:0; 
        }
        return result;
    }
};