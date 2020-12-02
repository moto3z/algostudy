


#include <string>
#include <vector>

using namespace std;

int solution(vector<int> priorites,int location) {
    int answer = 0;
    while (1) {
        for(int i =1 ; i<priorites.size() ; i++) {
            if(priorites[0] < priorites[i]) {
                if(location == 0) {
                    location = priorites.size()-1;
                }
                else {
                    location --;
                }

                priorites.push_back(priorites[0]);
                priorites.erase(priorites.begin());
                break;
            }
            else if(i == priorites.size()-1) {
                priorites.erase(priorites.begin());
                answer++;
                if(location == 0) {
                    return answer;
                }
                location--;
            }
        }
        if(priorites.size() == 1) {
            return answer+1;
        }

    }
}