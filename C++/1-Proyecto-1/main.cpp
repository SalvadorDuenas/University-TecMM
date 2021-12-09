#include<iostream>

using namespace std;

int main()
{
    int bt[50],p[50],te[50],tat[50],pr[50],x,z,n,total=0,pos,temp,promedio_te,promedio_tat;
    cout<<"Ingrese numero total de procesos\n";
    cin>>n;

    cout<<"\nIngrese tiempo de ejecucion y prioridad\n";
    for(x=0;x<n;x++)
    {
        cout<<"\nP["<<x+1<<"]\n";
        cout<<"tiempo de ejecucion:";
        cin>>bt[x];
        cout<<"Prioridad:";
        cin>>pr[x];
        p[x]=x+1;
    }


    for(x=0;x<n;x++)
    {
        pos=x;
        for(z=x+1;z<n;z++)
        {
            if(pr[z]<pr[pos])
                pos=z;
        }

        temp=pr[x];
        pr[x]=pr[pos];
        pr[pos]=temp;

        temp=bt[x];
        bt[x]=bt[pos];
        bt[pos]=temp;

        temp=p[x];
        p[x]=p[pos];
        p[pos]=temp;
    }

    te[0]=0;
    for(x=1;x<n;x++)
    {
        te[x]=0;
        for(z=0;z<x;z++)
            te[x]+=bt[z];

        total+=te[x];
    }

    promedio_te=total/n;
    total=0;

    cout<<"\nProceso\tTiempo de ejecucion  Tiempo de espera  Tiempo de vuelta";
    for(x=0;x<n;x++)
    {
        tat[x]=bt[x]+te[x];
        total+=tat[x];
        cout<<"\nP["<<p[x]<<"]\t\t  "<<bt[x]<<"\t\t    "<<te[x]<<"\t\t\t"<<tat[x];
    }

    promedio_tat=total/n;
    cout<<"\n\ntiempo de espera promedio="<<promedio_te;
    cout<<"\nTiempo de vuelta promedio="<<promedio_tat;

    return 0;
}
