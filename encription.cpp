#include <bits/stdc++.h>
using namespace std;

int b[7];
void binary(int n)
{

  for(int i=0; i<7; i++)
  {
      b[i]=0;
  }
  
  for(int i=0; n>0; i++)    
  {    
    b[i]=n%2;    
    n= n/2;  
  }    

  
}
int bl[9];
void binl(int n)
{

  for(int i=0; i<9; i++)
  {
    bl[i]=0;
  }
  
  for(int i=0; n>0; i++)    
  {    
    bl[i]=n%2;    
    n= n/2;  
  }    

  
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



string encript_word(string &s) 
{
  string final_encription="";
  char a[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
  char A[26]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
  char sp[29]={'\0', ' ',',','<','>','.','?','/','"',';',':','+','=','-','_',')','(','*','&','^','%','$','#','@','!','~','`', '\'','/'};
  int l=s.size();


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

  int m[8*r][8*r];
  for(int w=0; w<r*8; w++)
  {
    for(int e=0; e<r*8; e++)
    {
      m[w][e]=0;
    }
  }

  
  //encoding
  binl(l);
  for(int i=0; i<9; i++)
  { //0 -.   1- ,  2- -    3-`
   if(bl[i]==0)
   {
     final_encription+='.';
     //cout<<".";
   }else
   {
    final_encription+=',';
   // cout<<",";
   }
    
  }

 

  int stop=0;
  int k=0;
  for(int i=0; i<r; i++)
  {
    for(int j=0; j<r; j++)
    {
      //for(int p=i*8; p<(i+1)*8; p++ )
     // {
        for(int p=i*8; p<(i+1)*8 && k<(j+1)*8*(i+1); p++, k++)
        {
          if(k==l)
          {
            stop=1;
            //cout<<"hi\n";
            break;
          }else
          {
            
             // char c;
             //c=s[k];
             //string s_a = convertToString(c, 1);
             //stringstream geek(s);
             //  int num=0;
             // geek>>num;
             int num=(int)s[k]-48;
             if(num>=0 && num<=9 )
             {
               binary(num);
              // cout<<num<<endl;
               for(int q=j*8; q<(j+1)*8; q++)
               {
                 if(q==j*8)
                 {
                   m[p][q]=2; //2 for integers
                 }else 
                 {
                   m[p][q]=b[q-j*8-1]; //stored in  reverse like 6 : 0 1 1 0 0 0 0
                 }

               }
             }else if(isupper(s[k]))
             {
               int id=0;
               for(int g=0; g<26; g++)
               {
                 if(A[g]==s[k])
                 {
                   id=g;
                   break;
                 }
               }
               binary(id);
               for(int q=j*8; q<(j+1)*8; q++)
               {
                 if(q==j*8)
                 {
                   m[p][q]=1; //1 for uper case
                 }else 
                 {
                   m[p][q]=b[q-j*8-1];
                 }

                }

              }else if(islower(s[k]))
              {
               int id=0;
               for(int g=0; g<26; g++)
               {
                 if(a[g]==s[k])
                 {
                   id=g;
                   break;
                 }
               }
               binary(id);
               for(int q=j*8; q<(j+1)*8; q++)
               {
                 if(q==j*8)
                 {
                   m[p][q]=0; //0 for lower case
                 }else 
                 {
                   m[p][q]=b[q-j*8-1];
                 }

                }
              }else
              {
                int id=0;
               for(int g=0; g<29; g++)
               {
                 if(sp[g]==s[k])
                 {
                   id=g;
                   break;
                 }
               }
               binary(id);
               for(int q=j*8; q<(j+1)*8; q++)
               {
                 if(q==j*8)
                 {
                   m[p][q]=3; //3 for special chars
                 }else 
                 {
                   m[p][q]=b[q-j*8-1];
                 }

                }
              }

          }   
         
        }
        if(stop==1)
        {
          break;
        }
     // }
    }
    if(stop==1)
    {
     break;
    }
  }
  
  for(int w=0; w<r*8; w++)
  {
    //0 -.   1- ,  2- -    3-`
    for(int e=0; e<r*8; e++)
    {
      if(m[w][e]==0)
      {
        //cout<<".";
        final_encription+='.';
      }else if(m[w][e]==1)
      {
      // cout<<",";
       final_encription+=',';
      }else if(m[w][e]==2)
      {
      //  cout<<"-";
        final_encription+='-';
      }else if(m[w][e]==3)
      {
      //  cout<<"`";
        final_encription+='`';
      }
     
    }
  }

  return final_encription;


  

  

}
void read_word_by_word(string filename) 
{
   fstream file;
   string word;
    ofstream f("encripted.txt");
   file.open(filename.c_str());

   while(file >> word) 
   { 
      f <<encript_word(word) <<endl;
    }

   file.close();
}


int main()
{
 // cout<<"enter file name of txt message to encript :";
  string file_name;
  //cin>>file_name;
  file_name="message.txt";
  read_word_by_word(file_name);
}