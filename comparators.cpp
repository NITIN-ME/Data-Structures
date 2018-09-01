#include<bits/stdc++.h>
using namespace std;


class Box{
public:
    int a, b;
    Box(int num1,int num2){
        a = num1;
        b = num2;
    }
};

int func(Box b1, Box b2){
    return b1.b < b2.b;
}


int main(){
    vector<Box> arr;
    arr.push_back(Box(1,2));
    arr.push_back(Box(3,5));
    arr.push_back(Box(2,10));
    arr.push_back(Box(0,3));
    sort(arr.begin(), arr.end(), func);
    for(int i = 0; i < arr.size(); i++){
        cout<<arr[i].a<<"  "<<arr[i].b<<endl;
    }

    cout<<endl;
    return 0;
}
