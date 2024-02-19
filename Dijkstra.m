%ALGORITMO DE DIJKSTRA
%Integrantes: Ing. Erik Maldonado - Ing. Jheny Rueda
%Maestría en Ing. Industrial, Universidad del Norte

clc
clear all;
%#ok<*SAGROW>

fprintf('Ingrese la matriz de adyacencia: \n\n');

A=input('A = ');

b=length(A);

for i=1:b
    
   marcados(i)=0;
   distancia(i)=inf;
    
end

fprintf('\n');
sw=1;

while sw==1
inicio=input(['Digite el nodo de inicio (1 a ', num2str(b) ,'): ']);

inicio=double(inicio);

if inicio<=b && inicio>=1
    marcados(inicio)=1;
    distancia(inicio)=0;
    sw=0;
    for i=1:(b-1)
    
        for j=1:b
            if marcados(i)>0;
               for k=1:b

                    if marcados(k)==0 && A(j,k)<inf
                       distemp=A(j,k)+distancia(j); 
                        if distemp<distancia(k)
                           distancia(k)=distemp;
                           ruta(k)=j;
                        end
                        
                    end

               end
           
            end
            
        end
    
        dmin=inf;
        for j=1:b
            
            if marcados(j)==0 && distancia(j)<dmin && distancia(j)>=0
                dmin=distancia(j);
                min=j;
            end
        end
        marcados(min)=1;
    end
    
    fprintf('\nLa solucion es: \n');
    
    for i=1:b
       if i~=inicio
           desde=ruta(i);
           dist=distancia(i);
           fprintf('\n');
           fprintf('Al nodo %g', i);
           fprintf(' se llega desde %g', desde);
           fprintf(' con una distancia de %g', dist);
           fprintf('\n');
       end
    end
    
else
    
    fprintf('\nEl nodo inicial no fue ingresado correctamente, Digitelo nuevamente: \n\n');
    sw=1;
    
end
end

fprintf('\n');
