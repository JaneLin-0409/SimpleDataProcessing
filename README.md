# SimpleDataProcessing
## 1.use various language to process some datas in some files to improve efficiency
  Select specific columns of data in "fp" file into "fvp" file;
  Copy dat in "vp" file into "fvp" file;  
  <img src="https://github.com/JaneLin-0409/SimpleDataProcessing/blob/master/IMG/FpVp.png" width="150" height="150" alt="图片加载失败时，显示这段字"/>
  <img src="https://github.com/JaneLin-0409/SimpleDataProcessing/blob/master/IMG/ProblemVp.jpg" width="150" height="150" alt="图片加载失败时，显示这段字"/>
    
  *readDatAndWrite.cpp:*
  ### 1-1: There are two kinds of files, fp and vp, whose names are interlinked at the end, in this case, 500.
  ···
  
    vector<string> vecFp;  //we want all the context of "Fp" file, and this vector is to store the contexts
    vector<string> vecVp;  //we just want some specific columns in "Vp"file
    vector<string> vecFinalVp; //this vector is to store datas that we have selected in "Vp"file
    string temp;

    int Number;
    cout << "请输入你想读取的fp/vp文件名字的共同序号"<<endl;
    cin >> Number;
    string fileNumber = to_str(Number);
  ···
  ### 1-2 store the context of "Fp" into vector
  ···
  
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
  ···
    
  ### 1-3 select specific data of "Vp"File into a vector
  ···
    
    ifstream vpfile("/Users/janelin/Desktop/vp-"+fileNumber+".dat");
      cout<<"开始读取vp文件并删除部分数据"<<endl;
      if (!vpfile.is_open()){
          cout << "Unable to open vpfile"<<endl;
          system("pause");
          exit(1);
      }
    
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
    
  ···
  
  ### 1-4 create a txt to store all we have sored in the two vectors
  ```
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

  ```
  ***To view the source code, please see the readAndWrite.cpp ***
  
  ## 2. to be continued
  
