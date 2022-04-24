#include<iostream>
#include<fstream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

bool sortbysec(const pair<int,int> &a,
              const pair<int,int> &b)
{
    return (a.second < b.second);
}

int main(){
    //getting input from files
        ofstream wrt;
        ifstream read;
        wrt.open("Output.txt",ios::app);
        read.open("input.txt",ios::in);
        int n;
        read>>n;
        vector<vector<int> > lane;

        for(int i = 0; i < n; i++){
            vector<int> temp;
            string str ;
            int t=0;
            getline(read,str,']');
            for(int j = 0; j<str.size(); j++){

                if (str[j]-'0' != -38 && str[j] != ',' && str[j] != '[' && str[j] != ']')//space, ',' , [ , ]
                {
                    t=t*10+(str[j]-'0');
                    if(str[j+1]==','){
                        temp.push_back(t);//str[j]-48
                        t=0;
                    }
                }
            }
            temp.push_back(t);
            lane.push_back(temp);
            temp.clear();
        }
    //vector loaded//

    int count[2000]={0};
    int timesum[n]={0};
    for(int i=0;i<lane.size();i++){
        for(int j=0;j<lane[i].size();j++){
            if(count[lane[i][j]]==0){
                count[lane[i][j]]=1;
                timesum[i]+=lane[i][j];
            }
        }
        for(int a=0;a<2000;a++){
            count[a]=0;
        }
    }

    vector<pair<int,int>> ans;
    for(int i=1;i<=n;i++){
        ans.push_back(make_pair(i,timesum[i-1]));
    }

    sort(ans.begin(),ans.end(),sortbysec);

    wrt<<"[";
    for(int i=0;i<n-1;i++){
        // cout<<ans[i].first<<" "<<ans[i].second<<endl;
        wrt<<ans[i].first<<", "<<ans[i].second<<", ";
    }wrt<<ans[n-1].first<<", "<<ans[n-1].second;
    wrt<<"]"<<endl;
    return 0;
}