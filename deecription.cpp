
#include <bits/stdc++.h>
using namespace std;


//int b[7];
int nm=0;
void binary(int arr[],int n)
{
  nm=0;
  
  
  for(int i=0; i<n; i++)    
  {    
    nm=nm+pow(2,i)*arr[i];
  }    

  //cout<<nm<<" ";
  
}




string convertToString(char* a, int size)
{
    int i;
    string s = "";
    for (i = 0; i < size; i++) {
        s = s + a[i];
    }
    return s;
}



string decrypt_word(string &ppp) 
{
  nm=0;
 // char s[5000];//word limit
  string s="";
  int len[9];
  for(int i=0; i<9; i++)
  {  //0 -.   1- ,  2- -    3-`
    char qw;
    qw=ppp[i];
    if(qw=='.')
    {
     len[i]=0;
    }
    else
    {
     len[i]=1;
    }
  }
  
  binary(len,9);
  char a[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
  char A[26]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
  char sp[29]={'\0', ' ',',','<','>','.','?','/','"',';',':','+','=','-','_',')','(','*','&','^','%','$','#','@','!','~','`', '\'','/'};
  
  //here we take input for length 
  //cin>>nlength string having value encoded strening lenth of text
  int l=nm;
  int size=1*8;  //1x8x8 size
  int d=l/8;
  if(d*8!=l)
  {
    d=d+1;
  }
  int r= sqrt(d);
  if(r*r!=d)
  {
    r=r+1;
  }
  //cout<<r;
  int idxx=9;
  int m[8*r][8*r];
  for(int i=0; i<8*r; i++)
  {
    for(int j=0; j<8*r; j++)
    {//0 -.   1- ,  2- -    3-`
      char ed;
      ed=ppp[idxx];
      idxx++;
       if(ed=='.')
      {
        m[i][j]=0;
      }else if(ed==',')
      {
       m[i][j]=1;
      }else if(ed=='-')
      {
        m[i][j]=2;
      }else if(ed=='`')
      {
        m[i][j]=3;
      }
      
    }
  }

  //decoding
  int stop=0;
  int k=0;
  for(int i=0; i<r; i++)
  {
    for(int j=0; j<r; j++)
    {
        for(int p=i*8; p<(i+1)*8 && k<(j+1)*8*(i+1); p++, k++)
        {
            if(k==l)
            {
              //cout<<"bcz of this\n";
              stop=1;
              break;
            }else   //first alpha -> type // next 8 bits according to sequence
                //rajni->!2QA
            {
              //int num=(int)s[k]-48;
             
               
               //cout<<num<<endl;
               int arr[7];
               for(int q=j*8; q<(j+1)*8; q++)
               {
                 
                 if(q>j*8)
                {
                   
                   arr[q-(j*8)-1]=m[p][q];//ascii value //stored in  reverse like 6 : 0 1 1 0 0 0 0
                }
                 

              }
                
                 binary(arr,7);
                 //cout<<nm<<endl;
                if(m[p][j*8]==2)
                {
                  string stri = to_string(nm);
                  s+=stri[0];
                  //2 for integers
                
                 }else if(m[p][j*8]==1)
                 {
                   s+=A[nm];
                 }else if(m[p][j*8]==0)
                 {
                   s+=a[nm];
                 }else if(m[p][j*8]==3)
                 {
                   s+=sp[nm];
                 }

            }
      
        }
        if(stop==1)
        {
          break;
        }
     
    }
    if(stop==1)
    {
     break;
    }
  }


  return s;
 
} 

void read_word_by_word(string filename) 
{
   fstream file;
   string word;
   ofstream f("regenerated_message.txt");

   file.open(filename.c_str());
    while(file >> word) 
    {  
      f <<decrypt_word(word) << " ";
    }

    file.close();
}

int main()
{
  
  string file_name;
  //cin>>file_name;
  file_name="encripted.txt";
  read_word_by_word(file_name);

}