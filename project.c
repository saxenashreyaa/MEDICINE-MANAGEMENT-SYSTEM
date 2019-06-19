#include<stdio.h>
#include<conio.h>
#include<malloc.h>
#include<string.h>
#include<stdlib.h>
struct medicine
{
char med[100];
char dom[100];
char doe[100];
float price;
int qty;
struct medicine *next;
};
struct medicine *head=NULL;
struct medicine *add(struct medicine *);
struct medicine *search(struct medicine *);
struct medicine *modify(struct medicine *);
struct medicine *purchase(struct medicine *);
void*display(struct medicine *);
struct medicine *del(struct medicine *);

struct medicine *add(struct medicine *head)
{
struct medicine *newnode,*ptr;
char name[100];
char date1[100],date2[100];
float rate;
int quantity;
printf("Enter the medicine name-\n");
scanf("%s",name);
printf("Enter Date of Manufacture-\n");
scanf("%s",date1);
printf("Enter Date of Expiry-\n");
scanf("%s",date2);
printf("Enter price-\n");
scanf("%f",&rate);
printf("Enter its quantity-\n");
scanf("%d",&quantity);
/*newnode=(struct medicine *)malloc(sizeof(struct medicine));
strcpy(newnode->med,name);
strcpy(newnode->dom,date1);
strcpy(newnode->doe,date2);
newnode->price=rate;
newnode->qty=quantity;*/
if(head==NULL)
{
newnode=(struct medicine *)malloc(sizeof(struct medicine));
strcpy(newnode->med,name);
strcpy(newnode->dom,date1);
strcpy(newnode->doe,date2);
newnode->price=rate;
newnode->qty=quantity;
newnode->next=NULL;
head=newnode;
}
else
{
newnode=(struct medicine *)malloc(sizeof(struct medicine));
strcpy(newnode->med,name);
strcpy(newnode->dom,date1);
strcpy(newnode->doe,date2);
newnode->price=rate;
newnode->qty=quantity;
newnode->next=NULL;
ptr=head;
while(ptr->next!=NULL)
ptr=ptr->next;
ptr->next=newnode;
}
return head;
}
struct medicine *search(struct medicine *head)
{
struct medicine *ptr;
char name1[100];
ptr=head;
printf("Enter the name of the medicine\n");
scanf(" %s",&name1);
if(head== NULL){
    printf("not available\n");
}
else{
    while(ptr!=NULL && strcmp(ptr->med,name1))
    {
        ptr=ptr->next;
    }
    if(ptr!=NULL)
    {
    printf("\nMedicine name =%s",ptr->med);
    printf("\nDate of manufacture=%s",ptr->dom);
    printf("\nDate of expiry=%s",ptr->doe);
    printf("\nPrice of the medicine=%f",ptr->price);
    printf("\nQuantity available=%d\n",ptr->qty);
    }
    else
    {
        printf("Not available\n");
    }
}

return head;
}

struct medicine *modify(struct medicine *head)
{
struct medicine *ptr;
char name2[100],newdom[100],newdoe[100];
float newprice;
int newqty,val;
ptr=head;
printf("\nEnter the medicine name you want to modify details");
scanf("%s",name2);
if(head==NULL)
    printf("Not available\n");
else
{
while(ptr->next!=NULL && ptr->med!=name2)
{
    ptr=ptr->next;
}
if(ptr!=NULL)
{
printf("1.To edit date of manufacture\n2.To edit date of expiry\n3.To edit price\n4.To edit to quantity\n");
scanf("%d",&val);

switch(val)
{
case 1: printf("Enter new  manufacture date\n");
		scanf("%s",newdom);
		strcpy(ptr->dom,newdom);
		break;
case 2: printf("Enter new expiry date\n");
		scanf("%s",newdoe);
		strcpy(ptr->doe,newdoe);
		break;
case 3: printf("Enter new price\n");
		scanf("%f",&newprice);
		ptr->price=newprice;
		break;
case 4: printf("Enter new quantity\n");
		scanf("%d",&newqty);
		ptr->qty=newqty;
		break;
default:printf("Invalid Choice\n");
}
}
else
{
    printf("not available\n");
}}
return head;
}

struct medicine *purchase(struct medicine *head)
{
struct medicine *ptr;
char name3[100];
int num;
float pay;
ptr=head;
printf("Enter the name of medicine you want to buy\n");
scanf("%s",name3);
printf("Enter quatity\n");
scanf("%d",&num);
if(head==NULL)
printf("not avaialble\n");
else{

while(ptr->next!=NULL && ptr->med!=name3)
{
ptr=ptr->next;
}
if(ptr->qty < num)
{
printf("\nMedicine is out of stock or Please Enter quantity below Available Quantity");
}
else
{ pay = ptr->price * num;
  printf("Total Price to be paid=%f\n",pay);
  ptr->qty = ptr->qty - num;
  }
 }// return (ptr->qty);
  return head;
 }

void *display(struct medicine *ptr)
{
if(ptr==NULL)
    printf("not available\n");
else
{
while(ptr!=NULL)
{
printf("Name of the Medicine: %s\nRate: %f\nDate of expiring: %s\nDate of manufacturing: %s\n",ptr->med,ptr->price,ptr->doe,ptr->dom);
ptr=ptr->next;
}}
}
struct medicine *del(struct medicine *head)
{
struct medicine *ptr,*preptr;
char val[100];
printf("Enter the name of the medicine you want to delete\n");
scanf(" %s",&val);
ptr=head;
/*if(head==NULL)
printf("not available");
else{
    while(ptr->next!=NULL && ptr->med!=val)
       {
    preptr=ptr;
    ptr=ptr->next;
       }
       if(ptr==NULL)
        printf("medicine not found");
       else
       {
           preptr->next=ptr->next;
           return head;
       }

}
}*/
if(head==NULL)
    printf("not available\n");
else
    {
while(ptr!=NULL && strcmp(ptr->med,val))
{
preptr=ptr;
ptr=ptr->next;
}
if(ptr==NULL)
{
printf("Not Available\n");
}
else if(ptr==head)
    head=ptr->next;
else
    preptr->next=ptr->next;
    }
free(ptr);
return head;
}


int main()
{
int choice;
char name1[100];
printf("-----WELCOME-----\n");
do
{
printf("-----MAIN MENU-----\n");
printf("Select an option:\n1.ADD A MEDICINE\n2.MODIFY A MEDICINE\n3.DELETE A MEDICINE\n4.SEARCH A MEDICINE\n5.BUY\n6.DISPLAY\n7.EXIT\n");
scanf("%d",&choice);
switch(choice)
{
case 1:
head=add(head);
printf("Medicine added\n");
break;
case 2: head=modify(head);
printf("Medicine modified\n");
break;
case 3: head=del(head);
printf("Medicine deleted\n");
break;
case 4:
 head=search(head);
break;
case 5: head=purchase(head);
break;
case 6: display(head);
break;

}
}while(choice!=7);
return 0;
}


