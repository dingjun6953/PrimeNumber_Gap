/*
Create a function that takes 3 positive arguments (gap,a,b)
a: start a positive number
b: end a positive number
gap: the distance between two prime numbers that are between a and b

The return of this function: the first pair of two prime numbers spaced with a prime gap of length gap between a and b (inclusive) as an array. 

*/
// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
//#include <set>
//#include <string>
//#include <climits>
//#include <cmath>

using namespace std;

vector<int> find_gap(int gap,int a, int b){
    int flag=0;
    //find all prime numbers 
    //store them into a vector
    vector<int> primeNumber; 
    for (int i=a; i<=b; i++){
        flag=0;
        //determine if the nubmer 'i' is a prime number
        for(int j=2;j<=i/2;j++){
            if(i%j==0) {
                flag=1;
                break;
            }
        }
        if(flag==0) primeNumber.push_back(i); 
    }
    //find the first pair of two prime numbers from the vector of primeNumber
    bool findgap; 
    int num1, num2; 
    for(auto elm1:primeNumber){
        findgap=false;
        for(auto elm2:primeNumber){
            if(elm2-elm1==gap)
            {
                findgap=true; 
                num1=elm1;
                num2=elm2;
                break;
            }
        }
        if (findgap) break; 
    }
//another version using iterators of vector
/*
 for(auto it1 = primeNumber.begin();it1 != primeNumber.end();it1++){
        findgap=false;
        for(auto it2 = primeNumber.begin();it2 != primeNumber.end();it2++){    
              if(*it2-*it1==gap)       
            {
                findgap=true; 
                num1=*it1;           
                num2=*it2;        
                break;
            }
        }
        if (findgap) break; 
    }
  */  
    return {num1,num2}; //return this pair of vector as an array
}



int main() {
    // Write C++ code here
    //vector<int> result=find_gap(2,3,50); //{3,5}
    //vector<int> result=find_gap(2,5,7); //{5,7}
    vector<int> result=find_gap(4,130,200); //{163,167}
    for (auto elm:result){
        cout<<elm<<"    "; 
    }

    return 0;
}
