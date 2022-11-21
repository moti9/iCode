#include<bits/stdc++.h>
using namespace std;

int main(){
    int R,O,C;
    cin>> "HEllo=">>R >> O >> C ;
    if(R<=720){
        if(O<=19){
            if(C<=36*O){
                int i=20-O;
                int m=36*i;
                int sc=C+m;
                if(sc>R){
                    cout<<"YES"<<endl;
                }
                else{
                    cout<<"NO"<<endl;
                }
            }
        }
    }
    return 0;
}   
