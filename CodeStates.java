public class CodeStates {
   
        public static void main(String[] args){


            


        }

        public boolean isOdd(int num) {

        Math.abs(num);
        
        if(num == 0)	//num이 0이면 짝수 f
            return false;
        
        else if(num == 1) // num이 1이면 홀수
            return true;
        
        return isOdd(num -2); // 짝수 찾기 할때 2로 나누어 준것처럼 2를 빼주는것을 반복하여 홀수찾기
        
          }
    }


    