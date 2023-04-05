//@Author: Dr.Mydhili K Nair, Professor & Head-B.Tech, SoCSE, RVU
//Inserting and Deleting elements in queue using Arrays.
// Possible VIVA Questions are displayed in comments with their answers.

#include <stdio.h>
#define SIZE 5 //for Queue Size
int myQ[SIZE];
int front = -1; //for deletion - deQueing
int rear = -1; //for insertion  - enQueing
int element;
void enQueue()
{
    
    printf("\n Enter the element to be added into the Queue \t");
    scanf("%d", &element);
    
    if(rear == SIZE-1) printf("\n Sorry cannot enqueue - Queue is FULL!!");
    //Question: What happens if we dont give this statement : "if(front == -1)"
    /* Answer: The elememts will never be inserted into the queue. The display function will always say "Q Empty"
     */
    else
    {
    if(front == -1) front = 0; //To take care of the condition when the Queue is initially empty.
    
    //Question: What heppens if we put the statements below in "else" part?
    /* Answer: The elememts will never be inserted into the queue. Because initially the Queue is empty and
     "myQ[++rear] = element" will never be executed.
     */
    myQ[++rear] = element;
    printf("\n Enqueued by adding element %d in %d position which is value of rear", element,rear);
    printf("\n Queue has %d elements", rear+1);
    }//end else
    
    
}//end enQ

void deQueue()
{
    //Question: What happens if we remove the condition "front > rear"?
    /* Answer: When the value of front is greater than rear and when "front != -1" there is nothing to delete in Queue.But, the control goes to the "else" part and keeps assigning "junk values" beyond Queue size to "myQ". This is wrong execution.
     Situations where "front > rear" are:
     a) Insert one element and delete it immediately front = 1, rear = 0
     b) Keep inserting elements into the queue and then keep deleting. front == rear, for the last element in the Queue. Beyond that rear remains at end of queue value and front keeps increasing. E.g. 3 elements front = 3, rear = 2
     TIP: Display the values of "front" and "rear" and see for yourselves.
     */
    if(front == -1 || front > rear) printf("\n Sorry cannot dequeue - Queue Empty!!");
    else
    {
    element = myQ[front++];
    printf("\nElement %d in %d position(front)of queue deleted", element,front-1);
    printf("\n Queue start shifted to position %d which is value of front", front);
        /* Viva Q: Why is below "if" statement required?
         Answer: After the Queue is made empty "front" will be equal to "SIZE" that is "rear+1".
         Note: front is post-incremented.
         Also, in previous enqueing and making the Queue full "rear" is "SIZE-1"
         Therefore, if we dont reset "front" and "rear", after first deQueing when Q is empty, we cannot enQueue
         again, as it will mistakenly display "Q is full".
         Try commneting below "if" statement and execute to see for yourselves! */
        if(front == rear+1)
        {
        //resetting front and rear
        front = -1;
        rear = -1;
        }
    }
    
    
}//end deQ

void display()
{
    //Question: What happens if we remove the condition "front > rear"?
    /* Answer: When the value of front is greater than rear and when "front != -1" there is nothing to display in Queue.But, the control goes to the "else" part and displays nothing, which is wrong execution.
     Situations where "front > rear" are:
     a) Insert one element and delete it immediately front = 1, rear = 0
     b) Keep inserting elements into the queue and then keep deleting. front == rear, for the last element in the Queue. Beyond that rear remains at end of queue value and front keeps increasing. E.g. 3 elements front = 3, rear = 2
     TIP: Display the values of "front" and "rear" and see for yourselves.
     */
    if(front == -1 || front > rear)
    printf("\n Queue is Empty!!");
    else
    {
        printf("\n Displaying Queue Elements:");
        for(int i = front; i<=rear; i++)
        printf("\n %d ", myQ[i]);
        
        // Question: What is the output of the below for loop? Justify it.
        /*for(int i = 0; i<SIZE; i++)
        printf(" \n %d ", myQ[i]);*/
        /* Answer: The for loop displays all the contents of the "MyQ" array. Remember that the array contsnts
        remain intact. It is only the "notion" of a queue - with changing front & rear pointers!!! */
    }
    
    
    
}//end diaplay

int main()
{
    int choice;
    
    while(1)
    {
        printf("\n Press 1. To Insert into Queue");
        printf("\n Press 2. To Delete from Queue");
        printf("\n Press 3. To Display Queue\t");
        printf("\n Press 4. To Exit Menu\t");
        scanf("%d", &choice);
        
        if(choice == 1)enQueue();
        else if(choice == 2)deQueue();
        else if(choice == 3) display();
        else if(choice == 4) exit(0);
        else printf("\nWrong entry : Press either 1, 2 or 3");
        
    }//end while
    
    
}//end main
