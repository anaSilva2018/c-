#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <map>
#include <vector>
#include <fstream>

using namespace std;

class unidade{
    public:
    
   
    map<string, string>nome;
    map<string, int>ects;
    map<string, float>comp_pl;
    map<string, float>notapl;
    map<string, float>compt;
    map<string, float>notat;


    
    float medianormal(string designacao)
    { int i=0;
    
     float media;
     map<string, float> m;
   
             if((comp_pl[designacao]+compt[designacao]) !=1.0 || notapl[designacao] >20 || notat[designacao]>20|| notat[designacao] <0 || notapl[designacao]<0 || comp_pl[designacao]<0||compt[designacao]<0)
              {
               
                 return 0;
              }
                else
             {
               media=compt[designacao]*notat[designacao]+comp_pl[designacao]*notapl[designacao];
               m[designacao]=media;
              // cout << designacao<<"->media:"<<m[designacao]<<endl;
                return  m[designacao];
              }
            
        

      
      
    }

};


int main()
{
    
    unidade uc1;
    int i=0,total=0, error=0;
    string deg;

  
    cout << "insira o numero de uc's a inserir:";
    cin >> total;
    cout << endl;

    
  
    while(i<total)
    {
        cout <<"***********************UC["<<i+1<<"]************************"<<endl;
        i++;
        cout <<"DESIGNAÇAO:";
        cin >>deg;
        cout <<"NOME:";
        cin >>uc1.nome[deg];
        cout << "ECTS:";
        cin >> uc1.ects[deg];
        if(cin.fail())
        {
             error=1;
        }
        
        if(error ==0)
        {
              cout <<"PERCENTAGEM DA COMP.PL:";
              cin >>uc1.comp_pl[deg];
              if(cin.fail())
              {
                error=1;
              }
        }
      
        
        if(error ==0)
        {
            cout <<"PERCENTAGEM DA COMP T:";
            cin>>uc1.compt[deg];
             if(cin.fail())
             {
               error=1;
             }
        }
        
       
        if(error ==0)
        {
             cout<<"NOTA PL:";
             cin>>uc1.notapl[deg];
              if(cin.fail())
              {
               error=1;
              }
        }
       
      
         if(error ==0)
         {
              cout<<"NOTA T:";
              cin>>uc1.notat[deg];
               if(cin.fail())
               {
                  error=1;
               }
               cout << endl;
              

        }
       
       if(error ==0)
       {
       
        ofstream texto("mapandclasses.txt",ios::app);
       
       
        if(texto.is_open() && uc1.medianormal(deg)!=0)
        {
            texto <<"["<< deg<<"]"<<uc1.nome[deg]<<"("<<uc1.ects[deg]<<" ects)"<<":"<<uc1.medianormal(deg)<<" valores\n";
            texto.close();
        }
        else{
          
            error=1;
           
        }
       }
        
    }
  
    
   
    
    if(error==1)
    {
        cout <<"erro na insercao de dados!!"<<endl;
        return 0;
    }
   

}