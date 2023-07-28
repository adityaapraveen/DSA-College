#include<stdio.h>
#include<stdlib.h>

int ele, ch;

typedef struct node
{    
    struct node *prev;
    int data;
    struct node *next;
}node;

typedef struct list
{
    node *head;
    node *tail;
    int size;
}list;

list* createList()
{
    list *lst = (list*)malloc(sizeof(list));
    (*lst).head = NULL; //can also be written as lst->head
    lst->tail = NULL; //can also be written as (*lst).tail
    lst->size = 0; //can also be written as (*lst).size
    printf("\nLinked list created\n");
    return lst;
}

void traverseFront(list* lst)
{
    if(lst->size == 0)
    {
        printf("\nLinked list is empty.. Insert some items to continue!!\n");
    }
    else
    {
        node *curr;
        curr = lst->head;
        printf("\nLinked list from the front: \n");
        while(curr != NULL)
        {
            printf("\n%d", curr->data);
            curr = curr->next;
        }
        printf("\n");
    }
}

void traverseBack(list *lst)
{
    if(lst->size == 0)
    {
        printf("\nLinked list is empty.. Insert some items to continue!!\n");
    }
    else
    {
        node *curr;
        curr = lst->tail;
        printf("\nLinked list elements from the back are: ");
        while(curr != NULL)
        {
            printf("\n%d", curr->data);
            curr = curr->prev;
        }
        printf("\n");  
    }
}

void addFront(list *lst, int ele)
{
    node *temp = (node *)malloc(sizeof(node));
    temp->data = ele;
    temp->prev = NULL;
    temp->next = lst->head;

    if(lst->size == 0)
    {
        lst->tail = temp;
    }
    else
    {
        lst->head->prev = temp;
    }

    lst->head = temp;
    lst->size++;
    printf("%d has been added to the front", lst->head->data);
}

void addBack(list *lst, int ele)
{
    node *temp = (node *)malloc(sizeof(node));
    temp->data = ele;
    temp->next = NULL;
    temp->prev = lst->tail;

    if(lst->size == 0)
    {
        lst->head = temp;
        lst->tail = temp;
    }
    else
    {
        lst->tail->next = temp;
    }
    
    lst->tail = temp;
    lst->size++;
    printf("%d has been added to the back", lst->tail->data);
}

int deleteFront(list *lst)
{
    if(lst->size == 0)
    {
        printf("\nLinked list is empty.. Insert some items to continue!!\n");
        return -1;
    }
    else
    {
        int delDataFront;
        node *delFront;
        delDataFront = lst->head->data;
        delFront = lst->head;

        if(lst->size == 1)
        {
            lst->head = NULL;
            lst->tail = NULL;
        }
        else
        {
            lst->head = lst->head->next;
            lst->head->prev = NULL;
        }

        lst->size--;
        printf("\n%d has been deleted from the front\n", delDataFront);
        free(delFront);
        return delDataFront;
    }
}

int deleteBack(list *lst)
{
    if(lst->size == 0)
    {
        printf("\nLinked list is empty.. Insert some items to continue!!\n");
        return -1;
    }
    else
    {
        int delDataBack;
        node *delBack;
        delBack = lst->tail;
        delDataBack = delBack->data;

        if(lst->size == 1)
        {
            lst->head = NULL;
            lst->tail = NULL;
        }
        else
        {
            lst->tail = lst->tail->prev;
            lst->tail->next = NULL;
        }

        lst->size--;
        printf("\n%d has been deleted from the back\n", delDataBack);
        free(delBack);
        return delDataBack;
    }
}

int main()
{
    list *lst = createList();
    for(;;)
    {
        int ele, key, ch;
        printf("\nMENU OF DOUBLE LINKED LIST\n");
        printf("\n1.Display list from front");
        printf("\n2.Display list from back");
        printf("\n3.Add to front of list");
        printf("\n4.Add to back of list");
        printf("\n5.Delete from front of list");
        printf("\n6.Delete from back of list");
        printf("\n7.Exit");
        printf("\n");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1:
                traverseFront(lst);
                break;
            case 2:
                traverseBack(lst);
                break;
            case 3:
                printf("\nEnter element to be inserted to the front: ");
                scanf("%d", &ele);
                addFront(lst, ele);
                break;
            case 4:
                printf("\nEnter element to be inserted to the back: ");
                scanf("%d", &ele);
                addBack(lst, ele);
                break;
            case 5:
                int delDataFront = deleteFront(lst);
                break;
            case 6:
                int delDataBack = deleteBack(lst);
                break; 
            case 7:
                exit(0); 
        }  
    }
    return 0;
}