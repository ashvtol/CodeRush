#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define sn struct node
#define sc(x) scanf("%d",&x)
#define p(x) printf(x)
struct node
{
    int data;
    sn *link;
};

sn *head = NULL;

void print(sn *r)
{
    while(r!=NULL)
    {
        printf("%d ",r->data);
        r = r->link;
    }
    printf("\n");
}

void create()
{
    int n;
    p("Enter number of node\t");
    sc(n);
    sn *r ;
    while(n--)
    {
        sn *temp = (sn*)malloc(sizeof(sn));
        if(head==NULL)
        {
            p("Enter the data \t");
            sc(temp->data);
            temp->link=NULL;
            head = temp;
            r = head;
        }
        else
        {
            p("Enter the data \t");
            sc(temp->data);
            r->link = temp;
            r = temp;
            temp->link = NULL;
        }
    }
}

int getsize(sn *r)
{
    int ct = 0;
    while(r!=NULL)
    {
        r = r->link;
        ct++;
    }

    return ct;
}

void insert()
{
    p("Enter position to insert the node\n");
    int n;  sc(n); n--;
    if(n==0)
    {
        p("Enter the data to be inserterd\t");
        sn *temp = (sn*)malloc(sizeof(sn));
        sc(temp->data);
        temp->link = head;
        head = temp;
    }
    else
    {
        int sz = getsize(head);
        if(n+1 > sz)
        {
            p("Enter the data to be inserterd\t");
            sn *temp = (sn*)malloc(sizeof(sn));
            sc(temp->data);
            sn *r ;
            r = head;
            while(r->link!=NULL)
            {
                r = r->link;
            }
            r->link = temp;
            temp->link = NULL;

        }

         if(n+1 < sz)
        {
            p("Enter the data to be inserterd\t");
            sn *temp = (sn*)malloc(sizeof(sn));
            sc(temp->data);
            sn *r;
            r = head;
            while(n!=1)
            {
                r = r->link;
                n--;
            }
            temp->link = r->link;
            r->link = temp;
        }


    }

}

void del()
{
    p("Enter a value to be deleted\n");
    int nval; sc(nval);

    //if head contains the nval


    sn *r;
    r = head;
    if(r->data==nval && r!=NULL)
    {
        head = r->link;
        free(r);
        return;
    }

    r = head;
    sn *temp;
    while(r->data!=nval && r->link!=NULL)
    {
        temp = r;
        r = r->link;
    }
    if(r->link==NULL) {p("Key not found!\n"); return;}

    temp->link = r->link;
    free(r);


}

void search()
{
    p("Enter the value to be searched\n");
    int val; sc(val);
    sn *r = head;
   while(r!=NULL)
   {
       if(r->data!=val)
            r = r->link;
       else
       {
           p("Found\n");
           return;
       }
   }
   p("Not found\n");
   return;

}

//recursive search
int rsearch(sn* r,int val)
{

    if(r->data==val)
        return 1;

    if(r==NULL)
        return 0;

    return rsearch(r->link,val);
}

int main()
{
    create();
    insert();
    print(head);
    del();
    print(head);
    search();
    p("Enter the data to be searched\n");
    int val = sc(val);
    if(rsearch(head,val))
        p("Found\n");
    else
        p("Not Found\n");
   // print(head);
}
