//
//  ReadDatAndWrite.cpp
//
//  Created by Jane Lin on 2020/5/25.
//  Copyright © 2020 Jane Lin. All rights reserved.
//  If you want to know more details about the code, you can read "REAME.md"
//

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

int main(){
    
    vector<string> vecFp;  //we want all the context of "Fp" file, and this vector is to store the contexts
    vector<string> vecVp;  //we just want some specific columns in "Vp"file
    vector<string> vecFinalVp; //this vector is to store datas that we have selected in "Vp"file
    string temp;

    int Number;
    cout << "请输入你想读取的fp/vp文件名字的共同序号"<<endl;
    cin >> Number;
    string fileNumber = to_str(Number);

    /*notice the address in diffrent PC version， I use Mac。
     *If you use windows，the address may be like("E:\\result\\fp-"+fileNumber+".dat")
     *if your "Fp" and "Vp" file doesn't have similar pattern,you can set address separately
     */
    
    ifstream fpfile("/Users/janelin/Desktop/fp-"+fileNumber+".dat");
    cout<<"开始读取fp文件"<<endl;
    if (!fpfile.is_open()){
        cout << "Unable to open fpfile"<<endl;
        system("pause");
        exit(1);

    }
    while (getline(fpfile, temp))  {  //Each row is read by using getline () and placed into the vector by line units
        vecFp.push_back(temp);
    }
    fpfile.close();
    cout<<"fp文件读取完毕"<<endl;
    
    
     ifstream vpfile("/Users/janelin/Desktop/vp-"+fileNumber+".dat");
    cout<<"开始读取vp文件并删除部分数据"<<endl;
    if (!vpfile.is_open()){
        cout << "Unable to open vpfile"<<endl;
        system("pause");
        exit(1);
    }
    /*
    *//下面3行是为了消除vp文件里的前三行
    *getline(vpfile, temp);
    *getline(vpfile, temp);
    *getline(vpfile, temp);
    */
    while (getline(vpfile, temp))   {  //Each row is read by using getline () and placed into the vector by line units
        vecVp.push_back(temp);
    }
    
    for (auto it = vecVp.begin(); it != vecVp.end(); it++){
        istringstream is(*it);         //initializes a string input stream with each row of data;
        string s;
        int pam = 0;
        temp = "";
        
        while (is >> s)  {   //Take the data from istringstream and put it into sequence s, bounded by space
            if ( pam < 6 || pam > 8 )  {   //Gets data other than columns 7, 8, and 9
                temp += s;
                temp += "   ";
            }

            pam++;
        }
        vecFinalVp.push_back(temp.c_str());
        //cout<<temp<<endl;
    }
    cout<<"vp文件中需要的数据读取完毕"<<endl;
    vpfile.close();
    
    //outfile “　fvp” file
    ofstream fvpfile("/Users/janelin/Desktop/fvp-"+fileNumber+".txt", ofstream::app);

    if(fvpfile.is_open())
    {
        for (auto it = vecFp.begin(); it != vecFp.end(); it++){
            fvpfile<<*it<<"\n";
        }
        //cout<<*vecFp.begin();
        for (auto it = vecFinalVp.begin(); it != vecFinalVp.end(); it++){
            vpfile<<*it<<"\n";
        }
        //cout << *vecFinalVp.begin()；
        fvpfile.close();
        cout << "succced!"<<endl;
    }
    else
    {
        cout<<"can not open the file \n"<<endl;
        return -1;
    }

    //system("pause");
    return 1;
}

