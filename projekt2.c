#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct Z{
	char kat[53],mie[53],uli[103],pop[203];
	int roz,cen;
	struct Z *dalsi;
}ZAZ;

void n(FILE **f, int *i, ZAZ **prvy){
	char a[50];
	int h;
	ZAZ *pos = *prvy;
	if (*i!=0){
		for (h=0;h<*i;h++){
			pos=NULL;
			free(pos);
		}
		*i=0;
	}
	h=0;
	pos = *prvy;
	if ((*f=fopen("reality.txt","r"))==NULL){
		printf("nepodarilo sa nacitat");
	}
	else{
		*i=h;
		while(fgets(a,40,*f)!=NULL){
			++*i;
			fgets(pos->kat,50,*f);
			strtok(pos->kat,"\n");
			fgets(pos->mie,50,*f);
			strtok(pos->mie,"\n");
			fgets(pos->uli,100,*f);
			strtok(pos->uli,"\n");
			fscanf(*f,"%d",&pos->roz);
			fgets(a,40,*f);
			fscanf(*f,"%d",&pos->cen);
			fgets(a,40,*f);
			fgets(pos->pop,200,*f);
			strtok(pos->pop,"\n");
			pos->dalsi=(ZAZ *)malloc(sizeof(ZAZ));
			pos=pos->dalsi;
		}
		printf("Nacitalo sa %d zaznamov\n", *i);
	}
}

void v(int i, ZAZ *prvy){
	if (i==0){
		return;
	}
	else{
		int count;
		ZAZ *pos = prvy;
		for (count=1;count<i+1;count++){
			printf("%d.\n", count);
			printf("kategoria ponuky:%s\n", pos->kat);
			printf("miesto ponuky:%s\n", pos->mie);
			printf("ulica:%s\n", pos->uli);
			printf("rozloha v m2:%d\n", pos->roz);
			printf("cena:%d\n", pos->cen);
			printf("popis:%s\n", pos->pop);
			pos=pos->dalsi;
		}
	}
}

void p(int *i, ZAZ **prvy){
	ZAZ *novy=(ZAZ *)malloc(sizeof(ZAZ));
	int a=0,k,n2;
	char c,n1[203];
	scanf("%d", &k);
	ZAZ *pos = *prvy;
	c=getchar();
	fgets(n1,50,stdin);
	strcpy(novy->kat,n1);
	strtok(novy->kat,"\n");
	fgets(n1,50,stdin);
	strcpy(novy->mie,n1);
	strtok(novy->mie,"\n");
	fgets(n1,100,stdin);
	strcpy(novy->uli,n1);
	strtok(novy->uli,"\n");
	scanf("%d", &n2);
	c=getchar();
	novy->roz=n2;
	scanf("%d", &n2);
	c=getchar();
	novy->cen=n2;
	fgets(n1,200,stdin);
	strcpy(novy->pop,n1);
	strtok(novy->pop,"\n");
	if (*i==0 || k<1){
		if (*i==0 && k>0){
			*prvy = novy;
			(*prvy)->dalsi = NULL;
			*i=1;
		}
		return;
	}
	else{
		++*i;
		if (k==1){
		    strcpy(n1,novy->kat); 
		    strcpy(novy->kat,pos->kat);
		    strcpy(pos->kat,n1);   
		    novy->dalsi=pos->dalsi;
		    pos->dalsi=novy;
		    
		    strcpy(n1,novy->mie); 
		    strcpy(novy->mie,pos->mie);
		    strcpy(pos->mie,n1);   
		    novy->dalsi=pos->dalsi;
		    pos->dalsi=novy;
		    
		    strcpy(n1,novy->uli); 
		    strcpy(novy->uli,pos->uli);
		    strcpy(pos->uli,n1);   
		    novy->dalsi=pos->dalsi;
		    pos->dalsi=novy;
		    
		    a=novy->roz; 
			novy->roz=pos->roz;
			pos->roz=a;
			novy->dalsi=pos->dalsi;
			pos->dalsi=novy;
			
			a=novy->cen; 
			novy->cen=pos->cen;
			pos->cen=a;
			novy->dalsi=pos->dalsi;
			pos->dalsi=novy;
		    
		    strcpy(n1,novy->pop); 
		    strcpy(novy->pop,pos->pop);
		    strcpy(pos->pop,n1);   
		    novy->dalsi=pos->dalsi;
		    pos->dalsi=novy;
		    a=1; 
		}
		else{
			ZAZ *pos = *prvy;
			if (k>(*i)-1){
				k=(*i)-1;
			}
			n2=1;
			if (a==0){
        		while(pos->dalsi!=NULL){
					if (n2==k-1){
						novy->dalsi=pos->dalsi;
						pos->dalsi=novy;
						a=1;
						break;
						}
        			pos=pos->dalsi;
					++n2;
				}
			}
			if (a==0){
				pos->dalsi=novy;
			}
		}
	}
}

void z(int *i, ZAZ **prvy){
	char a[53],b[53], nic;
	nic=getchar();
	fgets(a,100,stdin);
	strtok(a,"\n");
	strcpy(b,a);
	ZAZ *pos = *prvy;
	ZAZ *nova = *prvy;
	strlwr(a);
	if (*i==0){
		return;
	}
	else{
		int k,kk,count=0,vym[*i];
		for (k=0;k<*i;k++){
			vym[k]=0;
		}
		for (k=0;k<*i;k++){
			strcpy(b,pos->mie);
			if (strstr(strlwr(b), a)!=NULL){
				count++;
				vym[k]=count;
			}
			pos=pos->dalsi;
		}
		pos = *prvy;
		for (k=0;k<*i;k++){
			if (vym[k+1]!=0){
				nova=pos->dalsi;
				pos->dalsi=nova->dalsi;
				nova=NULL;
				free(nova);
				--*i;
			}
				else{
				pos=pos->dalsi;
			}
		}	
		pos = *prvy;
		if (vym[0]!=0){
			*prvy= pos->dalsi;
			pos=pos->dalsi;
			*prvy=NULL;
			free(*prvy);
			*prvy=pos;
			--*i;
		}
		printf("Vymazalo sa %d zaznamov\n",count);
	}
}

void h(int i, ZAZ *prvy){
	int a=1,c,count;
	scanf("%d", &c);
	if (i==0){
		return;
	}
	else{
		ZAZ *pos = prvy;
		for (count=0; count<i; count++){
			if (pos->cen<=c){
				printf("%d.\n",a);
				printf("kategoria ponuky:%s\n", pos->kat);
				printf("miesto ponuky:%s\n", pos->mie);
				printf("ulica:%s\n", pos->uli);
				printf("rozloha v m2:%d\n", pos->roz);
				printf("cena:%d\n", pos->cen);
				printf("popis:%s\n", pos->pop);
				a++;
			}
			pos = pos->dalsi;
		}
		if (a==1){
			printf("V ponuke su len reality s vyssou cenou\n");
		}
	}
}

void a(int i, ZAZ *prvy){
	char nic,s1[203],s2[203],p[53];
	int d,n2,count=0;
	nic = getchar();
	fgets(p,50,stdin);
	strtok(p,"\n");
	strlwr(p);
	ZAZ *novy=(ZAZ *)malloc(sizeof(ZAZ));
	ZAZ *pos = prvy;
	
	fgets(s1,50,stdin);
	strcpy(novy->kat,s1);
	strtok(novy->kat,"\n");
	fgets(s1,50,stdin);
	strcpy(novy->mie,s1);
	strtok(novy->mie,"\n");
	fgets(s1,100,stdin);
	strcpy(novy->uli,s1);
	strtok(novy->uli,"\n");
	scanf("%d", &n2);
	nic=getchar();
	novy->roz=n2;
	scanf("%d", &n2);
	nic=getchar();
	novy->cen=n2;
	fgets(s1,200,stdin);
	strcpy(novy->pop,s1);
	strtok(novy->pop,"\n");
	if(i==0){
		return;
	}
	else{
		pos=prvy;
		for(d=0;d<i;d++){
			strcpy(s1,pos->mie);
			strlwr(s1);
			if (strstr(s1,p)!=NULL){
				strcpy(pos->kat, novy->kat);
				strcpy(pos->mie, novy->mie);
				strcpy(pos->uli, novy->uli);
				pos->roz = novy->roz;
				pos->cen = novy->cen;
				strcpy(pos->pop, novy->pop);
				count++;
			}
			pos=pos->dalsi;
		}
		printf("Aktualizovalo sa %d zaznamov\n", count);
		return;
	}
}

int main(){
	FILE *f;
	ZAZ *prvy = (ZAZ *)malloc(sizeof(ZAZ));
	ZAZ *pos = prvy;
	char vstup;
	int i=0,kidos=0;
	while(scanf("%c", &vstup)==1){
		switch(vstup){
			case 'n':
				n(&f,&i,&prvy);
				break;
			case 'v':
				v(i,prvy);
				break;
			case 'p':
				p(&i,&prvy);
				break;
			case 'z':
				z(&i,&prvy);
				break;
			case 'h':
				h(i,prvy);
				break;
			case 'a':
				a(i,prvy);
				break;
			case 'k':
				for (kidos=0;kidos<i;kidos++){
					pos=NULL;
					free(pos);
				}
				return 0;
		}
	}
	return 0;
}
