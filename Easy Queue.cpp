#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    queue<int> cola;
    int querys, o, n;

    cin >> querys;

    while(querys --){
        cin >> o;

        if(o == 1){
            cin >> n;

            cola.push(n);
        }
        else if(o == 2){
            if(!cola.empty()) cola.pop();
        }
        else{
            if(cola.empty()) cout << "Empty!\n";
            else cout << cola.front() << "\n";
        }
    }

    return 0;
}