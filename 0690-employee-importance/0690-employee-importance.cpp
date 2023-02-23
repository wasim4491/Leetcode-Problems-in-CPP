/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        int total = 0;
        queue<int> que;
        unordered_map<int, pair<int, vector<int>>> mp;
        for(int i=0;i<employees.size();i++){
            mp[employees[i]->id] = {employees[i]->importance, employees[i]->subordinates};
        }
        que.push(id);
        while(!que.empty()){
            int sz = que.size();
            while(sz!=0){
                int top = que.front();
                que.pop();
                auto v = mp[top].second;
                total += mp[top].first;
                for(int i=0;i<v.size();i++){
                    que.push(v[i]);
                }
                sz--;
            }
        }
        return total;
    }
};