#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char temp[50];
typedef struct node
{
        char data[50];
        struct node *left,*right;   //left and right pointer
        int ht; //this is used to store height of each node
}node;

//this function is used to calculate height of each node

int height(node *T)
{
        int lh,rh;
        if(T==NULL)
                return(0);

        if(T->left==NULL)
                lh=0;
        else
                lh=1+T->left->ht;

        if(T->right==NULL)
                rh=0;
        else
                rh=1+T->right->ht;

        if(lh>rh)
                return(lh);

        return(rh);
}
node * rotateright(node *x)
{
        node *y;
        y=x->left;
        x->left=y->right;
        y->right=x;
        x->ht=height(x);
        y->ht=height(y);
        return(y);
}

//this function is used to rotate left

node * rotateleft(node *x)
{
        node *y;
        y=x->right;
        x->right=y->left;
        y->left=x;
        x->ht=height(x);
        y->ht=height(y);

        return(y);
}

//this is used to rotate right right
node * RR(node *T)
{
        T=rotateleft(T);
    printf("RR rotation done\n");
        return(T);
}
node * LL(node *T)
{
        T=rotateright(T);
    printf("LL rotation done\n");
        return(T);
}

//this is used to rotate left right
node * LR(node *T)
{
        T->left=rotateleft(T->left);
    printf("RL rotation done\n");
        T=rotateright(T);
    printf("RR rotation done\n");

        return(T);
}

//this is used to rotate right left
node * RL(node *T)
{
        T->right=rotateright(T->right);
    printf("RR rotation done\n");
        T=rotateleft(T);
    printf("RL rotation done\n");
        return(T);
}
int BF(node *T)
{
        int lh,rh;
        if(T==NULL)
                return(0);

        if(T->left==NULL)
                lh=0;
        else
                lh=1+T->left->ht;

        if(T->right==NULL)
                rh=0;
         else
                rh=1+T->right->ht;

        return(lh-rh);
}

void inorder(node *T)
{
        if(T!=NULL)
        {
                inorder(T->left);
                printf("%s(Bf=%d)",T->data,BF(T));
                inorder(T->right);
        }
}

node * insert(node *T,char x[50])
{
        if(T==NULL)
        {
                T=(node*)malloc(sizeof(node));
                strcpy(T->data,x);
                T->left=NULL;
                T->right=NULL;
        }
        else
            {

                if(strcmp(x,T->data)>0)               // insert in right subtree
                {
                        T->right=insert(T->right,x);
                        int bf=BF(T);
                        if(bf==-2)
                                if(strcmp(x,T->right->data)>0)
                                   T=RR(T);  //RR means right right imbalance,,,so we are performing right right rotation
                                else
                                   T=RL(T);  //RL means right left imbalance,,,so we are performing right left rotation
                }
                else
                {
                  if(strcmp(x,T->data)<0)   //insert in left subtree
                  {
                        T->left=insert(T->left,x);
                        if(BF(T)==2)
                        if(strcmp(x,T->left->data)<0)
                        T=LL(T);    //RR means left left imbalance , so we are performing left left rotation
                        else
                        T=LR(T);    //RL means left right imbalance , so we are performing left right rotation
                  }
                }

            }
        T->ht = height(T);
        return(T);
}

int main()
{
        node *root=NULL;
        int x,n,i,op;
        char k[50];
	struct node *copy;
        for(int a=1;a>0;a++)
	{
                printf("\n1)Create:");
                printf("\n2)Print:");
                printf("\n3)Quit:");
                printf("\n\nEnter Your Choice:");
                scanf("%d",&op);
                if(op==3)
		break;
		else
		{
		switch(op)
                {
                        case 1: printf("\nEnter no. of elements:");
                                        scanf("%d",&n);
                                        printf("\nEnter tree data:");
                                        root=NULL;
                                        for(i=0;i<n;i++)
                                        {
                                                scanf("%s",&k);
                                                root=insert(root,k);
						copy=root;
                                        }
                                        break;

                        case 2: printf("\n\nInorder sequence:\n");
                                        inorder(root);
                                        printf("\n");
                                     break;
		}}}

	       int y;
               printf("to kaise h aap log insert new press 1=");
           scanf("%d",&y);
           if(y==1)
             {
                 scanf("%s",&k);
                root=insert(root,k);
                inorder(root);
             }
               else
                printf("ok bye");

       return 0;
}
