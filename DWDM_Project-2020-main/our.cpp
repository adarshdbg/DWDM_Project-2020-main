#include<bits/stdc++.h>
using namespace std;

int main(){
    
    clock_t start, end; 
    start = clock(); 
    cout<<"\n\nEnter K value and Input Item : \n\n"<<endl;
    int inpk;
    cin>>inpk;
    char input;
    cin>>input;
    vector<vector<pair<int,char>>>v(26,vector<pair<int,char>>(26));
    fstream newfile;
    int temp = 0;
    newfile.open("dataset/db.txt",ios::in);
    cout<<"\nComputing elements...\n";
    std::chrono::seconds dura( 5);
    std::this_thread::sleep_for( dura );
    for(int j=0;j<26;j++)
    {
        if (newfile.is_open()){
            string tp;
            char pp='a'+j;
            while(getline(newfile, tp)){
                // cout << tp << "\n";
                int k = tp.length();
                for(int i=0;i < tp.size();i++)
                {
                    if(tp[i]==pp)
                    {
                        k=i;
                        break;
                    }
                }
                for(int i=k+1;i<tp.size();i++)
                {
                    v[j][tp[i]-'a'].second=tp[i];
                    v[j][tp[i]-'a'].first++;
                }
            }
            newfile.close();
        }
    }
    for(int i=0;i<26;i++)
    {
        sort(v[i].begin(),v[i].end(),greater<pair<int,char>>());
    }
    vector<int>ans(inpk);
    for(int i=0;i<inpk;i++)
    {
        ans[i]=v[inpk-'a'][i].first;
    }

    cout<<"\n";
    cout<<"\n";
    cout<<"\n";
    cout<<"These are the top K elements we have : \n\n\n";
    cout<<"\t\t-------\n";
    for(int i=0;i<min(inpk,(int)ans.size());i++)
    {
        cout<<"\t\t|  "<<ans[i]<<"  |\n";
        cout<<"\t\t-------\n";
    }
    cout<<"\n\n";
    end = clock(); 
    // double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    // cout << "\e[1mTime taken by program is : \e[0m" <<fixed  << time_taken << setprecision(5); 
    // cout << " sec " << endl; 
    // cout << "Time taken by program is : " << fixed  << time_taken << setprecision(5); 
    // cout << " sec " << endl; 
    return 0;
}
