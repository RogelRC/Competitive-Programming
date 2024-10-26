#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int querys, n;
    bool flag = true;
    string oper;
    deque<int> cola;

    cin >> querys;

    while(querys --){
        cin >> oper;

        if(oper == "toFront"){
            cin >> n;

            if(flag) cola.push_front(n);
            else cola.push_back(n);
        }
        else if(oper == "front"){
            if(cola.empty()) cout << "No job for Ada?\n";
            else if(flag){
                cout << cola.front() << "\n";
                cola.pop_front();
            }
            else{
                cout << cola.back() << "\n";
                cola.pop_back();
            }
        }
        else if(oper == "reverse"){
            if(flag) flag = false;
            else flag = true;
        }
        else if(oper == "push_back"){
            cin >> n;

            if(!flag) cola.push_front(n);
            else cola.push_back(n);
        }
        else if(oper == "back"){
            if(cola.empty()) cout << "No job for Ada?\n";
            else if(!flag){
                cout << cola.front() << "\n";
                cola.pop_front();
            }
            else{
                cout << cola.back() << "\n";
                cola.pop_back();
            }
        }
    }

    return 0;
}