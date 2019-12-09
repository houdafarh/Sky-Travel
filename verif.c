#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtkclist.h>
#include <gdk/gdkkeysyms.h>
#include <gtk/gtk.h>
#include "verif.h"

int verif(char login[],char password[])
{	
	FILE*f;
	f=fopen("/home/aziz/Desktop/st1999/st7/src/personne.txt","r");
	int i=0;int c=-1;nouveau n;
	FILE*Ftemp;
	Ftemp=fopen("/home/aziz/Desktop/st1999/st7/src/datatemp.txt","w");
	if(f!=NULL)
	{
	while(fscanf(f,"%s %s %s %s %s %s %d\n",n.nom,n.login,n.password,n.email,n.cin,n.num,&n.id)!=EOF)
	{
		if(strcmp(n.login,login)==0 && strcmp(n.password,password)==0)
		{
			c=n.id;
			fprintf(Ftemp,"%s %s %s %s %s %s %d\n",n.nom,n.login,n.password,n.email,n.cin,n.num,n.id);
		}
	}
	}
	rewind(f);
	fclose(f);
	fclose(Ftemp);
	return(c);
}
void supprimer(char login[],char password[])
{
	FILE*f;
	FILE*ftemp;
	nouveau n;
	f=fopen("/home/aziz/Desktop/st1999/st7/src/personne.txt","r");
	ftemp=fopen("/home/aziz/Desktop/st1999/st7/src/per.txt","w");
	while(fscanf(f,"%s %s %s %s %s %s %d\n",n.nom,n.login,n.password,n.email,n.cin,n.num,&n.id)!=EOF)
		{				
			if(strcmp(login,n.login)!=0 && strcmp(password,n.password)!=0)
				fprintf(ftemp,"%s %s %s %s %s %s %d\n",n.nom,n.login,n.password,n.email,n.cin,n.num,n.id);
		}
	fclose(f);
	fclose(ftemp);
	remove("/home/aziz/Desktop/st1999/st7/src/personne.txt");
	rename("/home/aziz/Desktop/st1999/st7/src/per.txt","/home/aziz/Desktop/st1999/st7/src/personne.txt");
}
void ajouter(nouveau n)
{
	FILE*f;
	f=fopen("/home/aziz/Desktop/st1999/st7/src/personne.txt","a+");
	fprintf(f,"%s %s %s %s %s %s %d\n",n.nom,n.login,n.password,n.email,n.cin,n.num,n.id);
	fclose(f);
}
void ajouter_agent(nouveau n)
{
	FILE*f;
	f=fopen("/home/aziz/Desktop/st1999/st7/src/agents.txt","a+");
	fprintf(f,"%s %s %s %s %s %s %d\n",n.nom,n.login,n.password,n.email,n.cin,n.num,n.id);
	fclose(f);
}
void supprimer_agent(char login[],char password[])
{
	FILE*f;
	FILE*ftemp;
	nouveau n;
	f=fopen("/home/aziz/Desktop/st1999/st7/src/agents.txt","r");
	ftemp=fopen("/home/aziz/Desktop/st1999/st7/src/per.txt","w");
	while(fscanf(f,"%s %s %s %s %s %s %d\n",n.nom,n.login,n.password,n.email,n.cin,n.num,&n.id)!=EOF)
		{				
			if(strcmp(login,n.login)!=0 && strcmp(password,n.password)!=0)
				fprintf(ftemp,"%s %s %s %s %s %s %d\n",n.nom,n.login,n.password,n.email,n.cin,n.num,n.id);
		}
	fclose(f);
	fclose(ftemp);
	remove("/home/aziz/Desktop/st1999/st7/src/agents.txt");
	rename("/home/aziz/Desktop/st1999/st7/src/per.txt","/home/aziz/Desktop/st1999/st7/src/agents.txt");
}
void supprimerlv(char type[],char nch[])
{	lv lv;
	FILE*f;
	FILE*ftemp;
	f=fopen("/home/aziz/Desktop/st1999/st7/src/lv.txt","r");    
	ftemp=fopen("/home/aziz/Desktop/st1999/st7/src/lvtemp.txt","w");
	while(fscanf(f,"%s %s %s %s %s\n",lv.type,lv.nch,lv.date_a,lv.date_r,lv.prix)!=EOF)
    	{
        	if(strcmp(lv.type,type)!=0 && strcmp(lv.nch,nch)!=0)
        		{
            			fprintf(ftemp,"%s %s %s %s %s\n",lv.type,lv.nch,lv.date_a,lv.date_r,lv.prix);
        		}
        
        
    	}

    
    	fclose(f);
    	fclose(ftemp);
    	remove("/home/aziz/Desktop/st1999/st7/src/lv.txt");
    	rename("/home/aziz/Desktop/st1999/st7/src/lvtemp.txt","/home/aziz/Desktop/st1999/st7/src/lv.txt");
    
}
void ajouter_client(nouveau n)
{
	FILE*f;
	f=fopen("/home/aziz/Desktop/st1999/st7/src/clients.txt","a+");
	fprintf(f,"%s %s %s %s %s %s %d\n",n.nom,n.login,n.password,n.email,n.cin,n.num,n.id);
	fclose(f);
}
void supprimer_client(char login[],char password[])
{
	FILE*f;
	FILE*ftemp;
	nouveau n;
	f=fopen("/home/aziz/Desktop/st1999/st7/src/clients.txt","r");
	ftemp=fopen("/home/aziz/Desktop/st1999/st7/src/per.txt","w");
	while(fscanf(f,"%s %s %s %s %s %s %d\n",n.nom,n.login,n.password,n.email,n.cin,n.num,&n.id)!=EOF)
		{				
			if(strcmp(login,n.login)!=0 && strcmp(password,n.password)!=0)
				fprintf(ftemp,"%s %s %s %s %s %s %d\n",n.nom,n.login,n.password,n.email,n.cin,n.num,n.id);
		}
	fclose(f);
	fclose(ftemp);
	remove("/home/aziz/Desktop/st1999/st7/src/clients.txt");
	rename("/home/aziz/Desktop/st1999/st7/src/per.txt","/home/aziz/Desktop/st1999/st7/src/clients.txt");
}
