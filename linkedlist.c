# include "Linkedlist.h"



int add_to_list(linked_list *ll, char *s){
    int index=0;
    while(ll->next!=NULL){
        ++index;
        ll=ll->next;
    }
    linked_list *current=ll;
    linked_list *newNode=(linked_list *)malloc(sizeof(linked_list));
    newNode->data=s;
    newNode->index=++index;
    newNode->next=NULL;
    newNode->prev=NULL;
   ll->next=newNode;
    ll->next->prev=ll;
    ll=current;
    return index;
}


int display_item(linked_list *ll){
    if(ll->data!=NULL)
        return 0;
    else
        return -1;
}
int display_list(linked_list *node){
    int count=0;
   linked_list *last;
    printf("\forward direction \n");
    while (node != NULL)
    {
        ++count;
        printf(" %s", node->data);
        last = node;
        node = node->next;
    }
    
    printf(" reverse direction \n");
    while (last != NULL)
    {
      
        printf(" %s", last->data);
        last = last->prev;
        if(last->data==NULL)
            break;
    }
    return count;
}
linked_list *search_from_list(linked_list *ll, char *s){
    linked_list *current=ll;
    int flag=0;
    while(current->data!=NULL || current->next !=NULL){
        if(current->data==NULL){
            current=current->next;
            continue;
        }
        if(strcmp(current->data, s)==0){
            flag=1;
            break;
        }
        else{
            if(current->next==NULL){
                flag=0;
            break;
            }
            else{
                current=current->next;
            }
            
        }
        
    }
    if(flag==1)
        return current;
    else
        return NULL;
}
int delete_from_list(linked_list *ll,int index){
    int i;
    //if (ll == NULL)
     //   return -1;
    
 
   linked_list * temp = ll;

    if (index == 0)
    {
        ll = temp->next;   
        free(temp);             
        return -1;
    }
    
   
    for (int i=1; temp!=NULL && i<index; i++)
        temp = temp->next;
    
    
    if (temp == NULL )
        return 1;
    
  
    //linked_list *next = temp->next->next;
    
    
    //free(temp->next);  // Free memory
   // printf("%d\n",temp->index );
    //temp->next = next;  
    //if(temp->next==NULL)
      //  temp->prev->next=NULL;

    //else{
    temp->prev->next=temp->next;
    temp->next->prev=temp->prev;
//}

    
    free(temp);
    return index;
}


