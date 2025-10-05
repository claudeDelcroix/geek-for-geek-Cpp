/*Complete the function below*/
//premiere version du code j'etais aller trop loin dans mes reflexions ca ne servais a rien de faire comme cela vue que 
//avec les nombre un nombre palindrome c'est un numbre avec lequel on obtiens le meme nombre meme a l'invers
//alors il etait juste question de renverser le nombre et de le comparer a l'original 
class Solution {
  public:
  int how_many_digit(const int number){
        if(number >-1 && number <10)return 1;
        if(number > 9 && number < 100)return 2;
        if(number > 99 && number < 1000)return 3;
        if(number >999 && number < 10000)return 4;
        if(number > 9999 && number < 100000)return 5;
    }

    bool check_one_number(int number){
        int size = how_many_digit(number);
        int* arr = new int[size];
        int i = 0;
        while(number > 0){
            arr[i] = number % 10;
            number = number / 10;
            i++;
        }
        i = size - 1;
        for(int j = 0;j < size;j++){
            if(arr[j] != arr[i])return false;
            i--;
        }
        delete arr;
        return true;
    }
    bool isPalinArray(vector<int> &arr) {
        //3 code here
        for(int i = 0;i < arr.size();i++){
            if(!check_one_number(arr[i])){
                return false;
            }
        }
        return true;
        
    }
};

//code optimiser 
class Solution {
  public:
   bool check_one_number(const int number){
        int copy= number,rever = 0;
        while(copy > 0){
            int digit = copy % 10;
            rever = rever* 10 + digit;
            copy /= 10;
        }
        return rever == number;
    }
    bool isPalinArray(vector<int> &arr) {
        //3 code here
        for(int i = 0;i < arr.size();i++){
            if(!check_one_number(arr[i])){
                return false;
            }
        }
        return true;
        
    }
};
