//Algoritmo Genético
// Elaborado por: Erik Maldonado
//Junio 30 de 2010


# include <iostream> 
# include <vector>
# include <math.h>
# include <time.h>


using namespace std;

int main()
{
    vector<int>par;
    
    double mb[100][100], n,vx[100], yi[100], p[100] ,y, pt, qi[100], al1, al2, grup[100], mb2[100][100], t;
    int  i, j, tam, alt, n1, n2, sw;
    
    vector <int> vector1;
    vector <int> vector2;
    vector <int> vector3;
    vector <int> vector4;
    vector <int> vector5;
    vector <int> vector6;
    
    cout<<"<<<<<ALGORITMO GENETICO>>>>>"<<endl<<endl;
 
    do{
    t=10000000;
    
    srand(time(0));
 
 // Lectura datos máquinas (m) y trabajos (n), matriz: MT[m][n], matriz makespan: MS[m][n].
 // Generar soluciones iniciales
 // Utilizar matriz de soluciones
 
    for(i=0;i<n;i++){
    vector1.insert(vector1.end(),i+1);
    vector2.insert(vector1.end(),i+1);
    vector3.insert(vector1.end(),i+1);
    vector4.insert(vector1.end(),i+1);
    vector5.insert(vector1.end(),i+1);
    vector6.insert(vector1.end(),i+1);
    }
    
    random_shuffle(vector1.begin(),vector1.end());
    random_shuffle(vector2.begin(),vector2.end());
    random_shuffle(vector3.begin(),vector3.end());
    random_shuffle(vector4.begin(),vector4.end());
    random_shuffle(vector5.begin(),vector5.end());
    random_shuffle(vector6.begin(),vector6.end());
    
    while(t>10){
    
    // Se reinician las variables que indican que secuencia es mejor (Funciones Objetivo y Porcentajes)
    //y1=suma de los makespan y yf1(i)= makespan de cada secuencia
    //y2=suma de los flujos y yf2(i)= flujo de cada secuencia
    
    y1=0;
    y2=0;
    pt1=0;
    pt2=0;  
    
    for (i=0;i<6;i++){
    yf1[i]=0;
    p1[i]=0;
    q1[i]=0;
    yf2[i]=0;
    p2[i]=0;
    q2[i]=0;
    }
    
    // Aqui comienza calculo Makespan
    MS[0][0]= MT[vector1[0]][0];
    for (j=1;j<m;j++)
    MS[0][j]= MT[vector1[0]][j]+MS[vector1[0]][j-1];
    
    for (i=1;i<n;i++)
    MS[i][0]= MT[vector1[i]][0]+MS[vector1[i-1]][0];
    
    for (i=1;i<n;i++){
    for (j=1;j<m;i++){
        
    if (MS[i][j-1]<MS[i-1][j])
    MS[i][j]=MS[i-1][j]+MT[vector1[i]][j];
    else
    MS[i][j]=MS[i][j-1]+MT[vector1[i]][j];
    
    }
    }
    yf1[0] = MS[n][m];
    
    for (k=0;k<n;k++){
    yf2[k]=MS[k][m-1]
    y2=y2+yf2[k]
    }
    
    y1=y1+yf1[0];
    //resetear matriz makespan
    // Aqui termina calculo Makespan
    // En este punto se haria para el siguiente vector
    
    for (i=0;i<6;i++){
    p1[i]=1-(yf1[i]/y1);
    pt1=pt1+p1[i];
    p2[i]=1-(yf2[i]/y2);
    pt2=pt2+p2[i];
    }
    
    q1[0]=(p1[0]/pt1)*100;
    q2[0]=(p2[0]/pt2)*100;
    
    for (i=1;i<6;i++){
    q1[i]=q1[i-1]+((p1[i]/pt1)*100);
    q2[i]=q2[i-1]+((p2[i]/pt2)*100);
    }
    
    al1=(0+rand()%100);
    al2=(0+rand()%100);
    
    for (i=0;i<6;i++){
    if (al1<q1[i]){
    sec1=i;
    i=6;}
    
    for (i=0;i<6;i++){
    if (al2<q2[i]){
    sec2=i;
    i=6;}
    
    
    // Se cruzan las dos secuencias
    // se repite hasta sacar 6 hijos
 
    t=t*0.999;
    //se baja la temperatura y se repite el proceso
    }
        
    cout<<"Las solucion encontrada es:"<<endl<<endl;
    
    
    cout<<"Valor x = "<<vx[0]<<"\t Y = "<<yi[0]<<endl;
    cout<<endl;
    cout<<"\nDesea repetir el algoritmo?, Si(1) o No (2): ";
    cin>>sw;
    cout<<endl;
    
    
    }while(sw==1);
    
    cout << "\nPresione ENTER para terminar";
    cin.get();
    return 0; 
        
}
     
