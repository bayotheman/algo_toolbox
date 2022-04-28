#include<iostream>
#include<vector>
#include<cstdlib>
using namespace std;

long long maxPairwiseProductNaive(const vector<int> &v);
long long maxPairwiseProductFast(const vector<int> &v);

int main(){
    while(true){
        int n = rand() % 1000 + 2;
        cout << n << "\n";
        vector<int> a;
        for (int i = 0; i < n; ++i){
            a.push_back(rand() % 100000);
        }
        for (int i = 0; i < n; i++){
            cout << a[i] << ' ';
        }
        cout << "\n" ;
        long long res1 = maxPairwiseProductNaive(a);
        long long res2 = maxPairwiseProductFast(a);
        if(res1 != res2){
            cout<< "Wrong answer: " << res1 << ' ' << res2 << "\n";
            break;
        }else{
            cout << "OK\n" ;
        }
    }
    int n;
    cin >> n ;
    // cout <<'\n'<<endl;
    vector<int> v(n) ;
    for(int i = 0; i < n; ++i){
        cin >> v[i] ;
    }
    cout << maxPairwiseProductFast(v) <<endl;
    return 0;
}

long long maxPairwiseProductFast(const vector<int> &v){
    long long result;
    int size = v.size();
    int maxIndex = -1;
    for (int i = 0; i < size; ++i){
        if((maxIndex == -1) || (v[i] > v[maxIndex])){
            maxIndex = i;
        } 
    }
    int maxIndex2 = -1;

    for(int j = 0; j < size; ++j){
        if( (j != maxIndex) && ((maxIndex2 == -1) || (v[j] > v[maxIndex2]))) {
            maxIndex2 = j;
        }
    }
     
    cout << " maxIndex: " << maxIndex << "  maxIndex2: " << maxIndex2 << "\n";

    // result = v[maxIndex] * v[maxIndex2];
    // return result;
    return ((long long)v[maxIndex]) * v[maxIndex2];
}      

long long maxPairwiseProductNaive(const vector<int> &v){
    int n = v.size();
    long long result = 0;
    for (int i = 0; i < n; i++){
        for (int j = i + 1; j < n; j++){
            if(v[i] * v[j] > result ){
                result = v[i] * v[j];
            }
        }
    }
    return result;
}
 