//le code que j'ai realiser mais avec un  complexite de O(n^2) la complexite est trop grande 

//fonctionne jusqu'au test 1010 / 1111
void leftRotate(std::vector<int>& arr,int d){
        int size = arr.size();
        for(int i = 0;i < d;i++){
            int first = arr[0];
            for(int j = 0;j < size;j++){
                if(i+j < size)arr[j] = arr[j + 1];
            }
            arr[size - 1] = first;
        }
    }

//les autres versions 

class Solution {
public:
    void leftRotate(vector<int>& arr, int d) {
        int n = arr.size();
        d = d % n;  // Réduire d si plus grand que n
        if (d == 0) return;

        vector<int> temp(d);
        // Copier les d premiers éléments
        for (int i = 0; i < d; ++i) {
            temp[i] = arr[i];
        }
        // Décaler le reste
        for (int i = 0; i < n - d; ++i) {
            arr[i] = arr[i + d];
        }
        // Recoller la partie temporaire à la fin
        for (int i = 0; i < d; ++i) {
            arr[n - d + i] = temp[i];
        }
    }
};

//les version optimisee 

class Solution {
public:
    void leftRotate(vector<int>& arr, int d) {
        int n = arr.size();
        d = d % n;  // Réduire d si plus grand que n
        if (d == 0) return;

        vector<int> temp(d);
        // Copier les d premiers éléments
        for (int i = 0; i < d; ++i) {
            temp[i] = arr[i];
        }
        // Décaler le reste
        for (int i = 0; i < n - d; ++i) {
            arr[i] = arr[i + d];
        }
        // Recoller la partie temporaire à la fin
        for (int i = 0; i < d; ++i) {
            arr[n - d + i] = temp[i];
        }
    }
};

//algorithm de rotations par cycle 
class Solution {
public:
    void leftRotate(vector<int>& arr, int d) {
        int n = arr.size();
        d = d % n;
        if (d == 0) return;

        int count = 0; // nombre d’éléments déplacés
        for (int start = 0; count < n; start++) {
            int current = start;
            int prev = arr[start];

            do {
                int next = (current + n - d) % n; // position où placer prev
                int temp = arr[next];
                arr[next] = prev;
                prev = temp;
                current = next;
                count++;
            } while (start != current);
        }
    }
};

//autre algorithm on utilisant un autre tableau pour garder les valeurs 
class Solution {
public:
    void leftRotate(vector<int>& arr, int d) {
        int n = arr.size();
        d = d % n;  // Si d > n, on réduit d

        if(d == 0) return; // Pas de rotation nécessaire

        vector<int> temp(arr.begin(), arr.begin() + d);        // Partie à déplacer
        for(int i = 0; i < n - d; i++) {
            arr[i] = arr[i + d];                                // Décalage des éléments restants
        }
        for(int i = 0; i < d; i++) {
            arr[n - d + i] = temp[i];                           // Remise en fin des éléments déplacés
        }
    }
};

