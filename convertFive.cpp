//exercice interessant ou l'on doit changer tout les zero contenu dans un nombre en 5 , sachant que le nombre est un entier

/*you are required to complete this method*/
class Solution {
  public:
    int convertFive(int n) {
        // Your code here
        if(n == 0)return 5;
        std::vector<int> copy;
        int res = 0;
        while(n > 0){
            int x = n % 10;
            if(x == 0)x = 5;
            copy.push_back(x);
            n /= 10;
        }
        int size = copy.size();
        size--;
        int i = 1;
        while(size > -1){
            res = res * pow(10,i) + copy[size];
            size--;
        }
        return res;
    }
};
