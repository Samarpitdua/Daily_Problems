class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int ct=0,u=students.size(),i=0;
        while(1)
        {
            if(students.size()==0 or i==sandwiches.size())
                break;
            if(students[0]==sandwiches[i])
                ct++,students.erase(students.begin()),i++;
            else
            {
                int sz=students.size();
                int p=0;
                for(int j=0;j<sz;j++){
                    students.push_back(students[0]),students.erase(students.begin());
                    if(students[0]==sandwiches[i])
                    {
                        ct++,students.erase(students.begin()),i++;
                        p=1;
                        break;
                    }
                }
                if(p==0)
                    return u-ct;
            }
            
        }
        return u-ct;
    }
};
