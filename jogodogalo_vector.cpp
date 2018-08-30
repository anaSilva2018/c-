
#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <vector>


using namespace std;

struct matrix{

    vector<vector<string> >v;
}v1;
//iniciar a matrix/tabuleiro com dxd posições
void matrix_inicial(int d)
{

    int i=0,j=0;
  

    v1.v.resize(d);
    for(i=0; i<d; i++)
    {
       v1.v[i].resize(d);

        for (j=0; j<d; j++)
        {
             v1.v[i][j] = "  ";
              cout <<"|" <<v1.v[i][j]<<"|";

              if(j==d-1)
              {
                  cout << endl;
              }

        }
       
      
    
    }


}
//imprimir a matrix/tabuleiro com os valores guardados
void imprimir(int d)
{
     int i=0,j=0;
  
    // d colunas
    v1.v.resize(d);
    for(i=0; i<d; i++)
    {
        //d linhas para cada coluna
       v1.v[i].resize(d);

        for (j=0; j<d; j++)
        {
            
              cout <<"|" <<v1.v[i][j]<<"|";

              if(j==d-1)
              {
                  cout << endl;
              }

        }
       
      
    
    }


}

int jogador_j(int d, int p)
{
    int i=0,j=0;
//se a posicao for valida verifica se a jogada é valida
  if(p< (d*d)+1)
  {
       for(i=0; i<d; i++)
    {
        for(j=0; j<d; j++)
        {
            if(((i*d)+j+1)==p)
            {   //verifica se a posicao está desocupada
                if(v1.v[i][j]=="  ")
                {
                     cout <<"VEZ DO JOGADOR"<<endl;
                      v1.v[i][j]=" X";
                      imprimir(d);
                      return 1;
                }
                else
                {
                     cout <<"!!!!POSICAO OCUPADA!!!"<<endl;  
                     cout <<"INTRODUZA UMA OUTRA POSICAO"<<endl;
                     return 0;
                }
               

            }
        }
    }     
  }
  else
  {
         cout <<"COORDENADAS ERRADAS!!"<<endl;
         cout <<"INTRODUZA UMA OUTRA POSICAO"<<endl;
         return 0;
  }
  

}
//valores aleatorios para a posicao x
void pc_j(int d)
{
    int i=0,j=0, k=0, m=0;
   

    while(v1.v[i][j]!="  ")
    {
         i=rand()%d;
         j=rand()%d;
    }
    cout <<"VEZ DO PC"<<endl;
    v1.v[i][j]=":(";
    imprimir(d);
    
}



// verifica a vitoria/derrota na diagonal principal
int dig_p1(int d,string mark)
{ 
    
    int dig_p1=0, i=0,j=0;
     i=d-1;
     j=d-1;
    
    if(v1.v[d-1][d-1]==mark)
    {
       
       
        while(i>-1 && j >-1)
        {
            if(v1.v[i][j]==mark)
            {
                dig_p1++;
            

                if(dig_p1==d)
                {
                   
                    return 1;
                }
            }
            i--;
            j--;
        }
    }

    else
    {
        return 0;
    }
}
//verifica a vitoria/derrota na outra diagonal
int dig_e1(int d,string mark)
{ 
    
    int dig_e1=0, i=0,j=0;
     i=d-1;
     j=0;
    
    if(v1.v[d-1][0]==mark)
    {
       
        
       
        while(i>-1 && j <d)
        {
            if(v1.v[i][j]==mark)
            {
                dig_e1++;
               

                if(dig_e1==d)
                {
                    
                    return 1;
                }
            }
            i--;
            j++;
        }
    }

    else
    {
        return 0;
    }
}
//vitoria/derrota nas linhas
int linhas(int d, string mark)
{
    int j=0,i=0,lit=0;
    j=d-1;
    for(i=0; i<d; i++)
    {
        if(v1.v[i][d-1]==mark)
        {
            while(j>-1)
            {
                if(v1.v[i][j]== mark)
                {
                  lit++;
                

                   if(lit==d)
                   {
                  
                    return 1;
                 }

                }
                j--;
            }

        }
    }
}
//vitoria/derrota nas colunas
int coluna(int d,string mark )
{
    int colt=0, i=0,j=0;
    i=d-1;
    for(j=0; j<d;j++)
    {
        if(v1.v[d-1][j]==mark)
        {
            while(i>-1)
            {
                if(v1.v[i][j]==mark)
                {
                    colt++;
                    if(colt==d)
                   {
                   
                    return 1;
                 }

                }
              i--;  
            }

        }
    }
}

int vitorias(int d)
{
     if(dig_p1(d," X")==1)
            {
               cout<< "vitoria"<<endl;
                return 1;
            }
     if(dig_e1(d," X")==1)
            {
                 cout<< "vitoria"<<endl;
                return 1;
            }
    if(linhas(d," X")==1)
            {
                 cout<< "vitoria"<<endl;
                return 1;
            }
    if(coluna(d," X")==1)
            {
                 cout<< "vitoria"<<endl;
                return 1;
            }

}

int derrota(int d)
{
     if(dig_p1(d,":(")==1)
            {
               cout<< "perdeu!"<<endl;
                return 1;
            }
     if(dig_e1(d,":(")==1)
            {
                 cout<< "perdeu!"<<endl;
                return 1;
            }
    if(linhas(d,":(")==1)
            {
                 cout<< "perdeu!"<<endl;
                return 1;
            }
    if(coluna(d,":(")==1)
            {
                 cout<< "perdeu!"<<endl;
                return 1;
            }

}
int main()
{
    int dim=0,p=0,pos2=0,t=0, error=0,end_m=0;
    string pos,d;
    loopd:
    cout << "INDIQUE A DIMENSAO DO TABULEIRO(3X3->D=3):";
    cin>>dim;
    if(cin.fail()==1)
    {
        cout <<"ERRO FATAL!!!"<<endl;
        return 0;
                  
     }
    if(dim >0 && error==0)
    {

        cout<< endl;
        matrix_inicial(dim);
        while(1)
        {
            
               loop1:
               cout << "INTRODUZA A SUA POSICAO"<<"(1-"<<dim*dim<<"):";
               cin >> p;
               
                if(cin.fail()==1)
                {
                   cout <<"ERRO FATAL!!!"<<endl;
                   error =1;
                  
                }
                
            
            
            

            if(error==0)
            {   
                    if(jogador_j(dim, p)==0)
                    {
                
                      goto loop1;
                    }
                     t++;

                    if(vitorias(dim)==1)
                    {
                      end_m=1;
               
                     }
                    if(t==dim*dim)
                    {
                 
                     cout <<"FIM DE JOGO!!" <<endl;
                     end_m=1;
               
                    }
                    pc_j(dim);
                    t++;
          
                    if(derrota(dim)==1)
                    {
                     end_m=1;
               
                     }
                    if(t==dim*dim)
                    {
             
                      cout <<"FIM DE JOGO!!" <<endl;
                       end_m=1;
               
                    }
            
            }
            
            
            
           if(end_m==1)
           {
                v1.v.clear();
                if(v1.v.empty())
                {
                     return 0;
                }
           }
            
            if(error==1)
            {  
                return 0;
            }
        }
        
    }

    else
    {
        cout << "ERRO DE DIMENSAO!TENTE OUTRA VEZ!"<<endl;
        goto loopd;
    }
      
    
}
