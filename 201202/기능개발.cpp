// 문제가 개편되었습니다. 이로 인해 함수 구성이나 테스트케이스가 변경되어, 과거의 코드는 동작하지 않을 수 있습니다.
// 새로운 함수 구성을 적용하려면 [코드 초기화] 버튼을 누르세요. 단, [코드 초기화] 버튼을 누르면 작성 중인 코드는 사라집니다.
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> dday;//완료일
    vector<int> upday;
    int max = 0, updatenum=0;
    int tcase = speeds.size();
    int qu,rem=0;

    //완료일 구하기
    for(int i = 0 ; i<tcase ; i++) {
        qu = (100-progresses[i])/speeds[i];
        rem = (100-progresses[i])%speeds[i];
        if(rem!=0) {
            qu++;
        }
        //qu는 완료일임.
        dday.push_back(qu);
        
        if(max<qu) {
            answer.push_back(1);
            max=qu;
        }
        else {
            int temp=answer.back();
            answer.pop_back();
            answer.push_back(temp+1);
        }
    }
   
    
    return answer;
}