class Solution
{
public:
    int hammingWeight(uint32_t n)
    {
       int count =0 ;
       while(n){
        int lastbit = n&1; 
        if(lastbit==1 ) count++;
        n=n>>1;
       }
       return count;
    }
};
