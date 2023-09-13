#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    int len = prices.size();
    
    bool is_find=false;
    for(int i=0 ; i<len ; i++) {
        is_find=false;
        for(int j=i ; j<len ; j++) {
            
            if(prices[i]>prices[j]){
                is_find=true;
                answer.push_back(j-i);
                break;
            }
        }
        if(is_find == false) {
            answer.push_back(len-i-1);
        }
    }
    return answer;
}