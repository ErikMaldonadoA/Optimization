%ALGORITMO DE KRUSKAL
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

fprintf('\nLa solucion es: \n');  


    nmarcados=0;
    grupo=0;
    ant=0;
    costo=0;
    while nmarcados < b
    
         dmin=inf;
         
         
         for i=1:b
            for j=1:b
                if (A(i,j)<dmin) && (marcados(i)~= marcados(j) || marcados(i)==0 || marcados(j)==0)
                
                    dmin=A(i,j);
                    imin=i;
                    jmin=j;
                    
                end
            end
         end
         
         
         
         A(imin,jmin)=inf;
         A(jmin,imin)=inf;
         
         if marcados(jmin)==0
             ruta(jmin)=imin;
             distancia(jmin)= dmin;
             if jmin~=ant
             fprintf('\nSe selecciona el nodo %g',jmin);
             fprintf(' llegando desde %g',ruta(jmin));
             fprintf(' con una distancia de %g',distancia(jmin));
             fprintf('\n');
             ant=imin;
             costo=costo+distancia(jmin);
             end
             if marcados(imin)==0
                grupo=grupo+1; 
                marcados(jmin)=grupo;
                marcados(imin)=grupo;
                ruta(imin)=jmin;
                distancia(imin)=dmin;
                if imin~=ant
                fprintf('\nSe selecciona el nodo %g',imin);
                fprintf(' llegando desde %g',ruta(imin));
                fprintf(' con una distancia de %g',distancia(imin));
                fprintf('\n');
                ant=jmin;
                costo=costo+distancia(imin);
                end
             else
                 marcados(jmin)=marcados(imin);
             end
         else
             
             if marcados(imin)==0
                 ruta(imin)=jmin;
                 distancia(imin)=dmin;
                 marcados(imin)=marcados(jmin);
                 if imin~=ant
                fprintf('\nSe selecciona el nodo %g',imin);
                fprintf(' llegando desde %g',ruta(imin));
                fprintf(' con una distancia de %g',distancia(imin));
                fprintf('\n');
                ant=jmin;
                costo=costo+distancia(imin);
                 end
             else
                 if ruta(ruta(jmin)-1)==jmin
                     ruta(jmin)=imin;
                     distancia(jmin)=dmin;
                     if jmin~=ant
                    fprintf('\nSe selecciona el nodo %g',jmin);
                    fprintf(' llegando desde %g',ruta(jmin));
                    fprintf(' con una distancia de %g',distancia(jmin));
                    fprintf('\n');
                    ant=imin;
                    costo=costo+distancia(jmin);
                     end
                 else
                    ruta(imin)=jmin;
                    distancia(imin)=dmin;
                    if imin~=ant
                    fprintf('\nSe selecciona el nodo %g',imin);
                    fprintf(' llegando desde %g',ruta(imin));
                    fprintf(' con una distancia de %g',distancia(imin));
                    fprintf('\n');
                    ant=jmin;
                    costo=costo+distancia(imin);
                    end
                 end
                 
                 k=marcados(jmin);
                 for i=1:b
                    if marcados(i)==k
                        marcados(i)=marcados(imin);
                    end
                     
                 end
                 
             end
             
         end
        
         
         
         nmarcados=0;
         for i=1:b
            if marcados(i)>0
                nmarcados=nmarcados+1;
            end
         end
    end
    
      fprintf('\nCosto Total = %g',costo);
   
    fprintf('\n\n');
