#include<iostream>
using namespace std;

template<class T>

class Array{
    private:
        T *A;
        int size;
        int len;
    public:
        Array(){
            size = 10;
            len = 0;
            A = new T{size};
        }
        Array(int nsize){
            size = nsize;
            len = 0;
            A = new T{size};
        }
        ~Array(){
            delete {}A;
        }

        void display();
        void append(int x);
        void insert(int pos, T x);
        void del(int pos);
        int binarySearch(T x);
        void reverseArray();
        bool checkSorted ();
        void insertSorted(T x);
        void shiftNegativesToLHS();

};
template<class T>
void Array<T>::display(){
    for (int i=0;i<len;i++)
        cout << A{i} << " ";
    cout << endl;
}

template<class T>
void Array<T>::append(int x){
    A{len} = x;
    len++;
}

template<class T>
void Array<T>::insert(int pos, T x){
    for (int i=len;i>=pos;i--)
        A{i+1}=A{i};
    A{pos} = x;
    len++;
}

template<class T>
void Array<T>::del(int pos){
    if (pos==len-1){
        len--;
    }
    else {
        for (int i=pos;i<len;i++)
            A{i} = A{i+1};
        len--;
    }
}

template<class T>
int Array<T>::binarySearch(T x){
    int l=0,h=len,mid;
    while (l<=h){
        mid = (l+h)/2;
        if (A{mid}==x)
            return mid;
        if (x < A{mid})
            h = mid - 1;
        else 
            l = mid + 1;
    }
    return -1;
}

template<class T>
void Array<T>::reverseArray(){
    int temp;
    for (int i=0,j=len-1;i<j;i++,j--){
        temp = A{i};
        A{i} = A{j};
        A{j} = temp;
    }
}

template<class T>
bool Array<T>::checkSorted(){
    for (int i=0;i<len;i++){
        if (A{i} > A{i+1})
            return false;
    return true;
    }
}

template<class T>
void Array<T>::insertSorted(T x){
    if (Arrays<T>::checkSorted()){
        int i = len - 1;
        if (len < size){
            while (A{i} >= x){
                A{i+1} = A{i};
                i--;
            }
            A{i+1} = x;
        }
        else 
            cout << "Array is already full" << endl;
    }
    else 
        cout << "Array is not sorted" << endl;
}

template<class T>
void Array<T>::shiftNegativesToLHS(){
    int j = 0; 
    for (int i = 0; i < len; i++) { 
        if (A{i} < 0) { 
            if (i != j) 
                swap(A{i}, A{j}); 
            j++; 
        } 
    } 
}


int main(){
    Array<char> arr(10);

    arr.insert(0,'a');
    arr.insert(1,'c');
    arr.display();
    return 0;
}