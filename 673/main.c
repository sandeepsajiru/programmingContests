#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef int ElementType;
typedef struct LLNode LLNode;

// Define Structure LLNode
struct LLNode
{
    ElementType data;
    LLNode *next;
};

typedef struct stack Stack;
struct stack
{
    LLNode *top;
    int count;
};

LLNode* createLLNode(ElementType data)
{
    LLNode *t  = malloc(sizeof(LLNode));
    t->next = NULL;
    t->data = data;
    return t;
}

LLNode* insertInBegin(LLNode *head, ElementType data)
{
    LLNode *t = createLLNode(data);
    //if(head==NULL)
    //  return t;
    t->next = head;
    return t;
}

LLNode* deleteFirstNode(LLNode *head)
{
    if(head==NULL)
        return NULL;
    LLNode *t = head->next;
    free(head);
    return t;
}

LLNode* destroyAllNodes(LLNode *head)
{
    LLNode *n;
    while(head!=NULL)
    {
        n = head->next;
        free(head);
        head=n;
    }
    return NULL;
}


Stack *createStack()
{
    Stack *s = malloc(sizeof(Stack));
    s->top = NULL;
    s->count = 0;
    return s;
}

void push(Stack *s, ElementType data)
{
    assert(s!=NULL);
    s->top = insertInBegin(s->top, data);
    s->count++;
}

ElementType pop(Stack *s)
{
    assert(s!=NULL);
    assert(s->top!=NULL);
    ElementType data = s->top->data;
    s->top = deleteFirstNode(s->top);
    s->count--;
    return data;
}

ElementType peek(Stack *s)
{
    assert(s!=NULL);
    assert(s->top!=NULL);
    return s->top->data;
}

bool isStackEmpty(Stack *s)
{
    return (s==NULL || s->top==NULL);
}

Stack * destroyStack(Stack *s)
{
    assert(s!=NULL);
    s->top = destroyAllNodes(s->top);
    free(s);
    return NULL;
}

int getStackElementCount(Stack *s)
{
    assert(s!=NULL);
    return s->count;
}


int main()
{
    int t;
    scanf("%d\n", &t);
    char line[200];

    while(t--)
    {
        gets(line);
        Stack *s = createStack();
        int i;
        while(line[i]!='\0'))
        {


            i++;
        }

    }

    return 0;
}
