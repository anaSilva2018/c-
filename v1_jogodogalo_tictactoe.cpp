#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>

using namespace std;



struct mat{
string table[3][3];
}mat2;


void iniciar_matrix()
{   
    
    int n,m;
    
    cout <<"BEM-VINDO!"<<endl;

    for(n=0; n< 3;n++)
    {
        
        for(m=0; m< 3;m++)
        {
           
         mat2.table[n][m]="  ";
        std::cout <<"|"<< mat2.table[n][m]<<"|";


            if(m==2)
            {
                std::cout <<std::endl;
                 
            }
        }
    }
}

void imprimir()
{
    int n=0, m=0;
    for(n=0; n<3;n++)
    {
        for(m=0; m<3;m++)
        {
            cout <<"|"<< mat2.table[n][m]<<"|";
            if(m==2)
            {
                cout <<endl;
            }
        }
    }
    cout <<"*********************************************"<<endl;
}


int jogador_j(int p)
{ 
 int n,m,x,y;
 

 switch(p)
 {
    
     case 1: 
     {
         x =0;
         y= 0;
         break;
    }
    case 2: 
     {
         x =0;
         y= 1;
         break;
    }
    case 3: 
     {
         x =0;
         y= 2;
         break;
    }
    case 4: 
     {
         x =1;
         y= 0;
         break;
    }
    case 5: 
     {
         x =1;
         y= 1;
         break;
    }
    case 6: 
     {
         x =1;
         y= 2;
         break;
    }
    case 7: 
     {
         x =2;
         y= 0;
         break;
    }
    case 8: 
     {
         x =2;
         y= 1;
         break;
    }
    case 9: 
     {
         x =2;
         y= 2;
         break;
    }

     default: 
     {
         break;
     }

    

 }


    
 if( x <3 && y <3)
 {
     if( mat2.table[x][y] != "  ")
    {
     cout <<"!!!!POSICAO OCUPADA!!!"<<endl;  
     cout <<"INTRODUZA UMA OUTRA POSICAO"<<endl;
     return 0;
    }
    else
    {
    cout <<"VEZ DO JOGADOR"<<endl;
    mat2.table[x][y]="X ";
    }
     imprimir();
    return 1;

 }
    
  else{
       cout <<"COORDENADAS ERRADAS!!"<<endl;
       cout <<"INTRODUZA UMA OUTRA POSICAO"<<endl;
       return 0;
       
       
  } 

   

}

void pc_j()
{
    int x;
    int y;
     int n,m;

    do
    {
    x= rand()%3;
    y= rand()%3;

    } while(mat2.table[x][y] != "  ");
   
    
        cout <<"VEZ DO PC"<<endl;
        mat2.table[x][y]=":(";
        imprimir();
}



int vitoria()
{
    if(mat2.table[0][0]== "X ")
    {
        if(mat2.table[0][0]==mat2.table[1][1] && mat2.table[1][1]==mat2.table[2][2])
        {
            cout << "VICTORY!"<<endl;
            return 1; 
        }
        else if(mat2.table[0][0]==mat2.table[0][1] && mat2.table[0][1]==mat2.table[0][2])
        {
            cout << "VICTORY!"<<endl; 
              return 1;
        }
        else if(mat2.table[0][0]==mat2.table[1][0] && mat2.table[1][0]==mat2.table[2][0])
        {
            cout << "VICTORY!"<<endl; 
            return 1;
        }
    }



   else if(mat2.table[0][2]== "X ")
    {
        if(mat2.table[0][2]==mat2.table[1][1] && mat2.table[1][1]==mat2.table[2][0])
        {
            cout << "VICTORY!"<<endl; 
            return 1;
        }
        else if(mat2.table[0][2]==mat2.table[1][2] && mat2.table[1][2]==mat2.table[2][2])
        {
            cout << "VICTORY!"<<endl; 
            return 1;
        }
    }

    else if(mat2.table[0][1]== "X ")
    {
        if(mat2.table[0][1]==mat2.table[1][1] && mat2.table[1][1]==mat2.table[2][1])
        {
            cout << "VICTORY!"<<endl; 
            return 1;
        }

    }

    else if(mat2.table[1][2]== "X ")
    {
        if(mat2.table[1][2]==mat2.table[1][1] && mat2.table[1][1]==mat2.table[1][0])
        {
            cout << "VICTORY!"<<endl; 
            return 1;
        }

    }

   else if(mat2.table[2][2]== "X ")
    {
        if(mat2.table[2][2]==mat2.table[2][1] && mat2.table[2][1]==mat2.table[2][0])
        {
            cout << "VICTORY!"<<endl; 
            return 1;
        }

    }
    

}

int derrota()
{
    if(mat2.table[0][0]== ":(")
    {
        if(mat2.table[0][0]==mat2.table[1][1] && mat2.table[1][1]==mat2.table[2][2])
        {
            cout << "THE END :(!"<<endl;
            return 1; 
        }
        else if(mat2.table[0][0]==mat2.table[0][1] && mat2.table[0][1]==mat2.table[0][2])
        {
            cout << "THE END :(!"<<endl; 
              return 1;
        }
        else if(mat2.table[0][0]==mat2.table[1][0] && mat2.table[1][0]==mat2.table[2][0])
        {
            //cout << "THE END :(!"<<endl; 
            return 1;
        }
    }



   else if(mat2.table[0][2]== ":(")
    {
        if(mat2.table[0][2]==mat2.table[1][1] && mat2.table[1][1]==mat2.table[2][0])
        {
            cout << "THE END :(!"<<endl; 
            return 1;
        }
        else if(mat2.table[0][2]==mat2.table[1][2] && mat2.table[1][2]==mat2.table[2][2])
        {
            cout << "THE END :(!"<<endl; 
            return 1;
        }
    }

    else if(mat2.table[0][1]== ":(")
    {
        if(mat2.table[0][1]==mat2.table[1][1] && mat2.table[1][1]==mat2.table[2][1])
        {
            cout << "THE END :(!"<<endl; 
            return 1;
        }

    }

    else if(mat2.table[1][2]== ":(")
    {
        if(mat2.table[1][2]==mat2.table[1][1] && mat2.table[1][1]==mat2.table[1][0])
        {
            cout << "THE END :(!"<<endl; 
            return 1;
        }

    }

   else if(mat2.table[2][2]== ":(")
    {
        if(mat2.table[2][2]==mat2.table[2][1] && mat2.table[2][1]==mat2.table[2][0])
        {
            cout << "THE END :(!"<<endl; 
            return 1;
        }

    }
    

}

int main()
{  
    string pos;
    int p=0,t=0;
    
        iniciar_matrix();
        cout <<"*********************************************"<<endl;
        
        while(1){
            loop1:

                 
            cout <<"INTRODUZA A SUA POSICAO(1-9):"<<endl;
            getline(cin, pos);
            istringstream(pos)>>p;
       
                
            
            if(jogador_j(p)==0)
            {
                 goto loop1;

            }
            t++;
             if(t==9)
            {
                cout <<"FIM DO JOGO "<<endl;
                return 0;
            }
           
            if(vitoria()==1 )
            {
                return 0;
            }
            
            
            pc_j();
            t++;
            if(t==9 )
            {
                cout <<"FIM DO JOGO "<<endl;
                return 0;
            }
        
            if(derrota()==1)
            {
                return 0;
            
            }
             


           

        }
        


       


    

 
    
}

