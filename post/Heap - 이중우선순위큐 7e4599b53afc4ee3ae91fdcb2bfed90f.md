# Heap - 이중우선순위큐

생성일: 2020년 12월 8일 오전 11:21

# 문제

- 문제링크
- 이중우선순위큐 는 FIFO 특성의 일반큐에서 3가지 기능이 추가된 큐
    - I 숫자 : 큐에 숫자 삽입
    - D 1 : 최대값 삭제
    - D -1 : 최소값 삭제
- 최대값 최소값 삭제 기능을 추가해야함 → 일반큐로 구현하기에는 시간, 공간 복잡도가 상상이상
    - 1)Q 복사→ 새로운큐에다가 정렬(N*logN) → 바이너리서치(logN)
    - 2)Q 복사 → 선형탐색(이것은 최대/최소 알기위해), N
- 위 설명은 단한번의 루프를 돌기위해 필요한 연산이고, 입력이 N번이면
    - 최대 N^2 에서 N^2logN 정도까지 시간복잡도를 갖는다
    - 반복문 한번 돌때마다 sort같은게 필요하다면 Heap!

# 풀이

# 코드

```cpp
//////////////////////////////
//import java.util.Scanner;
//import java.io.FileInputStream;
import java.util.Comparator;
import java.util.PriorityQueue;

public class Solution {
	

	public static void main(String args[]) throws Exception
	{
		/////////////////////////////////
		//Solution sol = new Solution();
		//array class, 콜랙션,빅데시말
		Solution sol = new Solution();
		
		String[] in1 = {"I 16","D 1"};
		String[] in2 = {"I 7","I 5","I -5","D -1"};
		String[] in3 = {"I 1", "I 2", "I 3", "I 4", 
			"I 5", "I 6", "I 7", "I 8", "I 9", "I 10", 
			"D 1", "D -1", "D 1", "D -1", "I 1", "I 2",
			"I 3", "I 4", "I 5", "I 6", "I 7", "I 8", 
			"I 9", "I 10", "D 1", "D -1", "D 1", "D -1"};
		//String[] in4 = {};
		//String[] in5
 		
		
		int[] r1 = {0,0};
		int[] r2 = {7,5};
		int[] r3 = {8, 3};
		int[] ret = new int[2];
		
		
		//TC1
		ret = sol.solution(in1);
		if(ret == r1) {
			System.out.println("OK!");
		}
		else {
			System.out.print("No... : ");
			for(int i=0 ; i<ret.length ; i++) {
				System.out.print(ret[i]);
				System.out.print(' ');
			}
			System.out.println("\\n");
			
		}
		
		
		//TC2
		ret = sol.solution(in2);
		if(ret == r2) {
			System.out.println("OK!");
		}
		else {
			System.out.print("No... : ");
			for(int i=0 ; i<ret.length ; i++) {
				System.out.print(ret[i]);
				System.out.print(' ');
			}
			System.out.println("\n");
		}
		
		
		//TC3
		ret = sol.solution(in3);
		if(ret == r3) {
			System.out.println("OK!");
		}
		else {
			System.out.print("No... : ");
			for(int i=0 ; i<ret.length ; i++) {
				System.out.print(ret[i]);
				System.out.print(' ');
			}
			System.out.println("\n");
		}
		
		
		
	}
	// main //////////////////////////////////
	
	public int[] solution(String[] operations) {
		int[] answer = new int[]{0,0};
		
		PriorityQueue<Integer> pqMax = new PriorityQueue<>(Comparator.reverseOrder());
		PriorityQueue<Integer> pqMin = new PriorityQueue<>();
		
		for(String opit : operations) {
			String[] optoken = opit.split(" ");
			
			if(optoken[0].equals("I")) {
				//I 명령어는 무조건 숫자를 삽입
				pqMax.add(Integer.parseInt(optoken[1]));
				pqMin.add(Integer.parseInt(optoken[1]));
				
			}
			else if(optoken[0].equals("D")) {
				//D 명령어는 삭제, -1의 경우 최소값을 삭제
				if(pqMax.isEmpty()) {
					continue;
				}
				else {}
				
				int dels = Integer.parseInt(optoken[1]);
				if(dels == -1) {
					int mini = pqMin.peek();
					pqMin.remove(mini);
					pqMax.remove(mini);
				}
				else if(dels == 1) {
					int maxi = pqMax.peek(); 
					pqMin.remove(maxi);
					pqMax.remove(maxi);
				}
				else {
					//drop neither D -1,D 1
				}
			}
			else {
				//drop neither I,D 
			}
		}
		
		/*
		if(pqMax.isEmpty()) {
			answer[0] = 0;
		}
		else {
			answer[0] = pqMax.peek();
		}
		
		if(pqMin.isEmpty()) {
			answer[1] = 0;
		}
		else {
			answer[1] = pqMin.peek();
		}
		*/
		///*
		if(!pqMax.isEmpty()) {
            //answer[0] = pqMax.poll();
            //answer[1] = pqMin.poll();

            answer[0] = pqMax.peek();
            answer[1] = pqMin.peek();
        } 
        //*/
		
		return answer;
	}
	
	
	
}
```

# 해설

```cpp
snipet
```