//PROYECTO FINAL INFORMÁTICA AVANZADA
//ELABORADO POR: ERIK MALDONADO
//RECOCIDO SIMULADO PARA SECUENCIACIÓN DE TAREAS
//15 DE JULIO 2010

#include <iostream>
#include <math.h>
#include <vector>
#include <fstream>
#include <time.h>


using namespace std;

int main ()
{
    int caso, i, j, m, n, solucion, makespam1, makespam2,  rep, l, deltamks;
    long double temp, k, alpha;
    
    cout<<"<<<<<SECUENCIACION DE TAREAS CON RECOCIDO SIMULADO>>>>>"<<endl<<endl;
    
    cout<<"Elija el numero de maquinas y trabajos a secuenciar:\n\n";
    
    cout<<"1) 5  Maquinas 20  Trabajos"<<endl;
    cout<<"2) 10 Maquinas 50  Trabajos"<<endl;
    cout<<"3) 10 Maquinas 100 Trabajos"<<endl;
    cout<<"4) 20 Maquinas 200 Trabajos\n\n";
    
    cout<<"Opcion #: ";
    cin>>caso;
    
    cout<<endl<<"Digite la temperatura inicial: ";
    cin>>temp;
    cout<<endl<<"Digite el factor de enfriamiento k: ";
    cin>>k;
    cout<<endl<<"Digite el numero de replicas: ";
    cin>>rep;

    ifstream abrir_archivo;
    
    if (caso==1){
    abrir_archivo.open("caso1.txt");
    m=5;
    n=20;
    }
    if (caso==2){
    abrir_archivo.open("caso2.txt");
    m=10;
    n=50;
    }
    if (caso==3){
    abrir_archivo.open("caso3.txt");
    m=10;
    n=100;
    }
    if (caso==4){
    abrir_archivo.open("caso4.txt");
    m=20;
    n=200;         
    }
    
    int  M1[m][n];
    
    for(i=0;i<m;i++){
    for(j=0;j<n;j++){
    abrir_archivo>>M1[i][j];
    }
    }
    
    abrir_archivo.close();
    
    srand(time(0));
    
    int M2[100][200];
    int vsol[n];
    int M3[100][200];
    
    vector <int> vector1;

    for(i=0;i<n;i++)
    vector1.insert(vector1.end(),i+1);
    
    random_shuffle(vector1.begin(),vector1.end());

    M2[0][0]=0;    
    
    for(i=1;i<m;i++){
    M2[i][0]=M2[i-1][0] + M1[i-1][vector1[0]-1];
    }
      
    for(j=1;j<n;j++){
    M2[0][j]=M2[0][j-1] + M1[0][vector1[j-1]-1];
    }
   
    for(i=1;i<m;i++){
    for(j=1;j<n;j++){
    if ((M2[i-1][j] + M1[i-1][vector1[j]-1])<(M2[i][j-1]+M1[i][vector1[j-1]-1])){
    M2[i][j]=(M2[i][j-1]+M1[i][vector1[j-1]-1]);
    }
    else{
    M2[i][j]=(M2[i-1][j] + M1[i-1][vector1[j]-1]);   
    }
    }
    }
    
    solucion=(M2[m-1][n-1]+M1[m-1][vector1[n-1]-1]);
    
    cout<<"\n\nEl Makespam inicial encontrado es: "<<solucion<<endl;
    
    int rand1, rand2, vector2[n];
    
    while(temp>1)
    {
        for (l=1;l<=rep;l++){
        
        rand1=(0+rand()%n);
        rand2=(0+rand()%n);
   
        for (i=0;i<n;i++)
        {
        vector2[i]=vector1[i];
        }
         
         vector2[rand1]=vector1[rand2];
         vector2[rand2]=vector1[rand1];
        
        for (i=0;i<m;i++){
        for (j=0;j<n;j++){
            M2[m][n]=0;
            M3[m][n]=0;
        }
        }
       
        makespam1=0;
        makespam2=0;
    
        for(i=1;i<m;i++){
        M2[i][0]=M2[i-1][0] + M1[i-1][vector1[0]-1];
        }
          
        for(j=1;j<n;j++){
        M2[0][j]=M2[0][j-1] + M1[0][vector1[j-1]-1];
        }
       
        for(i=1;i<m;i++){
        for(j=1;j<n;j++){
        if ((M2[i-1][j] + M1[i-1][vector1[j]-1])<(M2[i][j-1]+M1[i][vector1[j-1]-1])){
        M2[i][j]=(M2[i][j-1]+M1[i][vector1[j-1]-1]);
        }
        else{
        M2[i][j]=(M2[i-1][j] + M1[i-1][vector1[j]-1]);   
        }
        }
        }
        
        makespam1=(M2[m-1][n-1]+M1[m-1][vector1[n-1]-1]);
        
        M2[0][0]=0; 
        
        for(i=1;i<m;i++){
        M3[i][0]=M3[i-1][0] + M1[i-1][vector2[0]-1];
        }
          
        for(j=1;j<n;j++){
        M3[0][j]=M3[0][j-1] + M1[0][vector2[j-1]-1];
        }
       
        for(i=1;i<m;i++){
        for(j=1;j<n;j++){
        if ((M3[i-1][j] + M1[i-1][vector2[j]-1])<(M3[i][j-1]+M1[i][vector2[j-1]-1])){
        M3[i][j]=(M3[i][j-1]+M1[i][vector2[j-1]-1]);
        }
        else{
        M3[i][j]=(M3[i-1][j] + M1[i-1][vector2[j]-1]);   
        }
        }
        }
        
        makespam2=(M3[m-1][n-1]+M1[m-1][vector2[n-1]-1]);
     
        deltamks=makespam2-makespam1;
        
        
        if (deltamks<=0){
        
        for (i=0;i<n;i++)
        vector1[i]=vector2[i];
        
        if (makespam2<solucion){
        solucion=makespam2;
        for(i=0;i<n;i++){
        vsol[i]=vector2[i];}
        }
        
        }
        
        else{
             
        alpha=(0+rand()%100);
        alpha=alpha/100;
              
        if (alpha<=exp(-deltamks/temp))
        {
          for (i=0;i<n;i++)
           vector1[i]=vector2[i];
        }
        }
        }
        temp=temp*k;
    }
    
    cout<<endl<<"El mejor Makespam encontrado es: "<<solucion<<endl;
    
    cout<<"\nLa secuencia es:\n\n(";
    for(i=0;i<n-1;i++)
    cout<<vsol[i]<<",";
    cout<<vsol[n-1]<<")\n\n";
    
   //Para mantener la ventana abierta 
    cin.ignore (256,'\n');
    cout << "\nPresione ENTER para terminar";
    cin.get();
    
    return 0; 
}

