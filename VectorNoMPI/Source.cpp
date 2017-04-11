#include<iostream>

using namespace std;

//functie pentru citirea vectorului
int citirevec(int n, int vec[])
{
 int i;
 for(i=1;i<=n;i++)
{
 cout<<"vec["<<i<<"]=";
 cin>>vec[i];
}
 cout<<"Vectorul a fost citit cu succes!"<<endl;
 return *vec;
}
//functie pentru afisarea vectorului
void afisarevec(int n, int vec[])
{
 int i;
 cout<<"Elementele vectorului sunt:"<<endl;
 for(i=1;i<=n;i++)
{
 cout<<vec[i]<<" ";
}
}

//functie pentru maxim din vector
int max(int n, int vec[])
{
 int i;
 int maxim=0;
 for(i=1;i<=n;i++)
{
 if(vec[i]>maxim)
{
 maxim=vec[i];
}
}
 return maxim;
}

// minim din vector
int min(int n, int vec[])
{
 int i;
 int minim=9999;
 for(i=1;i<=n;i++)
{
 if(vec[i]<minim)
{
 minim=vec[i];
}
}
 return minim;
}
// produsul elementelor nenule
int prod(int n, int vec[])
{
 int i;
 int produs=1;
 for(i=1;i<=n;i++)
{
 if(vec[i]!=0)
{
 produs=produs*vec[i];
}
}
 return produs;
}

//suma elementelor vectorului
int suma(int n, int vec[])
{
 int i;
 int s=0;
 for(i=1;i<=n;i++)
{
 if(vec[i]!=0)
{
 s=s+vec[i];
}
}
 return s;
}

// main part
int main()
{

 int vec[100];
 int n;
 cout<<"elemente vector: "; cin>>n;
 citirevec(n, vec);
 afisarevec(n, vec);
 cout<<endl;
 cout<<"elementul maxim din vector este: "<<max(n, vec)<<endl;
 cout<<"elementul minim din vector este: "<<min(n, vec)<<endl;
 cout<<"produsul elementelor nenule din vector este: "<<prod(n, vec)<<endl;
 cout<<"suma elementelor vectorului este: "<<suma(n, vec)<<endl;
 cout<<" " <<endl;

}